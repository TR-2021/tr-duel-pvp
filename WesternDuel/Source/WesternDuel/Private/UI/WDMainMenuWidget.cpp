// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WDMainMenuWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/WidgetSwitcher.h"
#include "WDGameInstance.h"


void UWDMainMenuWidget::NativeOnInitialized() 
 {
	Super::NativeOnInitialized();
	if (LayoutSwitcher) {
		LayoutSwitcher->SetActiveWidgetIndex(0);
	}
	if (HostButton) {
		HostButton->OnClicked.AddDynamic(this, &UWDMainMenuWidget::OnHostGame);
	}
	if (JoinButton) {
		JoinButton->OnClicked.AddDynamic(this, &UWDMainMenuWidget::OnJoinGame);
	}
	if (SubmitName) {
		SubmitName->OnClicked.AddDynamic(this, &UWDMainMenuWidget::OnSubmitName);
	}
}

void UWDMainMenuWidget::OnHostGame()
{	
	UWDGameInstance* GameInstance = GetGameInstance<UWDGameInstance>();
	if (!GameInstance) return;

	if (GameInstance->IsNameEmpty()) {
		MenuAction = EMainMenuAction::HOST_GAME;
		LayoutSwitcher->SetActiveWidgetIndex(LayoutSwitcher->GetActiveWidgetIndex() + 1);
	}
	else {
		HostGame();
	}
}

void UWDMainMenuWidget::OnJoinGame()
{
	UWDGameInstance* GameInstance = GetGameInstance<UWDGameInstance>();
	if (!GameInstance) return;

	if (GameInstance->IsNameEmpty()) 
	{
		MenuAction = EMainMenuAction::JOIN_GAME;
		LayoutSwitcher->SetActiveWidgetIndex(LayoutSwitcher->GetActiveWidgetIndex() + 1);
	}
	else {
		JoinGame();
	}
}

void UWDMainMenuWidget::HostGame() 
{
	auto GameInstace = GetGameInstance<UWDGameInstance>();
	if (!GameInstace) return;
	
	GameInstace->Host(FName("Session"+GameInstace->GetPlayerName()));

}
void UWDMainMenuWidget::JoinGame() 
{
	OnJoinRequest.Broadcast();	// Signal for HUD to change Widget 
}
void UWDMainMenuWidget::OnSubmitName() 
{
	UWDGameInstance* GameInstance = GetGameInstance<UWDGameInstance>();
	if (!GameInstance) return;
	
	if (NameTextBox->GetText().IsEmpty())
		return;
	GameInstance->SetPlayerName(NameTextBox->GetText().ToUpper().ToString());
	switch (MenuAction)
	{
		case EMainMenuAction::HOST_GAME:HostGame(); break;
		case EMainMenuAction::JOIN_GAME:JoinGame(); break;
	}
}