// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "WDGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class WESTERNDUEL_API AWDGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(Replicated)
	int32 CurrentRound = 1;

	FTimerHandle Timer;


	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

public:
	int32 GetCurrentRound() { return CurrentRound; };
	
	UFUNCTION(Server, Reliable)
	void NextRound();
	
	UFUNCTION(Server, Reliable)
	void OnChangeRound();


};
