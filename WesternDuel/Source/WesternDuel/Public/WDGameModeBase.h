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

	int32 MaxPlayers = 2;
	int32 MaxRounds = 3;

	TArray<AWDPlayerController*> Players;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<AWD_BaseCharacter>> PlayerPawns;

	UPROPERTY(EditDefaultsOnly)
	int32 CurrentRound = 0;

	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void HandleSeamlessTravelPlayer(AController*& C) override;

	virtual void Logout(AController* Exiting);
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

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
	void RestartRound();
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
