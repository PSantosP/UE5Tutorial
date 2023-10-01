// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/AI/BTDecorator_CanAttack.h"
#include "FirstProject\AI\MyAIController.h"
#include "FirstProject\Player\MyCharacter.h"
#include "BehaviorTree\BlackboardComponent.h"

UBTDecorator_CanAttack::UBTDecorator_CanAttack()
{
	// 노드 네임은 CanAttack으로 설정
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_CanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	// AI오너에 폰을 가져온다.
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return false;

	// 비헤비어 트리의 블랙보드에서 Object(Target)를 MyCharacter로 설정
	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));
	if (Target == nullptr)
		return false;

	// 거리가 200정도의 거리가 있으면 true
	return bResult && Target->GetDistanceTo(CurrentPawn) <= 200.f;
}
