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

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	// MyCharacterŬ������ �� ���캸�� CapsuleComponent�� ��Ʈ�� ���س����� ���� ���̴�.
	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 200.f;
	SpringArm->SetRelativeLocationAndRotation(
		FVector(0.f, 50.f, 70.f), FRotator(0.f, 0.f, 0.f));

	// �޽��� �츮�� ���� �������� �����ϱ� ���ؼ� ���
	GetMesh()->SetRelativeLocationAndRotation(
		FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonYin/Characters/Heroes/Yin/Meshes/Yin.Yin'"));

	if (SM.Succeeded())
	{
		// ĳ���� Ŭ�������� �̹� �޽��� ��������ִµ� 
		// Mesh�� private�� �Ǿ��־
		// GetMesh�� ���� ����
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	Stat = CreateDefaultSubobject<UMyStatComponent>(TEXT("STAT"));
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	FName WeaponSocket(TEXT("hand_l_socket"));

	auto DropWeapon = GetWorld()->SpawnActor<AMyWeapon>(FVector::ZeroVector, FRotator::ZeroRotator);

	if (DropWeapon)
	{
		//DropWeapon->AttachToComponent(GetMesh(),
		//	FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		//	WeaponSocket);
	}
}

void AMyCharacter::PostInitializeComponents()
{
	// BeginPlay���� ���� ���۵�
	Super::PostInitializeComponents();

	AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	if (AnimInstance)
	{
		// ��Ÿ�ְ� ������ AddDynamic�� �Ǿ��ִ� �Լ��� ������Ѷ�(��������Ʈ)
		AnimInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::OnAttackMontageEnded);
		AnimInstance->OnAttackHit.AddUObject(this, &AMyCharacter::AttackCheck);
	}
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
	// BindAxis = ���̽�ƽ
	// BindAction = ���̽�ƽ ��ư
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("TurnCamera"), this, &AMyCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyCharacter::LookUp);
}

void AMyCharacter::Attack()
{
	if (IsAttacking)
	{
		if (AnimInstance->Montage_IsPlaying(AnimInstance->AttackMontage))
		{
			AnimInstance->Montage_Stop(0.0f, AnimInstance->AttackMontage);
		}
	}
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

	// ä���� �̿��ؼ� Sweep�ϰڴ�.
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
	UE_LOG(LogTemp, Log, TEXT("MontageEnd %s"), (IsAttacking ? TEXT("true") : TEXT("false")));
}

float AMyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Stat->OnAttacked(DamageAmount);

	return DamageAmount;
}
