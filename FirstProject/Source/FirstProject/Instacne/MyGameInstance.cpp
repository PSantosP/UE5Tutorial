// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/Instacne/MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	// 데이터 테이블 불러오기
	static ConstructorHelpers::FObjectFinder<UDataTable>DATA(TEXT("/Script/Engine.DataTable'/Game/Data/StatTable.StatTable'"));
	if (DATA.Succeeded())
	{
		// 데이터 테이블 적용
		MyStats = DATA.Object;
	}
}

void UMyGameInstance::Init()
{
	Super::Init();

	// 제대로 불러와지는지 확인
	UE_LOG(LogTemp, Warning, TEXT("MyGameInstance %d"), GetStatData(1)->Attack);
}

FMyCharacterData* UMyGameInstance::GetStatData(int32 Level)
{
	// FindRow를 통해 Level에 맞는 데이터를 불러옴
	return MyStats->FindRow<FMyCharacterData>(*FString::FromInt(Level), TEXT(""));
}
