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

	UPROPERTY(EditDefaultsOnly)
	int32 MaxPlayers = 2;
	
	UPROPERTY(EditDefaultsOnly)
	int32 MaxRounds = 3;
	
	int32 CurrentRound = 1;

	TArray<AWDPlayerController*> Players;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AWD_BaseCharacter>> PlayerPawns;

	virtual void StartPlay() override;
	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void HandleSeamlessTravelPlayer(AController*& C) override;

	virtual void Logout(AController* Exiting);
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	//virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName) override;

	// Delete Unpossessed Pawn and Its guns
	UFUNCTION()
	void ClearWorld();
	
	UFUNCTION()
	void HandleNewPLayer(APlayerController* NewPlayer);


	template <class T >
	void RemoveAllActorsByClass();
public:
	AWDGameModeBase();

	int32 GetMaxRounds() { return MaxRounds; }
	int32 GetMaxPlayers() { return MaxPlayers; }
	void RestartRound(int32 NextRound);
};

template<class T>
void AWDGameModeBase::RemoveAllActorsByClass()
{
		TArray<AActor*> ActorList;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), T::StaticClass(), ActorList);
		for (auto Actor : ActorList)
		{
			Actor->Destroy();
		}
}
