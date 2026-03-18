// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePersonGame_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_PersonGame;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_PersonGame()
	{
		if (!Z_Registration_Info_UPackage__Script_PersonGame.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/PersonGame",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xF6091266,
				0x494A0ACF,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_PersonGame.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_PersonGame.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_PersonGame(Z_Construct_UPackage__Script_PersonGame, TEXT("/Script/PersonGame"), Z_Registration_Info_UPackage__Script_PersonGame, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF6091266, 0x494A0ACF));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
