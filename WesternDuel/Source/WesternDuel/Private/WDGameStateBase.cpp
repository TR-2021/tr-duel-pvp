// Fill out your copyright notice in the Description page of Project Settings.


#include "WDGameStateBase.h"
#include "WDGameModeBase.h"
#include "Net/Unrealnetwork.h"

void AWDGameStateBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWDGameStateBase, CurrentRound);
	DOREPLIFETIME(AWDGameStateBase, bIsGameOver);
	DOREPLIFETIME(AWDGameStateBase, EmptyPlayersCount);
}


void AWDGameStateBase::NextRound_Implementation()
{
	EndRound();
	GetWorld()->GetTimerManager().SetTimer(Timer,this,&AWDGameStateBase::OnChangeRound, DelayOnEndRound, false);
}


void AWDGameStateBase::NotifyEmpty_Implementation()
{
	if (!GetWorld()) return;

	auto CurrentGameMode = GetWorld()->GetAuthGameMode<AWDGameModeBase>();
	if (!CurrentGameMode) return;

	EmptyPlayersCount++;

	if (EmptyPlayersCount >= CurrentGameMode->GetMaxPlayers())
	{
		GetWorld()->GetTimerManager().SetTimer(Timer,[&]() {
				NextRound();
		}, DelayOnEmpty, false);
	}
}



void AWDGameStateBase::OnChangeRound_Implementation()
{

	if (!GetWorld()) return;

	auto CurrentGameMode = GetWorld()->GetAuthGameMode<AWDGameModeBase>();
	if (!CurrentGameMode) return;

	CurrentRound++;
	EmptyPlayersCount = 0;			// All Players have bullets at start of round
	OnRep_RoundChanged();			// Call implicitly to trigger event on Server
	if (CurrentRound > CurrentGameMode->GetMaxRounds())
	{
		bIsGameOver = true;
		OnRep_GameOver();			// Call implicitly to trigger event on Server
	}
	else
	{
		CurrentGameMode->RestartRound(CurrentRound);
	}
}

void AWDGameStateBase::OnRep_RoundChanged()
{
	OnRoundChanged.Broadcast();
	StartRound();
}

void AWDGameStateBase::OnRep_GameOver()
{
	OnGameOver.Broadcast();
}


void AWDGameStateBase::StartRound_Implementation()
{
	GetWorld()->GetTimerManager().SetTimer(Timer, 
	[&]() {
		OnRoundStart.Broadcast();
	}, DelayOnStartRound, false);
}

void AWDGameStateBase::EndRound_Implementation()
{
	OnRoundEnd.Broadcast();
}
