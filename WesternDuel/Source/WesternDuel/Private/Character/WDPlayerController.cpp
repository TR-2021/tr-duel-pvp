// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WDPlayerController.h"
#include "Character/WD_BaseCharacter.h"
#include "UI/WDGameHUD.h"
#include "WDGameStateBase.h"

AWDPlayerController::AWDPlayerController() 
{
	bReplicates = true;
}

void AWDPlayerController::BeginPlay() 
{
	Super::BeginPlay();
	SetInputMode(FInputModeGameOnly());
	if (!GetWorld()) return;


	auto CurrentGameState = GetWorld()->GetGameState<AWDGameStateBase>();
	if (CurrentGameState)
	{
		CurrentGameState->OnRoundStart.AddUObject(this, &AWDPlayerController::OnStartRound);
		CurrentGameState->OnRoundChanged.AddUObject(this, &AWDPlayerController::OnRestartRound);
		CurrentGameState->OnRoundEnd.AddUObject(this, &AWDPlayerController::OnEndRound);
		CurrentGameState->OnGameOver.AddUObject(this, &AWDPlayerController::OnGameOver);
	}
};

void AWDPlayerController::OnRestartRound()
{
	
	auto GameHUD = GetHUD<AWDGameHUD>();
	if (!GameHUD) return;

	UE_LOG(LogTemp, Warning, TEXT("Round Changed"));
	GameHUD->HideAll();
}
void AWDPlayerController::OnStartRound()
{
	auto ControllingPawn = GetPawn<AWD_BaseCharacter>();
	if (!ControllingPawn) return;

	ControllingPawn->Server_SetCanAim(true);
}
void AWDPlayerController::OnEndRound()
{

	auto GameHUD = GetHUD<AWDGameHUD>();
	if (!GameHUD) return;

	UE_LOG(LogTemp, Warning, TEXT("Round End"));
	GameHUD->ShowRoundResultMenu();
}

void AWDPlayerController::OnGameOver()
{
	auto GameHUD = GetHUD<AWDGameHUD>();
	if (!GameHUD) return;

	UE_LOG(LogTemp, Warning, TEXT("Game Over"));
	GameHUD->ShowGameOverMenu();

	DisableInput(this);
	SetInputMode(FInputModeUIOnly());
}