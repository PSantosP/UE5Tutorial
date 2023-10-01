// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/AI/BTTask_Attack.h"
#include "FirstProject\AI\MyAIController.h"
#include "FirstProject\Player\MyCharacter.h"

UBTTask_Attack::UBTTask_Attack()
{
	// ƽ�� ����Ѵ�.
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyCharacter = Cast<AMyCharacter>(OwnerComp.GetAIOwner()->GetPawn());

	if (MyCharacter == nullptr)
		return EBTNodeResult::Failed;

	MyCharacter->Attack();
	bIsAttacking = true;


	// ����
	// bIsAttacking�� BTTask_Attack Ŭ������ ��� �����̱⿡ this �����͸� ĸ��
	MyCharacter->OnAttackEnd.AddLambda([this]()
		{
			bIsAttacking = false;
		});
	return Result;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	// ������ ������ Task�� ���� ó��
	if (bIsAttacking == false)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
