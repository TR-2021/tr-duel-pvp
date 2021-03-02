// Fill out your copyright notice in the Description page of Project Settings.


#include "WDGameModeBase.h"
#include "Character/WDPlayerController.h"
#include "Character/WD_BaseCharacter.h"



AWDGameModeBase::AWDGameModeBase() {
	PlayerControllerClass = AWDPlayerController::StaticClass();
}

void AWDGameModeBase::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) {
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
}

void AWDGameModeBase::PostLogin(APlayerController* NewPlayer) {
	Super::PostLogin(NewPlayer);
	AWDPlayerController* NewPlayerController = Cast<AWDPlayerController>(NewPlayer);
	Players.Add(NewPlayerController);
	
	
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
