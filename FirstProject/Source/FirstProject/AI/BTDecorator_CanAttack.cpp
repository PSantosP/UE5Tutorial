// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/AI/BTDecorator_CanAttack.h"
#include "FirstProject\AI\MyAIController.h"
#include "FirstProject\Player\MyCharacter.h"
#include "BehaviorTree\BlackboardComponent.h"

UBTDecorator_CanAttack::UBTDecorator_CanAttack()
{
	// ��� ������ CanAttack���� ����
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_CanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	// AI���ʿ� ���� �����´�.
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn == nullptr)
		return false;

	// ������ Ʈ���� �����忡�� Object(Target)�� MyCharacter�� ����
	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));
	if (Target == nullptr)
		return false;

	// �Ÿ��� 200������ �Ÿ��� ������ true
	return bResult && Target->GetDistanceTo(CurrentPawn) <= 200.f;
}
