// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FirstProject/Instacne/MyGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyGameInstance() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_UMyGameInstance();
	FIRSTPROJECT_API UClass* Z_Construct_UClass_UMyGameInstance_NoRegister();
	FIRSTPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FMyCharacterData();
	UPackage* Z_Construct_UPackage__Script_FirstProject();
// End Cross Module References

static_assert(std::is_polymorphic<FMyCharacterData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FMyCharacterData cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MyCharacterData;
class UScriptStruct* FMyCharacterData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MyCharacterData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MyCharacterData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMyCharacterData, (UObject*)Z_Construct_UPackage__Script_FirstProject(), TEXT("MyCharacterData"));
	}
	return Z_Registration_Info_UScriptStruct_MyCharacterData.OuterSingleton;
}
template<> FIRSTPROJECT_API UScriptStruct* StaticStruct<FMyCharacterData>()
{
	return FMyCharacterData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMyCharacterData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Attack_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Attack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHp_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxHp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMyCharacterData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Instacne/MyGameInstance.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMyCharacterData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Level_MetaData[] = {
		{ "Category", "MyCharacterData" },
		{ "ModuleRelativePath", "Instacne/MyGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyCharacterData, Level), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Level_MetaData), Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Level_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Attack_MetaData[] = {
		{ "Category", "MyCharacterData" },
		{ "ModuleRelativePath", "Instacne/MyGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Attack = { "Attack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyCharacterData, Attack), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Attack_MetaData), Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Attack_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_MaxHp_MetaData[] = {
		{ "Category", "MyCharacterData" },
		{ "ModuleRelativePath", "Instacne/MyGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_MaxHp = { "MaxHp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyCharacterData, MaxHp), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_MaxHp_MetaData), Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_MaxHp_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMyCharacterData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_Attack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewProp_MaxHp,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMyCharacterData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FirstProject,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"MyCharacterData",
		Z_Construct_UScriptStruct_FMyCharacterData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyCharacterData_Statics::PropPointers),
		sizeof(FMyCharacterData),
		alignof(FMyCharacterData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyCharacterData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMyCharacterData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyCharacterData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FMyCharacterData()
	{
		if (!Z_Registration_Info_UScriptStruct_MyCharacterData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MyCharacterData.InnerSingleton, Z_Construct_UScriptStruct_FMyCharacterData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MyCharacterData.InnerSingleton;
	}
	void UMyGameInstance::StaticRegisterNativesUMyGameInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyGameInstance);
	UClass* Z_Construct_UClass_UMyGameInstance_NoRegister()
	{
		return UMyGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UMyGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MyStats_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MyStats;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_FirstProject,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyGameInstance_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "Instacne/MyGameInstance.h" },
		{ "ModuleRelativePath", "Instacne/MyGameInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyGameInstance_Statics::NewProp_MyStats_MetaData[] = {
		{ "ModuleRelativePath", "Instacne/MyGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyGameInstance_Statics::NewProp_MyStats = { "MyStats", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyGameInstance, MyStats), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::NewProp_MyStats_MetaData), Z_Construct_UClass_UMyGameInstance_Statics::NewProp_MyStats_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyGameInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyGameInstance_Statics::NewProp_MyStats,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyGameInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyGameInstance_Statics::ClassParams = {
		&UMyGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMyGameInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyGameInstance_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyGameInstance_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UMyGameInstance()
	{
		if (!Z_Registration_Info_UClass_UMyGameInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyGameInstance.OuterSingleton, Z_Construct_UClass_UMyGameInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyGameInstance.OuterSingleton;
	}
	template<> FIRSTPROJECT_API UClass* StaticClass<UMyGameInstance>()
	{
		return UMyGameInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyGameInstance);
	UMyGameInstance::~UMyGameInstance() {}
	struct Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Instacne_MyGameInstance_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Instacne_MyGameInstance_h_Statics::ScriptStructInfo[] = {
		{ FMyCharacterData::StaticStruct, Z_Construct_UScriptStruct_FMyCharacterData_Statics::NewStructOps, TEXT("MyCharacterData"), &Z_Registration_Info_UScriptStruct_MyCharacterData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMyCharacterData), 2127898829U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Instacne_MyGameInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyGameInstance, UMyGameInstance::StaticClass, TEXT("UMyGameInstance"), &Z_Registration_Info_UClass_UMyGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyGameInstance), 578175107U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Instacne_MyGameInstance_h_871986549(TEXT("/Script/FirstProject"),
		Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Instacne_MyGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Instacne_MyGameInstance_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Instacne_MyGameInstance_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProject_UE5Tutorial_FirstProject_Source_FirstProject_Instacne_MyGameInstance_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
