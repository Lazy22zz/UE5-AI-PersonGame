// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PersonGameCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PERSONGAME_PersonGameCharacter_generated_h
#error "PersonGameCharacter.generated.h already included, missing '#pragma once' in PersonGameCharacter.h"
#endif
#define PERSONGAME_PersonGameCharacter_generated_h

#define FID_PersonGame_Source_PersonGame_PersonGameCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPersonGameCharacter(); \
	friend struct Z_Construct_UClass_APersonGameCharacter_Statics; \
public: \
	DECLARE_CLASS(APersonGameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PersonGame"), NO_API) \
	DECLARE_SERIALIZER(APersonGameCharacter)


#define FID_PersonGame_Source_PersonGame_PersonGameCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APersonGameCharacter(APersonGameCharacter&&); \
	APersonGameCharacter(const APersonGameCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APersonGameCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APersonGameCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APersonGameCharacter) \
	NO_API virtual ~APersonGameCharacter();


#define FID_PersonGame_Source_PersonGame_PersonGameCharacter_h_9_PROLOG
#define FID_PersonGame_Source_PersonGame_PersonGameCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PersonGame_Source_PersonGame_PersonGameCharacter_h_12_INCLASS_NO_PURE_DECLS \
	FID_PersonGame_Source_PersonGame_PersonGameCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PERSONGAME_API UClass* StaticClass<class APersonGameCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PersonGame_Source_PersonGame_PersonGameCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
