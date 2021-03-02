// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "WDGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WESTERNDUEL_API UWDGameInstance : public UGameInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	FString PlayerName = "";

public:
		
	UFUNCTION()
	bool IsNameEmpty() { return  PlayerName.Len() == 0; };
 
	UFUNCTION()
	FString GetPlayerName() { return PlayerName; };

	UFUNCTION()
	void SetPlayerName(FString Name) { PlayerName = Name; };

};
