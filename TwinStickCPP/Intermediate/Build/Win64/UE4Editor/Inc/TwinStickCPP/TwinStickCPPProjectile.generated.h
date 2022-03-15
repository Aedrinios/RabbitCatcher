// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef TWINSTICKCPP_TwinStickCPPProjectile_generated_h
#error "TwinStickCPPProjectile.generated.h already included, missing '#pragma once' in TwinStickCPPProjectile.h"
#endif
#define TWINSTICKCPP_TwinStickCPPProjectile_generated_h

#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_SPARSE_DATA
#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATwinStickCPPProjectile(); \
	friend struct Z_Construct_UClass_ATwinStickCPPProjectile_Statics; \
public: \
	DECLARE_CLASS(ATwinStickCPPProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwinStickCPP"), NO_API) \
	DECLARE_SERIALIZER(ATwinStickCPPProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesATwinStickCPPProjectile(); \
	friend struct Z_Construct_UClass_ATwinStickCPPProjectile_Statics; \
public: \
	DECLARE_CLASS(ATwinStickCPPProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TwinStickCPP"), NO_API) \
	DECLARE_SERIALIZER(ATwinStickCPPProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATwinStickCPPProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATwinStickCPPProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATwinStickCPPProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATwinStickCPPProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATwinStickCPPProjectile(ATwinStickCPPProjectile&&); \
	NO_API ATwinStickCPPProjectile(const ATwinStickCPPProjectile&); \
public:


#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATwinStickCPPProjectile(ATwinStickCPPProjectile&&); \
	NO_API ATwinStickCPPProjectile(const ATwinStickCPPProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATwinStickCPPProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATwinStickCPPProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATwinStickCPPProjectile)


#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileMesh() { return STRUCT_OFFSET(ATwinStickCPPProjectile, ProjectileMesh); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(ATwinStickCPPProjectile, ProjectileMovement); }


#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_12_PROLOG
#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_SPARSE_DATA \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_RPC_WRAPPERS \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_INCLASS \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_SPARSE_DATA \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_INCLASS_NO_PURE_DECLS \
	TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TWINSTICKCPP_API UClass* StaticClass<class ATwinStickCPPProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TwinStickCPP_Source_TwinStickCPP_TwinStickCPPProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
