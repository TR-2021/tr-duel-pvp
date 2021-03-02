// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSubSystem.h"

#include "WDGameInstance.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FSessionFoundSignature,TArray<FOnlineSessionSearchResult>&)

UCLASS()
class WESTERNDUEL_API UWDGameInstance : public UGameInstance
{
	GENERATED_BODY()
protected:
	virtual void Init();

	UPROPERTY()
	FString PlayerName = "";
	
	IOnlineSessionPtr SessionInterface;
	
	TSharedPtr<class FOnlineSessionSearch> SessionSearch;
	
	void CreateSession(FName SessionName);
	void OnSessionCreated(FName Name, bool Success);
	void OnSessionDestroyed(FName Name, bool Success);
	void OnSessionSearchComplete(bool Success);
	void OnJoinComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Type);
	
public:
	FSessionFoundSignature OnSessionFoundEvent;

	UFUNCTION()
	bool IsNameEmpty() { return  PlayerName.Len() == 0; };
 
	UFUNCTION()
	FString GetPlayerName() { return PlayerName; };

	UFUNCTION()
	void SetPlayerName(FString Name) { PlayerName = Name; };

	UFUNCTION()
	void Host(FName SessionName);
	
	UFUNCTION()
	void RequestSearchSession();

	UFUNCTION()
	void Join(uint32 Index);
private:

	FString LobbyLevel = "/Game/Levels/Lobby/Lobby?listen";
};