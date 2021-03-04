// Fill out your copyright notice in the Description page of Project Settings.


#include "WDGameModeBase.h"
#include "WDGameStateBase.h"
#include "Character/WDPlayerController.h"
#include "Character/WD_BaseCharacter.h"
#include "Weapon/WDWeaponBase.h"
#include "UI/WDCrosshairActor.h"
#include "UI/WDGameHUD.h"
#include "Kismet/GameplayStatics.h"



AWDGameModeBase::AWDGameModeBase() 
{
	PlayerControllerClass = AWDPlayerController::StaticClass();
	GameStateClass = AWDGameStateBase::StaticClass();
	HUDClass = AWDGameHUD::StaticClass();
}


void AWDGameModeBase::PostLogin(APlayerController* NewPlayer) {
	Super::PostLogin(NewPlayer);
	HandleNewPLayer(NewPlayer);
}

void AWDGameModeBase::HandleSeamlessTravelPlayer(AController*& NewPlayer)
{
	Super::HandleSeamlessTravelPlayer(NewPlayer);
	auto NewPlayerControler = Cast<APlayerController>(NewPlayer);
	if (!NewPlayerControler) return;

	HandleNewPLayer(NewPlayerControler);
}

void AWDGameModeBase::HandleNewPLayer(APlayerController* NewPlayer)
{
	AWDPlayerController* NewPlayerController = Cast<AWDPlayerController>(NewPlayer);
	if (!NewPlayerController) return;

	SetPause(NewPlayerController);
	Players.Add(NewPlayerController);
	if (Players.Num() == MaxPlayers)
	{
		ClearPause();
		auto CurrentGameState = GetWorld()->GetGameState<AWDGameStateBase>();
		if (!CurrentGameState) return;
		CurrentGameState->StartRound();
	}
}
void AWDGameModeBase::Logout(AController* Exiting) {
	Super::Logout(Exiting);
	AWDPlayerController* NewPlayerController = Cast<AWDPlayerController>(Exiting);
	if (!NewPlayerController) return;

	Players.Remove(NewPlayerController);
	Exiting->Destroy();
}



UClass* AWDGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	// TODO Implement different Pawn for AIControllers
	return Super::GetDefaultPawnClassForController_Implementation(InController);

}

void AWDGameModeBase::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);

}

void AWDGameModeBase::RestartRound()
{
	for (auto Player : Players)
	{
		if (Player && Player->GetPawn())
		{
			Player->GetPawn()->Reset();
		}
	}
	ClearWorld();
	for (auto Player : Players)
	{
		RestartPlayer(Player);
	}

}

void AWDGameModeBase::ClearWorld() 
{
	RemoveAllActorsByClass<AWD_BaseCharacter>();
	RemoveAllActorsByClass<AWDWeaponBase>();
}
