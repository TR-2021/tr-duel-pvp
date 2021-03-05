// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WDGamePauseWidget.h"
#include "Components/Button.h"
#include "WDGameModeBase.h"

void UWDGamePauseWidget::NativeOnInitialized()
{
	/*if (MenuGameButton)
	{
		MenuGameButton->OnClicked.AddDynamic(this, &UWDGamePauseWidget::OnMenuButtonPressed);
	}
	if (MenuGameButton)
	{
		BackGameButton->OnClicked.AddDynamic(this, &UWDGamePauseWidget::OnBackButtonPressed);
	}*/
}


void UWDGamePauseWidget::OnMenuButtonPressed()
{
	auto GameMode = GetWorld()->GetAuthGameMode<AWDGameModeBase>();
	if (GameMode)
	{
		GameMode->FinishGame();
	}
	else
	{
		// Just exit
	}
}


void UWDGamePauseWidget::OnBackButtonPressed()
{

}