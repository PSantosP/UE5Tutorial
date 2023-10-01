// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/AI/BTService_SearchTarget.h"
#include "FirstProject\AI\MyAIController.h"
#include "FirstProject\Player\MyCharacter.h"
#include "BehaviorTree\BehaviorTreeComponent.h"
#include "BehaviorTree\BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTService_SearchTarget::UBTService_SearchTarget()
{
	// Interval로 Tick 딜레이를 설정해줄 수 있다.
	NodeName = TEXT("SerachTarget");
	Interval = 1.0f;
}

void UBTService_SearchTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// 주기적으로 이 TickNode가 실행이되는데.
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// 폰을 가져온다.
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (CurrentPawn == nullptr)
		return;

	// 월드와 Actor의 Location을 가져온다.
	// 반경은 500f
	UWorld* World = CurrentPawn->GetWorld();
	FVector Center = CurrentPawn->GetActorLocation();
	float SerachRadius = 500.f;

	if (World == nullptr)
		return;

	// 충돌결과를 받아올 Result
	TArray<FOverlapResult> OverlapResults;
	// 콜리전의 인자들을 받아오는 변수
	FCollisionQueryParams QueryParams(NAME_None, false, CurrentPawn);

	// 주변을 검색해서 콜라이더 채널에 맞는지 확인
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(SerachRadius),
		QueryParams);

	if (bResult)
	{
		// 찾음
		// OverlapResults를 한바퀴 돌아 체크
		for (auto& OverlapResult : OverlapResults)
		{
			// MyCharacter를 가져온다.
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor());
			if (MyCharacter && MyCharacter->GetController()->IsPlayerController())
			{
				// MyCharacter를 넣어줌
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), MyCharacter);

				DrawDebugSphere(World, Center, SerachRadius, 16, FColor::Green, false, 0.2f);
			}
		}

		//DrawDebugSphere(World, Center, SerachRadius, 16, FColor::Red, false, 0.2f);
	}
	else
	{
		// 못찾음
		// nullptr로 넣어줌
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);

		DrawDebugSphere(World, Center, SerachRadius, 16, FColor::Red, false, 0.2f);
	}
}
