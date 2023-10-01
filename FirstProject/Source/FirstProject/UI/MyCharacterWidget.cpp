// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/UI/MyCharacterWidget.h"
#include "FirstProject/Actor/MyStatComponent.h"
#include "Components/ProgressBar.h"

void UMyCharacterWidget::BindHp(UMyStatComponent* StatComp)
{
	// �̷������� ã����� ������ �׷��� �ʵ��� �ϴ� ���� �߿�
	//PB_HpBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HpBar")));
	CurrentStatComp = StatComp;
	// ����������Ʈ�� OnHpChanged�� �ҷ�����
	// UpdateHp�� �����ض��� ��������Ʈ�� ����
	// ���ٸ� ������ ���� �ִ�.
	// �ϴ� �츮�� �Լ��� ���ε�����.
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHp);
}

void UMyCharacterWidget::UpdateHp()
{
	if (CurrentStatComp.IsValid())
		PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
