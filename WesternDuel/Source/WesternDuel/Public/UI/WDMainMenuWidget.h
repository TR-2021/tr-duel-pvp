// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WDMainMenuWidget.generated.h"

/**
 * 
 */
class UButton;
class UWidgetSwitcher;

UENUM()
enum class EMainMenuAction : uint8 {
	NONE,
	HOST_GAME,
	JOIN_GAME  ,
	MAX	
};
UCLASS()
class WESTERNDUEL_API UWDMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;
 
	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SubmitName;
	
	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* LayoutSwitcher;


	EMainMenuAction MenuAction = EMainMenuAction::NONE;

	virtual void NativeOnInitialized() override;
private:
	UFUNCTION()
	void OnHostGame();

	UFUNCTION()
	void OnJoinGame();

	UFUNCTION()
	void OnSubmitName();


	UFUNCTION()
	void HostGame();
};
