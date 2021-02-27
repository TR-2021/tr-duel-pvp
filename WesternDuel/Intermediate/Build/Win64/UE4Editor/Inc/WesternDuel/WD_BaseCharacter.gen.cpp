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
// End Cross Module References
	void AWD_BaseCharacter::StaticRegisterNativesAWD_BaseCharacter()
	{
	}
	UClass* Z_Construct_UClass_AWD_BaseCharacter_NoRegister()
	{
		return AWD_BaseCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AWD_BaseCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWD_BaseCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_WesternDuel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWD_BaseCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Character/WD_BaseCharacter.h" },
		{ "ModuleRelativePath", "Public/Character/WD_BaseCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWD_BaseCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWD_BaseCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWD_BaseCharacter_Statics::ClassParams = {
		&AWD_BaseCharacter::StaticClass,
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
	IMPLEMENT_CLASS(AWD_BaseCharacter, 2753578504);
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
