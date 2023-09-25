// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/Actor/MyStatComponent.h"
#include "FirstProject/Instacne/MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

	// InitializeComponent를 실행하려면 아래를 true로 바꿔줘야 한다.
	bWantsInitializeComponent = true;

	Level = 1;
}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMyStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetLevel(Level);
}

void UMyStatComponent::SetLevel(int32 NewLevel)
{
	// GetGameInstance 싱글톤처럼 불러올 수 있는 함수
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(Level);
		if (StatData)
		{
			Level = StatData->Level;
			Hp = StatData->MaxHp;
			Attack = StatData->Attack;
		}
	}
}

void UMyStatComponent::OnAttacked(float DamageAmount)
{
	Hp -= DamageAmount;
	if (Hp < 0)
		Hp = 0;

	UE_LOG(LogTemp, Warning, TEXT("OnAttacked %d"), Hp);
}



