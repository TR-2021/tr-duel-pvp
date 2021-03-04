// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WDGameHUD.h"
#include "UI/WDGameOverWidget.h"
#include "UI/WDRoundResultWidget.h"
#include "Character/WDGamePlayerState.h"
#include "Kismet/GameplayStatics.h"



void AWDGameHUD::BeginPlay()
{
	Super::BeginPlay();
	if (RoundResultWidgetClass)
	{
		RoundResultWidget = CreateWidget<UWDRoundResultWidget>(GetWorld(), RoundResultWidgetClass);
		if (RoundResultWidget) RoundResultWidget->AddToViewport();
	}

	if (GameOverWidgetClass)
	{
		GameOverWidget = CreateWidget<UWDGameOverWidget>(GetWorld(), GameOverWidgetClass);
		if (GameOverWidget) GameOverWidget->AddToViewport();
	}

	HideAll();
}



void AWDGameHUD::UpdatePlayerInfo()
{
	auto LocalController = Cast<AController>(GetOwner());
	if (LocalController)
	{
		auto PlayerState = Cast< AWDGamePlayerState>(LocalController->PlayerState);
		if (PlayerState)
		{
			GameOverWidget->SetKills(PlayerState->GetKills());
			GameOverWidget->SetDeaths(PlayerState->GetDeaths());
		}
	}
}


void AWDGameHUD::ShowGameOverMenu()
{
	if (RoundResultWidget)
	{
		RoundResultWidget->SetVisibility(ESlateVisibility::Hidden);
	}
	if (GameOverWidget)
	{
		UpdatePlayerInfo();
		GameOverWidget->SetVisibility(ESlateVisibility::Visible);
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