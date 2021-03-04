// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "WDGameHUD.generated.h"

/**
 * 
 */
class UWDGameOverWidget;
class UWDRoundResultWidget;
UCLASS()
class WESTERNDUEL_API AWDGameHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> RoundResultWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> GameOverWidgetClass;

private:

	UPROPERTY()
	UWDRoundResultWidget* RoundResultWidget;

	UPROPERTY()
	UWDGameOverWidget* GameOverWidget;


public:
	UFUNCTION()
	void UpdatePlayerInfo();
	
	UFUNCTION()
	void ShowGameOverMenu();

	UFUNCTION()
	void ShowRoundResultMenu();
	void HideAll();

};
