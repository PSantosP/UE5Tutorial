// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/AI/BTTask_FindPartolPos.h"

#include "FirstProject/AI/MyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree\BehaviorTree.h"
#include "BehaviorTree\BlackboardData.h"
#include "BehaviorTree\BlackboardComponent.h"


UBTTask_FindPartolPos::UBTTask_FindPartolPos()
{
	NodeName = TEXT("FindPatrolPos");
}

EBTNodeResult::Type UBTTask_FindPartolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	// �� �Լ��� ������ �Ǹ� ���� �Լ��� �Ѿ���� ������ �ƴ϶�� ���� �Լ��� �Ѿ�� �ʱ� ������
	// �������θ� ��ȯ���Ѿ� �ϴ� �Լ��̴�.
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
	UE_LOG(LogTemp, Warning, TEXT("Succees"));
	// AI�� ���� �����ͼ�
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	UE_LOG(LogTemp, Warning, TEXT("Succees"));
	if (CurrentPawn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed"));
		return EBTNodeResult::Failed;
	}

	// �׺���̼� �ý����� �����´�.
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed"));
		return EBTNodeResult::Failed;
	}

	UE_LOG(LogTemp, Warning, TEXT("Succees"));
	FNavLocation RandomLocation;		// �׺� ������� ��ǥ������ ����
	// ZeroVector�߽����� 500�Ÿ��� �� ������ ��ġ�� RandomLocation�� �����µ��� �����ϸ�
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
	{
		// AI ���� ���� ��ǥ�� �̵���Ű��� ���
		// UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("PatrolPos")), RandomLocation.Location);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
