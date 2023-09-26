// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/Instacne/MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	// ������ ���̺� �ҷ�����
	static ConstructorHelpers::FObjectFinder<UDataTable>DATA(TEXT("/Script/Engine.DataTable'/Game/Data/StatTable.StatTable'"));
	if (DATA.Succeeded())
	{
		// ������ ���̺� ����
		MyStats = DATA.Object;
	}
}

void UMyGameInstance::Init()
{
	Super::Init();

	// ����� �ҷ��������� Ȯ��
	UE_LOG(LogTemp, Warning, TEXT("MyGameInstance %d"), GetStatData(1)->Attack);
}

FMyCharacterData* UMyGameInstance::GetStatData(int32 Level)
{
	// FindRow�� ���� Level�� �´� �����͸� �ҷ���
	return MyStats->FindRow<FMyCharacterData>(*FString::FromInt(Level), TEXT(""));
}
