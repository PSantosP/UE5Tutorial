// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Actor/MyWeapon.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef FIRSTPROJECT_MyWeapon_generated_h
#error "MyWeapon.generated.h already included, missing '#pragma once' in MyWeapon.h"
#endif
#define FIRSTPROJECT_MyWeapon_generated_h

#define FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_SPARSE_DATA
#define FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnCharacterOverlap);


#define FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_ACCESSORS
#define FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyWeapon(); \
	friend struct Z_Construct_UClass_AMyWeapon_Statics; \
public: \
	DECLARE_CLASS(AMyWeapon, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FirstProject"), NO_API) \
	DECLARE_SERIALIZER(AMyWeapon)


#define FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyWeapon(AMyWeapon&&); \
	NO_API AMyWeapon(const AMyWeapon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyWeapon); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyWeapon); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyWeapon) \
	NO_API virtual ~AMyWeapon();


#define FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_9_PROLOG
#define FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_SPARSE_DATA \
	FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_ACCESSORS \
	FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_INCLASS_NO_PURE_DECLS \
	FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FIRSTPROJECT_API UClass* StaticClass<class AMyWeapon>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealEngineProject_UE5Tutorial_FirstProject_Source_FirstProject_Actor_MyWeapon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
