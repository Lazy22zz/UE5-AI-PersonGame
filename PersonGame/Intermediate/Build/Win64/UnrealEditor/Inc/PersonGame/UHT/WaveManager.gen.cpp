// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PersonGame/WaveManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWaveManager() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
PERSONGAME_API UClass* Z_Construct_UClass_AWaveManager();
PERSONGAME_API UClass* Z_Construct_UClass_AWaveManager_NoRegister();
UPackage* Z_Construct_UPackage__Script_PersonGame();
// End Cross Module References

// Begin Class AWaveManager Function OnEnemyKilledDelegate
struct Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics
{
	struct WaveManager_eventOnEnemyKilledDelegate_Parms
	{
		int32 ScoreValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WaveManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ScoreValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::NewProp_ScoreValue = { "ScoreValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WaveManager_eventOnEnemyKilledDelegate_Parms, ScoreValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::NewProp_ScoreValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWaveManager, nullptr, "OnEnemyKilledDelegate", nullptr, nullptr, Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::WaveManager_eventOnEnemyKilledDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::WaveManager_eventOnEnemyKilledDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AWaveManager::execOnEnemyKilledDelegate)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ScoreValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnEnemyKilledDelegate(Z_Param_ScoreValue);
	P_NATIVE_END;
}
// End Class AWaveManager Function OnEnemyKilledDelegate

// Begin Class AWaveManager
void AWaveManager::StaticRegisterNativesAWaveManager()
{
	UClass* Class = AWaveManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnEnemyKilledDelegate", &AWaveManager::execOnEnemyKilledDelegate },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWaveManager);
UClass* Z_Construct_UClass_AWaveManager_NoRegister()
{
	return AWaveManager::StaticClass();
}
struct Z_Construct_UClass_AWaveManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "WaveManager.h" },
		{ "ModuleRelativePath", "WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArenaRadius_MetaData[] = {
		{ "Category", "Arena" },
		{ "ModuleRelativePath", "WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentWave_MetaData[] = {
		{ "Category", "Game" },
		{ "ModuleRelativePath", "WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Score_MetaData[] = {
		{ "Category", "Game" },
		{ "ModuleRelativePath", "WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGameOver_MetaData[] = {
		{ "Category", "Game" },
		{ "ModuleRelativePath", "WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGameStarted_MetaData[] = {
		{ "Category", "Game" },
		{ "ModuleRelativePath", "WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBetweenWaves_MetaData[] = {
		{ "Category", "Game" },
		{ "ModuleRelativePath", "WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WaveCountdown_MetaData[] = {
		{ "Category", "Game" },
		{ "ModuleRelativePath", "WaveManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeBetweenWaves_MetaData[] = {
		{ "Category", "Game" },
		{ "ModuleRelativePath", "WaveManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArenaRadius;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentWave;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Score;
	static void NewProp_bGameOver_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGameOver;
	static void NewProp_bGameStarted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGameStarted;
	static void NewProp_bBetweenWaves_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBetweenWaves;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WaveCountdown;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeBetweenWaves;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AWaveManager_OnEnemyKilledDelegate, "OnEnemyKilledDelegate" }, // 2791227309
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWaveManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_ArenaRadius = { "ArenaRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveManager, ArenaRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArenaRadius_MetaData), NewProp_ArenaRadius_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_CurrentWave = { "CurrentWave", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveManager, CurrentWave), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentWave_MetaData), NewProp_CurrentWave_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveManager, Score), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Score_MetaData), NewProp_Score_MetaData) };
void Z_Construct_UClass_AWaveManager_Statics::NewProp_bGameOver_SetBit(void* Obj)
{
	((AWaveManager*)Obj)->bGameOver = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_bGameOver = { "bGameOver", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AWaveManager), &Z_Construct_UClass_AWaveManager_Statics::NewProp_bGameOver_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGameOver_MetaData), NewProp_bGameOver_MetaData) };
void Z_Construct_UClass_AWaveManager_Statics::NewProp_bGameStarted_SetBit(void* Obj)
{
	((AWaveManager*)Obj)->bGameStarted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_bGameStarted = { "bGameStarted", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AWaveManager), &Z_Construct_UClass_AWaveManager_Statics::NewProp_bGameStarted_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGameStarted_MetaData), NewProp_bGameStarted_MetaData) };
void Z_Construct_UClass_AWaveManager_Statics::NewProp_bBetweenWaves_SetBit(void* Obj)
{
	((AWaveManager*)Obj)->bBetweenWaves = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_bBetweenWaves = { "bBetweenWaves", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AWaveManager), &Z_Construct_UClass_AWaveManager_Statics::NewProp_bBetweenWaves_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBetweenWaves_MetaData), NewProp_bBetweenWaves_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_WaveCountdown = { "WaveCountdown", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveManager, WaveCountdown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WaveCountdown_MetaData), NewProp_WaveCountdown_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AWaveManager_Statics::NewProp_TimeBetweenWaves = { "TimeBetweenWaves", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWaveManager, TimeBetweenWaves), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeBetweenWaves_MetaData), NewProp_TimeBetweenWaves_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWaveManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_ArenaRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_CurrentWave,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_Score,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_bGameOver,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_bGameStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_bBetweenWaves,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_WaveCountdown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWaveManager_Statics::NewProp_TimeBetweenWaves,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AWaveManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_PersonGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AWaveManager_Statics::ClassParams = {
	&AWaveManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AWaveManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AWaveManager_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWaveManager_Statics::Class_MetaDataParams), Z_Construct_UClass_AWaveManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AWaveManager()
{
	if (!Z_Registration_Info_UClass_AWaveManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWaveManager.OuterSingleton, Z_Construct_UClass_AWaveManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AWaveManager.OuterSingleton;
}
template<> PERSONGAME_API UClass* StaticClass<AWaveManager>()
{
	return AWaveManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AWaveManager);
AWaveManager::~AWaveManager() {}
// End Class AWaveManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_PersonGame_Source_PersonGame_WaveManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AWaveManager, AWaveManager::StaticClass, TEXT("AWaveManager"), &Z_Registration_Info_UClass_AWaveManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWaveManager), 191302068U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PersonGame_Source_PersonGame_WaveManager_h_2526734782(TEXT("/Script/PersonGame"),
	Z_CompiledInDeferFile_FID_PersonGame_Source_PersonGame_WaveManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PersonGame_Source_PersonGame_WaveManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
