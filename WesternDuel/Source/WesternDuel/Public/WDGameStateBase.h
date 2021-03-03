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
	FGameStateEventSignature OnRoundChanged;
	FGameStateEventSignature OnGameOver;
	
	int32 GetCurrentRound() { return CurrentRound; };
	
	UFUNCTION(Server, Reliable)
	void NextRound();
	
	UFUNCTION(Server, Reliable)
	void OnChangeRound();

};
