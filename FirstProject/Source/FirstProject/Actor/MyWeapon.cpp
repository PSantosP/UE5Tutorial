// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/Actor/MyWeapon.h"
#include "Components/BoxComponent.h"
#include "FirstProject/Player/MyCharacter.h"

// Sets default values
AMyWeapon::AMyWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// 필요한 컴포넌트를 생성화 해서 변수에 담는다.
	Weapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WEAPON"));
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));


	// 필요한 메쉬를 불러와 Weapon에 적용시킨다.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SW(TEXT("/Script/Engine.StaticMesh'/Engine/EditorResources/FieldNodes/_Resources/SM_FieldArrow.SM_FieldArrow'"));
	if (SW.Succeeded())
	{
		Weapon->SetStaticMesh(SW.Object);
	}

	// Weapon은 이 클래스의 RootComponent의 자식으로
	// Trigger는 Weapon의 자식으로 설정해준다.
	Weapon->SetupAttachment(RootComponent);
	Trigger->SetupAttachment(Weapon);

	// Weapon과 Trigger의 충돌체 이름을 지어준 후
	// Trigger의 박스크기를 정해준다.
	Weapon->SetCollisionProfileName(TEXT("MyCollectible"));
	Trigger->SetCollisionProfileName(TEXT("MyCollectible"));
	Trigger->SetBoxExtent(FVector(30.f, 30.f, 30.f));
}

// Called when the game starts or when spawned
void AMyWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMyWeapon::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	// 트리거의 충돌했을 때 델리게이트를 설정해준다.
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AMyWeapon::OnCharacterOverlap);
}

void AMyWeapon::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Overlapped"));

	// OtherActor의 AMyCharater가 있으면 캐릭터가 주운것으로 판단
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
	if (MyCharacter)
	{
		FName WeaponSocket(TEXT("hand_l_socket"));

		AttachToComponent(MyCharacter->GetMesh(),
			FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			WeaponSocket);
	}
}



