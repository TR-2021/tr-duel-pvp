// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WDPlayerController.h"
#include "WDGameStateBase.h"

AWDPlayerController::AWDPlayerController() 
{
	bReplicates = true;
}

void AWDPlayerController::BeginPlay() 
{
	SetInputMode(FInputModeGameOnly());
	UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
	ViewportClient->RemoveAllViewportWidgets();

	auto GameState = GetWorld()->GetGameState<AWDGameStateBase>();
	if (GameState && IsLocalController())
	{
		GameState->OnRoundChanged.AddUObject(this, &AWDPlayerController::OnRestartRound);
		GameState->OnGameOver.AddUObject(this, &AWDPlayerController::OnGameOver);
	}
};


void AWDPlayerController::OnRestartRound()
{
	UE_LOG(LogTemp, Warning, TEXT("Round Changed"));
}


void AWDPlayerController::OnGameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Over"));
}