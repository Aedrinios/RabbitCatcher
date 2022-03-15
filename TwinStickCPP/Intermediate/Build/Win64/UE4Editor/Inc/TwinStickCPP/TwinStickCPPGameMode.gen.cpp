// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TwinStickCPP/TwinStickCPPGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTwinStickCPPGameMode() {}
// Cross Module References
	TWINSTICKCPP_API UClass* Z_Construct_UClass_ATwinStickCPPGameMode_NoRegister();
	TWINSTICKCPP_API UClass* Z_Construct_UClass_ATwinStickCPPGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_TwinStickCPP();
// End Cross Module References
	void ATwinStickCPPGameMode::StaticRegisterNativesATwinStickCPPGameMode()
	{
	}
	UClass* Z_Construct_UClass_ATwinStickCPPGameMode_NoRegister()
	{
		return ATwinStickCPPGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATwinStickCPPGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATwinStickCPPGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TwinStickCPP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATwinStickCPPGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "TwinStickCPPGameMode.h" },
		{ "ModuleRelativePath", "TwinStickCPPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATwinStickCPPGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATwinStickCPPGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATwinStickCPPGameMode_Statics::ClassParams = {
		&ATwinStickCPPGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATwinStickCPPGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ATwinStickCPPGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATwinStickCPPGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATwinStickCPPGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATwinStickCPPGameMode, 49610674);
	template<> TWINSTICKCPP_API UClass* StaticClass<ATwinStickCPPGameMode>()
	{
		return ATwinStickCPPGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATwinStickCPPGameMode(Z_Construct_UClass_ATwinStickCPPGameMode, &ATwinStickCPPGameMode::StaticClass, TEXT("/Script/TwinStickCPP"), TEXT("ATwinStickCPPGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATwinStickCPPGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
