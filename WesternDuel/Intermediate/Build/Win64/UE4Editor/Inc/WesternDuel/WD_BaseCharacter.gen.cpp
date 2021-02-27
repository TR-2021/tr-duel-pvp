// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WesternDuel/Public/Character/WD_BaseCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWD_BaseCharacter() {}
// Cross Module References
	WESTERNDUEL_API UClass* Z_Construct_UClass_AWD_BaseCharacter_NoRegister();
	WESTERNDUEL_API UClass* Z_Construct_UClass_AWD_BaseCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_WesternDuel();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AWD_BaseCharacter::execIsAim)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsAim();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWD_BaseCharacter::execHasGunTaken)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasGunTaken();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWD_BaseCharacter::execGetMovementDirection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMovementDirection();
		P_NATIVE_END;
	}
	void AWD_BaseCharacter::StaticRegisterNativesAWD_BaseCharacter()
	{
		UClass* Class = AWD_BaseCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetMovementDirection", &AWD_BaseCharacter::execGetMovementDirection },
			{ "HasGunTaken", &AWD_BaseCharacter::execHasGunTaken },
			{ "IsAim", &AWD_BaseCharacter::execIsAim },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics
	{
		struct WD_BaseCharacter_eventGetMovementDirection_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WD_BaseCharacter_eventGetMovementDirection_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWD_BaseCharacter, nullptr, "GetMovementDirection", nullptr, nullptr, sizeof(WD_BaseCharacter_eventGetMovementDirection_Parms), Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics
	{
		struct WD_BaseCharacter_eventHasGunTaken_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WD_BaseCharacter_eventHasGunTaken_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(WD_BaseCharacter_eventHasGunTaken_Parms), &Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWD_BaseCharacter, nullptr, "HasGunTaken", nullptr, nullptr, sizeof(WD_BaseCharacter_eventHasGunTaken_Parms), Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics
	{
		struct WD_BaseCharacter_eventIsAim_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WD_BaseCharacter_eventIsAim_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(WD_BaseCharacter_eventIsAim_Parms), &Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWD_BaseCharacter, nullptr, "IsAim", nullptr, nullptr, sizeof(WD_BaseCharacter_eventIsAim_Parms), Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWD_BaseCharacter_IsAim()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWD_BaseCharacter_IsAim_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AWD_BaseCharacter_NoRegister()
	{
		return AWD_BaseCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AWD_BaseCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringArmComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringArmComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MovementComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MovementComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GunIsTaken_MetaData[];
#endif
		static void NewProp_GunIsTaken_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_GunIsTaken;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsAiming_MetaData[];
#endif
		static void NewProp_IsAiming_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsAiming;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWD_BaseCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_WesternDuel,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AWD_BaseCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AWD_BaseCharacter_GetMovementDirection, "GetMovementDirection" }, // 1183329718
		{ &Z_Construct_UFunction_AWD_BaseCharacter_HasGunTaken, "HasGunTaken" }, // 2712425628
		{ &Z_Construct_UFunction_AWD_BaseCharacter_IsAim, "IsAim" }, // 2664273516
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWD_BaseCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/WD_BaseCharacter.h" },
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_SpringArmComponent_MetaData[] = {
		{ "Category", "Player" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_SpringArmComponent = { "SpringArmComponent", nullptr, (EPropertyFlags)0x0020080000090009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWD_BaseCharacter, SpringArmComponent), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_SpringArmComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_SpringArmComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_CameraComponent_MetaData[] = {
		{ "Category", "Player" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_CameraComponent = { "CameraComponent", nullptr, (EPropertyFlags)0x0020080000090009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWD_BaseCharacter, CameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_CameraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_CameraComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_MovementComponent_MetaData[] = {
		{ "Category", "Player" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_MovementComponent = { "MovementComponent", nullptr, (EPropertyFlags)0x0020080000090009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWD_BaseCharacter, MovementComponent), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_MovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_MovementComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_GunIsTaken_MetaData[] = {
		{ "Category", "Player" },
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_GunIsTaken_SetBit(void* Obj)
	{
		((AWD_BaseCharacter*)Obj)->GunIsTaken = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_GunIsTaken = { "GunIsTaken", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWD_BaseCharacter), &Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_GunIsTaken_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_GunIsTaken_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_GunIsTaken_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_IsAiming_MetaData[] = {
		{ "Category", "Player" },
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_IsAiming_SetBit(void* Obj)
	{
		((AWD_BaseCharacter*)Obj)->IsAiming = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_IsAiming = { "IsAiming", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AWD_BaseCharacter), &Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_IsAiming_SetBit, METADATA_PARAMS(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_IsAiming_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_IsAiming_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWD_BaseCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_SpringArmComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_CameraComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_MovementComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_GunIsTaken,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWD_BaseCharacter_Statics::NewProp_IsAiming,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWD_BaseCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWD_BaseCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWD_BaseCharacter_Statics::ClassParams = {
		&AWD_BaseCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AWD_BaseCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AWD_BaseCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AWD_BaseCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWD_BaseCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWD_BaseCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWD_BaseCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWD_BaseCharacter, 3675834770);
	template<> WESTERNDUEL_API UClass* StaticClass<AWD_BaseCharacter>()
	{
		return AWD_BaseCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWD_BaseCharacter(Z_Construct_UClass_AWD_BaseCharacter, &AWD_BaseCharacter::StaticClass, TEXT("/Script/WesternDuel"), TEXT("AWD_BaseCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWD_BaseCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
