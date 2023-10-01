// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API UMyCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindHp(class UMyStatComponent* StatComp);

	void UpdateHp();

private:
	// WeakPointer로 설정(스마트 포인터로 관리하는 것이 더 나은 편)
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;

	// 위젯에서 바로 찾을 수 있는데 그게 안된다면 따로 찾아주자.
	UPROPERTY(meta=(BindWidget))
	class UProgressBar* PB_HpBar;
	
};
