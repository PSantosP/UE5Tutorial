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

	// Pawn이 빙의 될 때 불러와지는 함수
	virtual void OnPossess(APawn* InPawn) override;
	// Pawn이 빙의가 끝났을 때 불러와지는 함수
	virtual void OnUnPossess() override;

private:
	void RandomMove();

private:
	FTimerHandle TimerHandle;
};
