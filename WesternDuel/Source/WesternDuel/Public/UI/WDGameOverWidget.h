// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WDGameOverWidget.generated.h"

/**
 * 
 */

class UTextBlock;

UCLASS()
class WESTERNDUEL_API UWDGameOverWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* KillsTextBox;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DeathsTextBox;

public:
	void SetKills(int32 Kills);
	void SetDeaths(int32 Deaths);
};
