// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WESTERNDUEL_WD_BaseCharacter_generated_h
#error "WD_BaseCharacter.generated.h already included, missing '#pragma once' in WD_BaseCharacter.h"
#endif
#define WESTERNDUEL_WD_BaseCharacter_generated_h

#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_SPARSE_DATA
#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsAim); \
	DECLARE_FUNCTION(execHasGunTaken); \
	DECLARE_FUNCTION(execGetMovementDirection);


#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsAim); \
	DECLARE_FUNCTION(execHasGunTaken); \
	DECLARE_FUNCTION(execGetMovementDirection);


#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWD_BaseCharacter(); \
	friend struct Z_Construct_UClass_AWD_BaseCharacter_Statics; \
public: \
	DECLARE_CLASS(AWD_BaseCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WesternDuel"), NO_API) \
	DECLARE_SERIALIZER(AWD_BaseCharacter)


#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAWD_BaseCharacter(); \
	friend struct Z_Construct_UClass_AWD_BaseCharacter_Statics; \
public: \
	DECLARE_CLASS(AWD_BaseCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WesternDuel"), NO_API) \
	DECLARE_SERIALIZER(AWD_BaseCharacter)


#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWD_BaseCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWD_BaseCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWD_BaseCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWD_BaseCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWD_BaseCharacter(AWD_BaseCharacter&&); \
	NO_API AWD_BaseCharacter(const AWD_BaseCharacter&); \
public:


#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWD_BaseCharacter(AWD_BaseCharacter&&); \
	NO_API AWD_BaseCharacter(const AWD_BaseCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWD_BaseCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWD_BaseCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWD_BaseCharacter)


#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SpringArmComponent() { return STRUCT_OFFSET(AWD_BaseCharacter, SpringArmComponent); } \
	FORCEINLINE static uint32 __PPO__CameraComponent() { return STRUCT_OFFSET(AWD_BaseCharacter, CameraComponent); } \
	FORCEINLINE static uint32 __PPO__MovementComponent() { return STRUCT_OFFSET(AWD_BaseCharacter, MovementComponent); } \
	FORCEINLINE static uint32 __PPO__GunIsTaken() { return STRUCT_OFFSET(AWD_BaseCharacter, GunIsTaken); } \
	FORCEINLINE static uint32 __PPO__IsAiming() { return STRUCT_OFFSET(AWD_BaseCharacter, IsAiming); }


#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_12_PROLOG
#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_SPARSE_DATA \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_RPC_WRAPPERS \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_INCLASS \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_PRIVATE_PROPERTY_OFFSET \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_SPARSE_DATA \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_INCLASS_NO_PURE_DECLS \
	WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WESTERNDUEL_API UClass* StaticClass<class AWD_BaseCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WesternDuel_Source_WesternDuel_Public_Character_WD_BaseCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
