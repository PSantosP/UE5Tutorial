// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FirstProject/AI/BTService_SearchTarget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_SearchTarget() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTService();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_UBTService_SearchTarget();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_UBTService_SearchTarget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FirstProject();
// End Cross Module References
	void UBTService_SearchTarget::StaticRegisterNativesUBTService_SearchTarget()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_SearchTarget);
	UClass* Z_Construct_UClass_UBTService_SearchTarget_NoRegister()
	{
		return UBTService_SearchTarget::StaticClass();
	}
	struct Z_Construct_UClass_UBTService_SearchTarget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTService_SearchTarget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTService,
		(UObject* (*)())Z_Construct_UPackage__Script_FirstProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_SearchTarget_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTService_SearchTarget_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTService_SearchTarget.h" },
		{ "ModuleRelativePath", "AI/BTService_SearchTarget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTService_SearchTarget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_SearchTarget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_SearchTarget_Statics::ClassParams = {
		&UBTService_SearchTarget::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_SearchTarget_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTService_SearchTarget_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTService_SearchTarget()
	{
		if (!Z_Registration_Info_UClass_UBTService_SearchTarget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_SearchTarget.OuterSingleton, Z_Construct_UClass_UBTService_SearchTarget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTService_SearchTarget.OuterSingleton;
	}
	template<> FIRSTPROJECT_API UClass* StaticClass<UBTService_SearchTarget>()
	{
		return UBTService_SearchTarget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_SearchTarget);
	UBTService_SearchTarget::~UBTService_SearchTarget() {}
	struct Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTService_SearchTarget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTService_SearchTarget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_SearchTarget, UBTService_SearchTarget::StaticClass, TEXT("UBTService_SearchTarget"), &Z_Registration_Info_UClass_UBTService_SearchTarget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_SearchTarget), 2790535255U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTService_SearchTarget_h_2999908482(TEXT("/Script/FirstProject"),
		Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTService_SearchTarget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTService_SearchTarget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
