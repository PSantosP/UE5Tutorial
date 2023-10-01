// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/AI/BTService_SearchTarget.h"
#include "FirstProject\AI\MyAIController.h"
#include "FirstProject\Player\MyCharacter.h"
#include "BehaviorTree\BehaviorTreeComponent.h"
#include "BehaviorTree\BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTService_SearchTarget::UBTService_SearchTarget()
{
	// Interval�� Tick �����̸� �������� �� �ִ�.
	NodeName = TEXT("SerachTarget");
	Interval = 1.0f;
}

void UBTService_SearchTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// �ֱ������� �� TickNode�� �����̵Ǵµ�.
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	// ���� �����´�.
	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (CurrentPawn == nullptr)
		return;

	// ����� Actor�� Location�� �����´�.
	// �ݰ��� 500f
	UWorld* World = CurrentPawn->GetWorld();
	FVector Center = CurrentPawn->GetActorLocation();
	float SerachRadius = 500.f;

	if (World == nullptr)
		return;

	// �浹����� �޾ƿ� Result
	TArray<FOverlapResult> OverlapResults;
	// �ݸ����� ���ڵ��� �޾ƿ��� ����
	FCollisionQueryParams QueryParams(NAME_None, false, CurrentPawn);

	// �ֺ��� �˻��ؼ� �ݶ��̴� ä�ο� �´��� Ȯ��
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(SerachRadius),
		QueryParams);

	if (bResult)
	{
		// ã��
		// OverlapResults�� �ѹ��� ���� üũ
		for (auto& OverlapResult : OverlapResults)
		{
			// MyCharacter�� �����´�.
			AMyCharacter* MyCharacter = Cast<AMyCharacter>(OverlapResult.GetActor());
			if (MyCharacter && MyCharacter->GetController()->IsPlayerController())
			{
				// MyCharacter�� �־���
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), MyCharacter);

				DrawDebugSphere(World, Center, SerachRadius, 16, FColor::Green, false, 0.2f);
			}
		}

		//DrawDebugSphere(World, Center, SerachRadius, 16, FColor::Red, false, 0.2f);
	}
	else
	{
		// ��ã��
		// nullptr�� �־���
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Target")), nullptr);

		DrawDebugSphere(World, Center, SerachRadius, 16, FColor::Red, false, 0.2f);
	}
}
