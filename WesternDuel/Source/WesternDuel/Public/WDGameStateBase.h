// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "WDGameStateBase.generated.h"

/**
 * 
 */
DECLARE_MULTICAST_DELEGATE(FGameStateEventSignature)
UCLASS()
class WESTERNDUEL_API AWDGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(ReplicatedUsing=OnRep_RoundChanged)
	int32 CurrentRound = 1;

	UPROPERTY(ReplicatedUsing=OnRep_GameOver)
	bool bIsGameOver = false;

	FTimerHandle Timer;
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;
	
	UFUNCTION()
	void OnRep_RoundChanged();
	
	UFUNCTION()
	void OnRep_GameOver();

public:
	FGameStateEventSignature OnRoundStart;		// Called when players can shoot
	FGameStateEventSignature OnRoundEnd;		// Called when Someone died
	FGameStateEventSignature OnRoundChanged;	// Called After End and before Start
	FGameStateEventSignature OnGameOver;
	
	int32 GetCurrentRound() { return CurrentRound; };
	
	UFUNCTION(Server, Reliable)
	void NextRound();
	
	UFUNCTION(NetMulticast, Reliable)
	void OnChangeRound();

	UFUNCTION(NetMulticast, Reliable)
	void StartRound();

	UFUNCTION(NetMulticast, Reliable)
	void EndRound();


};
