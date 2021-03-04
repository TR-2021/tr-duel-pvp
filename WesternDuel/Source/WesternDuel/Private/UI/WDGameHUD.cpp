// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WDGameHUD.h"
#include "UI/WDGameOverWidget.h"
#include "UI/WDRoundResultWidget.h"



void AWDGameHUD::BeginPlay()
{
	Super::BeginPlay();
	if (RoundResultWidgetClass)
	{

		RoundResultWidget = CreateWidget<UWDRoundResultWidget>(GetWorld(), RoundResultWidgetClass);
		if (RoundResultWidget) RoundResultWidget->AddToViewport();
		FString s = "I Am " + FString::FromInt(GetLocalRole()) + " RoundWidget created";
		UE_LOG(LogTemp, Warning, TEXT("%s"), *s);
	}

	if (GameOverWidgetClass)
	{

		GameOverWidget = CreateWidget<UWDGameOverWidget>(GetWorld(), GameOverWidgetClass);
		if (GameOverWidget) GameOverWidget->AddToViewport();
		FString s = "I Am " + FString::FromInt(GetLocalRole()) + " GAMEOVer created";
		UE_LOG(LogTemp, Warning, TEXT("%s"), *s);
	}

	HideAll();
}



void AWDGameHUD::UpdatePlayerInfo()
{
	
}


void AWDGameHUD::ShowGameOverMenu()
{
	if (RoundResultWidget)
	{
		RoundResultWidget->SetVisibility(ESlateVisibility::Hidden);
		UE_LOG(LogTemp, Warning, TEXT("Round Hidden"));

	}
	if (GameOverWidget)
	{
		GameOverWidget->SetVisibility(ESlateVisibility::Visible);
		UE_LOG(LogTemp, Warning, TEXT("GameOVer Shown"));

	}
}

void AWDGameHUD::ShowRoundResultMenu()
{
	if (RoundResultWidget)
	{
		RoundResultWidget->SetVisibility(ESlateVisibility::Visible);
	}
	if (GameOverWidget)
	{
		GameOverWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}


void AWDGameHUD::HideAll()
{
	if (RoundResultWidget)
	{
		RoundResultWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	if (GameOverWidget)
	{
		GameOverWidget->SetVisibility(ESlateVisibility::Hidden);
	}
}