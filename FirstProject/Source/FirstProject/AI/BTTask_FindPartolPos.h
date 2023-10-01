// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindPartolPos.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API UBTTask_FindPartolPos : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_FindPartolPos();

	// �½�ũ�� �����ϴ� �Լ�
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
