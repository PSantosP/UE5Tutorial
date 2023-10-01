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
	// WeakPointer�� ����(����Ʈ �����ͷ� �����ϴ� ���� �� ���� ��)
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;

	// �������� �ٷ� ã�� �� �ִµ� �װ� �ȵȴٸ� ���� ã������.
	UPROPERTY(meta=(BindWidget))
	class UProgressBar* PB_HpBar;
	
};
