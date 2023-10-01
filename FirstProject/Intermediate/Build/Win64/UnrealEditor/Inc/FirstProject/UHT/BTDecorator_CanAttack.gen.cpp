// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FirstProject/AI/BTDecorator_CanAttack.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTDecorator_CanAttack() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTDecorator();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_UBTDecorator_CanAttack();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_UBTDecorator_CanAttack_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FirstProject();
// End Cross Module References
	void UBTDecorator_CanAttack::StaticRegisterNativesUBTDecorator_CanAttack()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTDecorator_CanAttack);
	UClass* Z_Construct_UClass_UBTDecorator_CanAttack_NoRegister()
	{
		return UBTDecorator_CanAttack::StaticClass();
	}
	struct Z_Construct_UClass_UBTDecorator_CanAttack_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTDecorator_CanAttack_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTDecorator,
		(UObject* (*)())Z_Construct_UPackage__Script_FirstProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_CanAttack_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTDecorator_CanAttack_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTDecorator_CanAttack.h" },
		{ "ModuleRelativePath", "AI/BTDecorator_CanAttack.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTDecorator_CanAttack_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTDecorator_CanAttack>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTDecorator_CanAttack_Statics::ClassParams = {
		&UBTDecorator_CanAttack::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTDecorator_CanAttack_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTDecorator_CanAttack_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTDecorator_CanAttack()
	{
		if (!Z_Registration_Info_UClass_UBTDecorator_CanAttack.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTDecorator_CanAttack.OuterSingleton, Z_Construct_UClass_UBTDecorator_CanAttack_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTDecorator_CanAttack.OuterSingleton;
	}
	template<> FIRSTPROJECT_API UClass* StaticClass<UBTDecorator_CanAttack>()
	{
		return UBTDecorator_CanAttack::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTDecorator_CanAttack);
	UBTDecorator_CanAttack::~UBTDecorator_CanAttack() {}
	struct Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTDecorator_CanAttack_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTDecorator_CanAttack_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTDecorator_CanAttack, UBTDecorator_CanAttack::StaticClass, TEXT("UBTDecorator_CanAttack"), &Z_Registration_Info_UClass_UBTDecorator_CanAttack, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTDecorator_CanAttack), 188477655U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTDecorator_CanAttack_h_241053673(TEXT("/Script/FirstProject"),
		Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTDecorator_CanAttack_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTDecorator_CanAttack_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
