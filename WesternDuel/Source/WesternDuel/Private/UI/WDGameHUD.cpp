// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WDGameHUD.h"
#include "UI/WDGameOverWidget.h"
#include "UI/WDRoundResultWidget.h"
#include "UI/WDGamePauseWidget.h"
#include "Components/Button.h"
#include "WDGameModeBase.h"
#include "Character/WDPlayerController.h"

#include "Character/WDGamePlayerState.h"
#include "Kismet/GameplayStatics.h"



void AWDGameHUD::BeginPlay()
{
	Super::BeginPlay();
	HUDWidgetMap.Add(EHUDState::ROUND_END, CreateWidget<UWDRoundResultWidget>(GetWorld(), RoundResultWidgetClass));
	HUDWidgetMap.Add(EHUDState::GAMEOVER, CreateWidget<UWDGameOverWidget>(GetWorld(), GameOverWidgetClass));
	auto PauseWidget = CreateWidget<UWDGamePauseWidget>(GetWorld(), PauseWidgetClass);
	if (PauseWidget)
	{
		PauseWidget->MenuGameButton->OnClicked.AddDynamic(this, &AWDGameHUD::OnMainMenuClicked);
		PauseWidget->BackGameButton->OnClicked.AddDynamic(this, &AWDGameHUD::OnBackClicked);
	}
	HUDWidgetMap.Add(EHUDState::PAUSE, PauseWidget);
	InitAll();
	SetState(EHUDState::NONE);
}


void AWDGameHUD::SetState(EHUDState State)
{
	HUDState = State;
	switch (State)
	{
	case EHUDState::NONE:
		HideAll();
		break;
	case EHUDState::GAMEOVER:
		UpdatePlayerInfo();
	default:
		SetStateVisibility(State);
		break;
	}
	SetStateVisibility(State);
}

void AWDGameHUD::OnMainMenuClicked()
{
	auto GameMode = GetWorld()->GetAuthGameMode<AWDGameModeBase>();
	if (GameMode)
	{
		GameMode->FinishGame();
	}
	else 
	{
		auto LocalController = Cast<AWDPlayerController>(GetOwner());
		if (LocalController)
		{
			LocalController->Disconnect();
		}
	}
}

void AWDGameHUD::OnBackClicked()
{
	SetState(EHUDState::NONE);
}
void AWDGameHUD::UpdatePlayerInfo()
{
	auto LocalController = Cast<AController>(GetOwner());
	if (LocalController)
	{
		auto PlayerState = Cast< AWDGamePlayerState>(LocalController->PlayerState);
		if (PlayerState)
		{
			auto GameOverWidget = Cast< UWDGameOverWidget>(HUDWidgetMap[EHUDState::GAMEOVER]);
			if (GameOverWidget)
			{
				GameOverWidget->SetKills(PlayerState->GetKills());
				GameOverWidget->SetDeaths(PlayerState->GetDeaths());
			}
		}
	}
}

void AWDGameHUD::SetStateVisibility(EHUDState State)
{
	if (HUDWidgetMap.Contains(State))
	{
		UUserWidget* Widget = HUDWidgetMap[State];
		if (Widget)
		{
			HideAll();
			Widget->SetVisibility(ESlateVisibility::Visible);
		}
	}
}


void AWDGameHUD::InitAll()
{
	for (auto MapPair : HUDWidgetMap)
	{
		UUserWidget* Widget = MapPair.Value;
		if (Widget)
		{
			Widget->AddToViewport();
		}
	}
}

void AWDGameHUD::HideAll()
{
	for (auto MapPair : HUDWidgetMap)
	{
		UUserWidget* Widget = MapPair.Value;
		if (Widget)
		{
			Widget->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}