// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/Player/MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include <FirstProject\Anim\MyAnimInstance.h>
#include "Debug/DebugDrawComponent.h"
#include "FirstProject/Actor/MyWeapon.h"
#include "FirstProject/Actor/MyStatComponent.h"
#include "Engine/DamageEvents.h"
#include "Components/WidgetComponent.h"
#include <FirstProject\UI\MyCharacterWidget.h>
#include "FirstProject\AI\MyAIController.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	// MyCharacter클래스를 잘 살펴보면 CapsuleComponent에 루트를 정해놓은게 있을 것이다.
	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 200.f;
	SpringArm->SetRelativeLocationAndRotation(
		FVector(0.f, 50.f, 70.f), FRotator(0.f, 0.f, 0.f));

	// 메쉬를 우리가 보는 방향으로 설정하기 위해서 사용
	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonYin/Characters/Heroes/Yin/Meshes/Yin.Yin'"));

	if (SM.Succeeded())
	{
		// 캐릭터 클래스에는 이미 메쉬가 만들어져있는데 
		// Mesh가 private로 되어있어서
		// GetMesh를 통해 수정
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	// 스탯의 인스턴스를 가져와 넣어준다.
	Stat = CreateDefaultSubobject<UMyStatComponent>(TEXT("STAT"));

	// HpBar 생성
	// 에러가 날 시 위에 #include "Components/WidgetComponent.h"를 추가해주자
	HpBar = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBAR"));
	HpBar->SetupAttachment(GetMesh());
	HpBar->SetRelativeLocation(FVector(0.f, 0.f, 200.f));

	// World와 Screen두개의 형태가 있다.
	HpBar->SetWidgetSpace(EWidgetSpace::Screen);

	// 유저 위젯을 가져온다.
	// 블루프린트 클래스를 가져오려면 항상 _C가 붙어야 한다.
	static ConstructorHelpers::FClassFinder<UUserWidget> UW(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/WBP_HpBar.WBP_HpBar_C'"));

	// 클래스를 제대로 불러왔다면
	if (UW.Succeeded())
	{
		// HpBar의 위젯클래스를 우리가 불러온 클래스로 설정 해준 후
		// 사이즈를 우리가 커스텀한 사이즈로 초기화 시켜준다.
		HpBar->SetWidgetClass(UW.Class);
		HpBar->SetDrawSize(FVector2D(200.f, 50.f));
	}

	// AIControllerClass를 우리가 만든 AMyAIController클래스로 기본으로 지정하겠다고 설정
	AIControllerClass = AMyAIController::StaticClass();
	// AutoPossesAI를 월드에 배치가 되거나 스폰이 되었을 때로 설정
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	FName WeaponSocket(TEXT("hand_l_socket"));

	//auto DropWeapon = GetWorld()->SpawnActor<AMyWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);

	//if (DropWeapon)
	//{
	//	//DropWeapon->AttachToComponent(GetMesh(),
	//	//	FAttachmentTransformRules::SnapToTargetNotIncludingScale,
	//	//	WeaponSocket);
	//}
}

void AMyCharacter::PostInitializeComponents()
{
	// BeginPlay보다 전에 시작됨
	Super::PostInitializeComponents();

	AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	if (AnimInstance)
	{
		// 몽타주가 끝나면 AddDynamic에 되어있는 함수를 실행시켜라(델리게이트)
		AnimInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::OnAttackMontageEnded);
		AnimInstance->OnAttackHit.AddUObject(this, &AMyCharacter::AttackCheck);
	}

	// 위젯 초기화
	HpBar->InitWidget();
	
	// TODO
	// 체력이 닳았을 때 델리게이트 바인딩을 해주는 역할을 추가해줘야 함
	// 왜 UMyCharacterWidget으로 캐스팅 하게 되냐면
	// 지금 현재 우리가 가지고 있는 HpBar는 UWidgetComponent이다.
	// 그렇기에 우리는 UMyCharacterWidget에 있는 UpdateHp와 BindHp를 이용할 것이기 때문에
	// UMyCharacterWidget 타입을 가져와야 한다.
	auto HpWidget = Cast<UMyCharacterWidget>(HpBar->GetUserWidgetObject());

	// 잘 불러왔다면 Bind를 초기화 한다.
	if (HpWidget)
		HpWidget->BindHp(Stat);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// BindAxis = 조이스틱
	// BindAction = 조이스틱 버튼
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("TurnCamera"), this, &AMyCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyCharacter::LookUp);
}

void AMyCharacter::Attack()
{
	if (IsAttacking == true) return;
	//if (IsAttacking)
	//{
	//	if (AnimInstance->Montage_IsPlaying(AnimInstance->AttackMontage))
	//	{
	//		AnimInstance->Montage_Stop(0.0f, AnimInstance->AttackMontage);
	//	}
	//}
	//auto AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	//if (AnimInstance)
	//{
	//	AnimInstance->PlayAttackMontage();
	//}
	AnimInstance->PlayAttackMontage();

	AnimInstance->JumpToSection(AttackIndex);

	AttackIndex = (AttackIndex + 1) % 3;
	
	IsAttacking = true;
	UE_LOG(LogTemp, Log, TEXT("AttackCheck %s"), (IsAttacking ? TEXT("true") : TEXT("false")));
}

void AMyCharacter::AttackCheck()
{
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);

	float AttackRange = 100.f;
	float AttackRadius = 50.f;

	// 채널을 이용해서 Sweep하겠다.
	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_EngineTraceChannel2,
		FCollisionShape::MakeSphere(AttackRadius),
		Params);

	FVector Vec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + Vec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat Rotation = FRotationMatrix::MakeFromZ(Vec).ToQuat();
	FColor DrawColor;
	if (bResult)
		DrawColor = FColor::Green;
	else
		DrawColor = FColor::Red;

	DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius,
		Rotation, DrawColor, false, 2.f);

	if (bResult && HitResult.GetActor())
	{
		UE_LOG(LogTemp, Log, TEXT("Hit Actor : %s"), *HitResult.GetActor()->GetName());

		FDamageEvent DamageEvent;
		HitResult.GetActor()->TakeDamage(Stat->GetAttack(), DamageEvent, GetController(), this);
	}
}

void AMyCharacter::MoveForward(float Value)
{
	//if (Value == 0.f) return;
	
	if (IsAttacking == true)
	{
		MoveForwardValue = 0.f;
		return;
	}
	//UE_LOG(LogTemp, Warning, TEXT("MoveForward %f"), Value);

	MoveForwardValue = Value;
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMyCharacter::MoveRight(float Value)
{
	/*if (Value == 0.f) return;*/
	//UE_LOG(LogTemp, Log, TEXT("IsAttacking %s"), IsAttacking);
	if (IsAttacking == true)
	{
		MoveRightValue = 0.f;
		return;
	}
	/*UE_LOG(LogTemp, Warning, TEXT("MoveRight %f"), Value);*/
	MoveRightValue = Value;
	AddMovementInput(GetActorRightVector(), Value);
}

void AMyCharacter::Turn(float Value)
{
	if (Value == 0.f) return;

	/*UE_LOG(LogTemp, Warning, TEXT("Turn %f"), Value);*/

	AddControllerYawInput(Value);
}

void AMyCharacter::LookUp(float Value)
{
	if (Value == 0.f) return;

	/*UE_LOG(LogTemp, Warning, TEXT("LookUp %f"), Value);*/

	AddControllerPitchInput(Value);
}

void AMyCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	if (IsAttacking == false) return;
	IsAttacking = false;
	OnAttackEnd.Broadcast();
	UE_LOG(LogTemp, Log, TEXT("MontageEnd %s"), (IsAttacking ? TEXT("true") : TEXT("false")));
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Stat->OnAttacked(DamageAmount);


	UE_LOG(LogTemp, Warning, TEXT("TEST Text"));

	return DamageAmount;
}
