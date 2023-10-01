// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FirstProject/AI/BTTask_FindPartolPos.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTTask_FindPartolPos() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_UBTTask_FindPartolPos();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_UBTTask_FindPartolPos_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FirstProject();
// End Cross Module References
	void UBTTask_FindPartolPos::StaticRegisterNativesUBTTask_FindPartolPos()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTTask_FindPartolPos);
	UClass* Z_Construct_UClass_UBTTask_FindPartolPos_NoRegister()
	{
		return UBTTask_FindPartolPos::StaticClass();
	}
	struct Z_Construct_UClass_UBTTask_FindPartolPos_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBTTask_FindPartolPos_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
		(UObject* (*)())Z_Construct_UPackage__Script_FirstProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_FindPartolPos_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBTTask_FindPartolPos_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/BTTask_FindPartolPos.h" },
		{ "ModuleRelativePath", "AI/BTTask_FindPartolPos.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBTTask_FindPartolPos_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_FindPartolPos>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_FindPartolPos_Statics::ClassParams = {
		&UBTTask_FindPartolPos::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_FindPartolPos_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_FindPartolPos_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UBTTask_FindPartolPos()
	{
		if (!Z_Registration_Info_UClass_UBTTask_FindPartolPos.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_FindPartolPos.OuterSingleton, Z_Construct_UClass_UBTTask_FindPartolPos_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBTTask_FindPartolPos.OuterSingleton;
	}
	template<> FIRSTPROJECT_API UClass* StaticClass<UBTTask_FindPartolPos>()
	{
		return UBTTask_FindPartolPos::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_FindPartolPos);
	UBTTask_FindPartolPos::~UBTTask_FindPartolPos() {}
	struct Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTTask_FindPartolPos_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTTask_FindPartolPos_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_FindPartolPos, UBTTask_FindPartolPos::StaticClass, TEXT("UBTTask_FindPartolPos"), &Z_Registration_Info_UClass_UBTTask_FindPartolPos, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_FindPartolPos), 158146422U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTTask_FindPartolPos_h_3850103478(TEXT("/Script/FirstProject"),
		Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTTask_FindPartolPos_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_AI_BTTask_FindPartolPos_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
