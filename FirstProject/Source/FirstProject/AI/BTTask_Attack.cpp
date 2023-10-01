// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/AI/BTTask_Attack.h"
#include "FirstProject\AI\MyAIController.h"
#include "FirstProject\Player\MyCharacter.h"

UBTTask_Attack::UBTTask_Attack()
{
	// 틱을 사용한다.
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


	// 람다
	// bIsAttacking이 BTTask_Attack 클래스의 멤버 변수이기에 this 포인터를 캡쳐
	MyCharacter->OnAttackEnd.AddLambda([this]()
		{
			bIsAttacking = false;
		});
	return Result;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	// 공격이 끝나면 Task를 종료 처리
	if (bIsAttacking == false)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
