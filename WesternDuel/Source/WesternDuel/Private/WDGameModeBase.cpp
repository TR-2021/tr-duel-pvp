// Fill out your copyright notice in the Description page of Project Settings.


#include "WDGameModeBase.h"
#include "WDGameStateBase.h"
#include "Character/WDPlayerController.h"
#include "Character/WDGamePlayerState.h"
#include "Character/WD_BaseCharacter.h"
#include "Weapon/WDWeaponBase.h"
#include "UI/WDCrosshairActor.h"
#include "UI/WDGameHUD.h"
#include "Multiplayer/WDPlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"



AWDGameModeBase::AWDGameModeBase() 
{
	PlayerControllerClass = AWDPlayerController::StaticClass();
	GameStateClass = AWDGameStateBase::StaticClass();
	HUDClass = AWDGameHUD::StaticClass();
	PlayerStateClass = AWDGamePlayerState::StaticClass();
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
/*
*  Track new logged in PlayerController
*/
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

void AWDGameModeBase::StartPlay()
{
	Super::StartPlay();
}

/*
* Befor restarting round, we should free all PlayerStart
* NextRound - indicate which PlayerStart's we should use for spawning
*/
void AWDGameModeBase::RestartRound(int NextRound)
{
	CurrentRound = NextRound;
	UWorld* World = GetWorld();
	for (TActorIterator<AWDPlayerStart> It(World); It; ++It)
	{
		AWDPlayerStart* PlayerStart = *It;
		PlayerStart->SetOccupition(false);
	}
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
///*
//* Almost the same as Parent Class, 
//* Just instead of looking for APlayerStart we look for AWDPlayerStart
//*/
//AActor* AWDGameModeBase::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
//{
//	return Super::FindPlayerStart_Implementation(Player, IncomingName);
//	UWorld* World = GetWorld();
//
//	AActor* BestStart = nullptr; //ChoosePlayerStart(Player);
//	for (TActorIterator<AWDPlayerStart> It(World); It; ++It)
//	{
//		AWDPlayerStart* PlayerStart = *It;
//		
//		UE_LOG(LogTemp, Warning, TEXT("current round %d - Start round %d - occup[ied %d"), CurrentRound, PlayerStart->GetRoundNumber(), PlayerStart->IsOccupied()?1:0);
//		if (PlayerStart->GetRoundNumber() == CurrentRound && !PlayerStart->IsOccupied())
//		{
//			PlayerStart->SetOccupition(true);
//			BestStart = PlayerStart;
//			break;
//		}
//	}
//
//	if (BestStart == nullptr)
//	{
//		BestStart = Super::FindPlayerStart_Implementation(Player, IncomingName);
//	}
//
//	return BestStart;
//}

/*
* Remove all bodies and weapons
*/
void AWDGameModeBase::ClearWorld() 
{
	RemoveAllActorsByClass<AWD_BaseCharacter>();
	RemoveAllActorsByClass<AWDWeaponBase>();
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