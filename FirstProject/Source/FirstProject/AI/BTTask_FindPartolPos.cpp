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
	// 이 함수는 성공이 되면 다음 함수로 넘어가지만 성공이 아니라면 다음 함수로 넘어가지 않기 때문에
	// 성공여부를 반환시켜야 하는 함수이다.
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
	UE_LOG(LogTemp, Warning, TEXT("Succees"));
	// AI의 폰을 가져와서
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	UE_LOG(LogTemp, Warning, TEXT("Succees"));
	if (CurrentPawn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed"));
		return EBTNodeResult::Failed;
	}

	// 네비게이션 시스템을 가져온다.
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed"));
		return EBTNodeResult::Failed;
	}

	UE_LOG(LogTemp, Warning, TEXT("Succees"));
	FNavLocation RandomLocation;		// 네비 기반으로 좌표찍어놓을 변수
	// ZeroVector중심으로 500거리의 내 랜덤한 위치를 RandomLocation에 찍어놓는데에 성공하면
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
	{
		// AI 한테 찍은 좌표로 이동시키라고 명령
		// UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("PatrolPos")), RandomLocation.Location);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
