// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/Actor/MyWeapon.h"
#include "Components/BoxComponent.h"
#include "FirstProject/Player/MyCharacter.h"

// Sets default values
AMyWeapon::AMyWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// �ʿ��� ������Ʈ�� ����ȭ �ؼ� ������ ��´�.
	Weapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WEAPON"));
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TRIGGER"));


	// �ʿ��� �޽��� �ҷ��� Weapon�� �����Ų��.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SW(TEXT("/Script/Engine.StaticMesh'/Engine/EditorResources/FieldNodes/_Resources/SM_FieldArrow.SM_FieldArrow'"));
	if (SW.Succeeded())
	{
		Weapon->SetStaticMesh(SW.Object);
	}

	// Weapon�� �� Ŭ������ RootComponent�� �ڽ�����
	// Trigger�� Weapon�� �ڽ����� �������ش�.
	Weapon->SetupAttachment(RootComponent);
	Trigger->SetupAttachment(Weapon);

	// Weapon�� Trigger�� �浹ü �̸��� ������ ��
	// Trigger�� �ڽ�ũ�⸦ �����ش�.
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
	// Ʈ������ �浹���� �� ��������Ʈ�� �������ش�.
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AMyWeapon::OnCharacterOverlap);
}

void AMyWeapon::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Overlapped"));

	// OtherActor�� AMyCharater�� ������ ĳ���Ͱ� �ֿ������ �Ǵ�
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(OtherActor);
	if (MyCharacter)
	{
		FName WeaponSocket(TEXT("hand_l_socket"));

		AttachToComponent(MyCharacter->GetMesh(),
			FAttachmentTransformRules::SnapToTargetNotIncludingScale,
			WeaponSocket);
	}
}



