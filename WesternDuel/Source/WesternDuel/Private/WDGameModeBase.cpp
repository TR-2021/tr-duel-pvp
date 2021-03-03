// Fill out your copyright notice in the Description page of Project Settings.


#include "WDGameModeBase.h"
#include "WDGameStateBase.h"
#include "Character/WDPlayerController.h"
#include "Character/WD_BaseCharacter.h"
#include "Weapon/WDWeaponBase.h"
#include "UI/WDCrosshairActor.h"
#include "Kismet/GameplayStatics.h"



AWDGameModeBase::AWDGameModeBase() {
	PlayerControllerClass = AWDPlayerController::StaticClass();
	GameStateClass = AWDGameStateBase::StaticClass();
}


void AWDGameModeBase::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) {
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
}

void AWDGameModeBase::PostLogin(APlayerController* NewPlayer) {
	Super::PostLogin(NewPlayer);
	AWDPlayerController* NewPlayerController = Cast<AWDPlayerController>(NewPlayer);
	UE_LOG(LogTemp, Warning, TEXT("Pausing %s"),*NewPlayerController->GetName());
	SetPause(NewPlayerController);
	Players.Add(NewPlayerController);
	if (Players.Num() == MaxPlayers)
	{
		ClearPause();
	}
}

void AWDGameModeBase::Logout(AController* Exiting) {
	Super::Logout(Exiting);
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
			Player->UnPossess();
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
	RemoveAllActorsByClass<AWDCrosshairActor>();
}
