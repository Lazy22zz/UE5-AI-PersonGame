// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePersonGame_init() {}
	PERSONGAME_API UFunction* Z_Construct_UDelegateFunction_PersonGame_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_PersonGame;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_PersonGame()
	{
		if (!Z_Registration_Info_UPackage__Script_PersonGame.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_PersonGame_OnEnemyDied__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/PersonGame",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x09B741DC,
				0xFA6D1AC4,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_PersonGame.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_PersonGame.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_PersonGame(Z_Construct_UPackage__Script_PersonGame, TEXT("/Script/PersonGame"), Z_Registration_Info_UPackage__Script_PersonGame, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x09B741DC, 0xFA6D1AC4));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
