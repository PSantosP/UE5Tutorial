// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFirstProject_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_FirstProject;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_FirstProject()
	{
		if (!Z_Registration_Info_UPackage__Script_FirstProject.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/FirstProject",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xC26435C2,
				0x192EB27E,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_FirstProject.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_FirstProject.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_FirstProject(Z_Construct_UPackage__Script_FirstProject, TEXT("/Script/FirstProject"), Z_Registration_Info_UPackage__Script_FirstProject, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xC26435C2, 0x192EB27E));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
