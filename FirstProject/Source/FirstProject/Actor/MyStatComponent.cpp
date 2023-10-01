// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/Actor/MyStatComponent.h"
#include "FirstProject/Instacne/MyGameInstance.h"
#include "Kismet/GameplayStatics.h"			// 싱글톤을 사용 할 수 있는 헤더

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

	// 레벨을 설정해준다.
	SetLevel(Level);
}

void UMyStatComponent::SetLevel(int32 NewLevel)
{
	// GetGameInstance 싱글톤처럼 불러올 수 있는 함수
	// MyGameInstance를 캐스팅해온다.
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		// 레벨에 맞는 스탯 데이터를 가져온다.
		auto StatData = MyGameInstance->GetStatData(Level);
		if (StatData)
		{
			// 스탯 데이터가 있다면 정해준다.
			// 이제 이 스탯으로 플레이어가 사용할 것.
			Level = StatData->Level;
			SetHp(StatData->MaxHp);
			MaxHp = StatData->MaxHp;
			Attack = StatData->Attack;
		}
	}
}

void UMyStatComponent::SetHp(int32 NewHp)
{
	Hp = NewHp;
	if (Hp < 0)
		Hp = 0;

	// HP가 변했다고 알림
	OnHpChanged.Broadcast();
}

void UMyStatComponent::OnAttacked(float DamageAmount)
{
	int32 NewHp = Hp - DamageAmount;
	SetHp(NewHp);

	//UE_LOG(LogTemp, Warning, TEXT("OnAttacked %d"), Hp);
}



