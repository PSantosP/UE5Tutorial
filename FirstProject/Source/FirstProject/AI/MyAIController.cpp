// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/AI/MyAIController.h"
#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AMyAIController::AMyAIController()
{

}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	// ������ Ÿ���� 1.5�ʸ��� RandomMove�Լ��� ����
	// ���߿� BehaviorTree�� ����� ���̱⿡ ���� ������ ����
	// (Ÿ�̸� �ڵ�, ���� ��������, �� ��������, ���� �ֱ�, true�� �س����� ���ට���� ������ �ɸ�)
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyAIController::RandomMove, 1.5f, true);
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();

	// �ڵ��� �ֱ⸶�� ������ �̺�Ʈ���� ���� ����
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
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
