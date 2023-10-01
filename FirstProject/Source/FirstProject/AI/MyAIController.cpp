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
	// 월드의 타임의 1.5초마다 RandomMove함수를 실행
	// 나중에 BehaviorTree를 사용할 것이기에 깊이 파지는 말자
	// (타이머 핸들, 누가 실행할지, 뭐 실행할지, 실행 주기, true로 해놓으면 실행때부터 딜레이 걸림)
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyAIController::RandomMove, 1.5f, true);
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();

	// 핸들을 주기마다 실행할 이벤트에서 빼는 역할
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void AMyAIController::RandomMove()
{
	// 폰을 가져와서
	auto CurrentPawn = GetPawn();

	// 네비게이션 시스템을 가져온다.
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	if (NavSystem == nullptr)
		return;

	FNavLocation RandomLocation;		// 네비 기반으로 좌표찍어놓을 변수
	// ZeroVector중심으로 500거리의 내 랜덤한 위치를 RandomLocation에 찍어놓는데에 성공하면
	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
	{
		// AI 한테 찍은 좌표로 이동시키라고 명령
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, RandomLocation);
	}
}
