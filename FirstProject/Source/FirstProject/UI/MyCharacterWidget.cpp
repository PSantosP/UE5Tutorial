// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/UI/MyCharacterWidget.h"
#include "FirstProject/Actor/MyStatComponent.h"
#include "Components/ProgressBar.h"

void UMyCharacterWidget::BindHp(UMyStatComponent* StatComp)
{
	// 이런식으로 찾아줘야 하지만 그렇지 않도록 하는 것이 중요
	//PB_HpBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HpBar")));
	CurrentStatComp = StatComp;
	// 스탯컴포넌트의 OnHpChanged가 불러오면
	// UpdateHp를 실행해라라는 델리게이트를 설정
	// 람다를 설정할 수도 있다.
	// 일단 우리는 함수를 바인딩하자.
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHp);
}

void UMyCharacterWidget::UpdateHp()
{
	if (CurrentStatComp.IsValid())
		PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
