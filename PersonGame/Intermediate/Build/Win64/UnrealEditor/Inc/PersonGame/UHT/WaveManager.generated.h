// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WaveManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PERSONGAME_WaveManager_generated_h
#error "WaveManager.generated.h already included, missing '#pragma once' in WaveManager.h"
#endif
#define PERSONGAME_WaveManager_generated_h

#define FID_PersonGame_Source_PersonGame_WaveManager_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnEnemyKilledDelegate);


#define FID_PersonGame_Source_PersonGame_WaveManager_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWaveManager(); \
	friend struct Z_Construct_UClass_AWaveManager_Statics; \
public: \
	DECLARE_CLASS(AWaveManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PersonGame"), NO_API) \
	DECLARE_SERIALIZER(AWaveManager)


#define FID_PersonGame_Source_PersonGame_WaveManager_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AWaveManager(AWaveManager&&); \
	AWaveManager(const AWaveManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWaveManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWaveManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWaveManager) \
	NO_API virtual ~AWaveManager();


#define FID_PersonGame_Source_PersonGame_WaveManager_h_10_PROLOG
#define FID_PersonGame_Source_PersonGame_WaveManager_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PersonGame_Source_PersonGame_WaveManager_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PersonGame_Source_PersonGame_WaveManager_h_13_INCLASS_NO_PURE_DECLS \
	FID_PersonGame_Source_PersonGame_WaveManager_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PERSONGAME_API UClass* StaticClass<class AWaveManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PersonGame_Source_PersonGame_WaveManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
