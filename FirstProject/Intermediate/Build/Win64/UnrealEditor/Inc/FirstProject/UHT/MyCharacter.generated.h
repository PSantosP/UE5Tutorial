// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/MyCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAnimMontage;
#ifdef FIRSTPROJECT_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define FIRSTPROJECT_MyCharacter_generated_h

#define FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_SPARSE_DATA
#define FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnAttackMontageEnded);


#define FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_ACCESSORS
#define FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FirstProject"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyCharacter) \
	NO_API virtual ~AMyCharacter();


#define FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_9_PROLOG
#define FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_SPARSE_DATA \
	FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_ACCESSORS \
	FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_INCLASS_NO_PURE_DECLS \
	FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FIRSTPROJECT_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Player_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
