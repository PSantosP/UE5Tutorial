// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstProject/GameMode/MyGameModeBase.h"
#include "FirstProject/Player/MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	// UClass�� ����ϴ� ��ü��
	// ��Ÿ�ӿ� �� Ŭ������ ��Ÿ���� ��ü�� ��ȯ�ϴ� ����
	// StaticClass��� �Ѵ�.
	// �� ��Ÿ�ӿ� AMyPawn�̶�� ��ü�� ��ȯ��Ű�� ���̶�� �����ϸ� ���ϴ�.

	// ĳ���͸� ������ �� �ִ� ������ Character�� Pawn���� Ȯ��� Ŭ����
	// �� Pawn�� ��ӹ޴´ٶ�� �� �� �ִ�.
	// �׷��⿡ DefaultPawnClass�� ���� �� ����
	DefaultPawnClass = AMyCharacter::StaticClass();

	// �������Ʈ Ŭ�������� �ҷ����µ��� �־ �������� ������ _C�� �ٿ��� �Ѵ�.
	// �̰��� �𸮾� ��Ģ�̱⿡ �� �ؾ��Ѵ�.
	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("/Script/Engine.Blueprint'/Game/Blueprints/BP_MyCharacter.BP_MyCharacter'_C'"));

	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}
}