// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WDGameModeBase.generated.h"

/**
 * 
 */
class AWDPlayerController;
class AWD_BaseCharacter;
UCLASS()
class WESTERNDUEL_API AWDGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:
	TArray<AWDPlayerController*> Players;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AWD_BaseCharacter>> PlayerPawns;
	
	UPROPERTY(EditDefaultsOnly)
	int32 TotalNumberOfRounds = 3;

	UPROPERTY(EditDefaultsOnly)
	int32 CurrentRound = 0;

	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void Logout(AController* Exiting) ;

	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;
public:
	AWDGameModeBase();
	
};
