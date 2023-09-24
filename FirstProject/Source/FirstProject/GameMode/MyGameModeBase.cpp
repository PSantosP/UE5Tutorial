// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/GameMode/MyGameModeBase.h"
#include "FirstProject/Player/MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	// UClass를 사용하는 객체는
	// 런타임에 이 클래스를 나타내는 객체를 반환하는 것을
	// StaticClass라고 한다.
	// 즉 런타임에 AMyPawn이라는 객체를 반환시키는 것이라고 생각하면 편하다.

	// 캐릭터를 가져올 수 있는 이유는 Character는 Pawn에서 확장된 클래스
	// 즉 Pawn을 상속받는다라고 볼 수 있다.
	// 그렇기에 DefaultPawnClass에 넣을 수 있음
	DefaultPawnClass = AMyCharacter::StaticClass();

	// 블루프린트 클ㄹ래스를 불러오는데에 있어서 마지막에 무조건 _C를 붙여야 한다.
	// 이것은 언리얼 규칙이기에 꼭 해야한다.
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/BP_MyCharacter.BP_MyCharacter'_C'"));

	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}
}