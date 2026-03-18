// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PersonGamePlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PERSONGAME_PersonGamePlayerController_generated_h
#error "PersonGamePlayerController.generated.h already included, missing '#pragma once' in PersonGamePlayerController.h"
#endif
#define PERSONGAME_PersonGamePlayerController_generated_h

#define FID_PersonGame_Source_PersonGame_PersonGamePlayerController_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPersonGamePlayerController(); \
	friend struct Z_Construct_UClass_APersonGamePlayerController_Statics; \
public: \
	DECLARE_CLASS(APersonGamePlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PersonGame"), NO_API) \
	DECLARE_SERIALIZER(APersonGamePlayerController)


#define FID_PersonGame_Source_PersonGame_PersonGamePlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APersonGamePlayerController(APersonGamePlayerController&&); \
	APersonGamePlayerController(const APersonGamePlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APersonGamePlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APersonGamePlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APersonGamePlayerController) \
	NO_API virtual ~APersonGamePlayerController();


#define FID_PersonGame_Source_PersonGame_PersonGamePlayerController_h_16_PROLOG
#define FID_PersonGame_Source_PersonGame_PersonGamePlayerController_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PersonGame_Source_PersonGame_PersonGamePlayerController_h_19_INCLASS_NO_PURE_DECLS \
	FID_PersonGame_Source_PersonGame_PersonGamePlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PERSONGAME_API UClass* StaticClass<class APersonGamePlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PersonGame_Source_PersonGame_PersonGamePlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
