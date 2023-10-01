// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/AI/MyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree\BehaviorTree.h"
#include "BehaviorTree\BlackboardData.h"
#include "BehaviorTree\BlackboardComponent.h"

AMyAIController::AMyAIController()
{
	// BT ����
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("/Script/AIModule.BehaviorTree'/Game/AI/BT_MyCharacter.BT_MyCharacter'"));

	if (BT.Succeeded())
	{
		BehaviorTree = BT.Object;
	}

	// BD ����
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BD(TEXT("/Script/AIModule.BlackboardData'/Game/AI/BB_MyCharacter.BB_MyCharacter'"));

	if (BD.Succeeded())
	{
		BlackBoardData = BD.Object;
	}
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	// ������ Ÿ���� 1.5�ʸ��� RandomMove�Լ��� ����
	// ���߿� BehaviorTree�� ����� ���̱⿡ ���� ������ ����
	// (Ÿ�̸� �ڵ�, ���� ��������, �� ��������, ���� �ֱ�, true�� �س����� ���ට���� ������ �ɸ�)
	// GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyAIController::RandomMove, 1.5f, true);

	// BlackBoard�� null�̶� �ȵ�

	UBlackboardComponent* BlackboardComp = Blackboard.Get();
	// �����带 ����ϰ�
	if (UseBlackboard(BlackBoardData, BlackboardComp))
	{
		UE_LOG(LogTemp, Warning, TEXT("Success"));
		// �����̺�� Ʈ���� ����Ѵٴ� ���̴�.
		if (RunBehaviorTree(BehaviorTree))
		{
			// TODO
			UE_LOG(LogTemp, Warning, TEXT("Success"));
		}
	}
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();

	// �ڵ��� �ֱ⸶�� ������ �̺�Ʈ���� ���� ����
	//GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void AMyAIController::RandomMove()
{
	// ���� �����ͼ�
	auto CurrentPawn = GetPawn();

	// �׺���̼� �ý����� �����´�.
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
		return;

	FNavLocation RandomLocation;		// �׺� ������� ��ǥ������ ����
	// ZeroVector�߽����� 500�Ÿ��� �� ������ ��ġ�� RandomLocation�� �����µ��� �����ϸ�
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
	{
		// AI ���� ���� ��ǥ�� �̵���Ű��� ���
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
	}
}
