// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PersonGame/TopDownHUD.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTopDownHUD() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AHUD();
ENGINE_API UClass* Z_Construct_UClass_UFont_NoRegister();
PERSONGAME_API UClass* Z_Construct_UClass_ATopDownHUD();
PERSONGAME_API UClass* Z_Construct_UClass_ATopDownHUD_NoRegister();
UPackage* Z_Construct_UPackage__Script_PersonGame();
// End Cross Module References

// Begin Class ATopDownHUD
void ATopDownHUD::StaticRegisterNativesATopDownHUD()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATopDownHUD);
UClass* Z_Construct_UClass_ATopDownHUD_NoRegister()
{
	return ATopDownHUD::StaticClass();
}
struct Z_Construct_UClass_ATopDownHUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "TopDownHUD.h" },
		{ "ModuleRelativePath", "TopDownHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDFont_MetaData[] = {
		{ "ModuleRelativePath", "TopDownHUD.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HUDFont;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATopDownHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATopDownHUD_Statics::NewProp_HUDFont = { "HUDFont", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATopDownHUD, HUDFont), Z_Construct_UClass_UFont_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDFont_MetaData), NewProp_HUDFont_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATopDownHUD_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATopDownHUD_Statics::NewProp_HUDFont,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownHUD_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ATopDownHUD_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHUD,
	(UObject* (*)())Z_Construct_UPackage__Script_PersonGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownHUD_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATopDownHUD_Statics::ClassParams = {
	&ATopDownHUD::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ATopDownHUD_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownHUD_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATopDownHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_ATopDownHUD_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATopDownHUD()
{
	if (!Z_Registration_Info_UClass_ATopDownHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATopDownHUD.OuterSingleton, Z_Construct_UClass_ATopDownHUD_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATopDownHUD.OuterSingleton;
}
template<> PERSONGAME_API UClass* StaticClass<ATopDownHUD>()
{
	return ATopDownHUD::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATopDownHUD);
ATopDownHUD::~ATopDownHUD() {}
// End Class ATopDownHUD

// Begin Registration
struct Z_CompiledInDeferFile_FID_PersonGame_Source_PersonGame_TopDownHUD_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATopDownHUD, ATopDownHUD::StaticClass, TEXT("ATopDownHUD"), &Z_Registration_Info_UClass_ATopDownHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATopDownHUD), 472982847U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PersonGame_Source_PersonGame_TopDownHUD_h_3561821763(TEXT("/Script/PersonGame"),
	Z_CompiledInDeferFile_FID_PersonGame_Source_PersonGame_TopDownHUD_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PersonGame_Source_PersonGame_TopDownHUD_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
