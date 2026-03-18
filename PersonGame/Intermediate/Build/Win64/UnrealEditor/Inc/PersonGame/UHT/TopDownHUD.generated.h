// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "TopDownHUD.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PERSONGAME_TopDownHUD_generated_h
#error "TopDownHUD.generated.h already included, missing '#pragma once' in TopDownHUD.h"
#endif
#define PERSONGAME_TopDownHUD_generated_h

#define FID_PersonGame_Source_PersonGame_TopDownHUD_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATopDownHUD(); \
	friend struct Z_Construct_UClass_ATopDownHUD_Statics; \
public: \
	DECLARE_CLASS(ATopDownHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/PersonGame"), NO_API) \
	DECLARE_SERIALIZER(ATopDownHUD)


#define FID_PersonGame_Source_PersonGame_TopDownHUD_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ATopDownHUD(ATopDownHUD&&); \
	ATopDownHUD(const ATopDownHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATopDownHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATopDownHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATopDownHUD) \
	NO_API virtual ~ATopDownHUD();


#define FID_PersonGame_Source_PersonGame_TopDownHUD_h_9_PROLOG
#define FID_PersonGame_Source_PersonGame_TopDownHUD_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PersonGame_Source_PersonGame_TopDownHUD_h_12_INCLASS_NO_PURE_DECLS \
	FID_PersonGame_Source_PersonGame_TopDownHUD_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PERSONGAME_API UClass* StaticClass<class ATopDownHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PersonGame_Source_PersonGame_TopDownHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
