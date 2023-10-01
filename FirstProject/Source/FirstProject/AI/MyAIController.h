// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AMyAIController();

	// Pawn�� ���� �� �� �ҷ������� �Լ�
	virtual void OnPossess(APawn* InPawn) override;
	// Pawn�� ���ǰ� ������ �� �ҷ������� �Լ�
	virtual void OnUnPossess() override;

private:
	void RandomMove();

private:
	FTimerHandle TimerHandle;
};
