// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EnemyCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef PERSONGAME_EnemyCharacter_generated_h
#error "EnemyCharacter.generated.h already included, missing '#pragma once' in EnemyCharacter.h"
#endif
#define PERSONGAME_EnemyCharacter_generated_h

#define FID_PersonGame_Source_PersonGame_EnemyCharacter_h_17_DELEGATE \
PERSONGAME_API void FOnEnemyDied_DelegateWrapper(const FMulticastScriptDelegate& OnEnemyDied, int32 Score);


#define FID_PersonGame_Source_PersonGame_EnemyCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnBodyOverlap);


#define FID_PersonGame_Source_PersonGame_EnemyCharacter_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemyCharacter(); \
	friend struct Z_Construct_UClass_AEnemyCharacter_Statics; \
public: \
	DECLARE_CLASS(AEnemyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PersonGame"), NO_API) \
	DECLARE_SERIALIZER(AEnemyCharacter)


#define FID_PersonGame_Source_PersonGame_EnemyCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEnemyCharacter(AEnemyCharacter&&); \
	AEnemyCharacter(const AEnemyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemyCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemyCharacter) \
	NO_API virtual ~AEnemyCharacter();


#define FID_PersonGame_Source_PersonGame_EnemyCharacter_h_19_PROLOG
#define FID_PersonGame_Source_PersonGame_EnemyCharacter_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PersonGame_Source_PersonGame_EnemyCharacter_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PersonGame_Source_PersonGame_EnemyCharacter_h_22_INCLASS_NO_PURE_DECLS \
	FID_PersonGame_Source_PersonGame_EnemyCharacter_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PERSONGAME_API UClass* StaticClass<class AEnemyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PersonGame_Source_PersonGame_EnemyCharacter_h


#define FOREACH_ENUM_EENEMYTYPE(op) \
	op(EEnemyType::Small) \
	op(EEnemyType::Medium) \
	op(EEnemyType::Large) 

enum class EEnemyType : uint8;
template<> struct TIsUEnumClass<EEnemyType> { enum { Value = true }; };
template<> PERSONGAME_API UEnum* StaticEnum<EEnemyType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
