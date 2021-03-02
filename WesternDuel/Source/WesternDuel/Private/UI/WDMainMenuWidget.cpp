// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WDMainMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "WDGameInstance.h"


void UWDMainMenuWidget::NativeOnInitialized() 
 {
	Super::NativeOnInitialized();
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
	UE_LOG(LogTemp, Display, TEXT("HOST"));
	
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

	if (GameInstance->IsNameEmpty()) {
		MenuAction = EMainMenuAction::JOIN_GAME;
		LayoutSwitcher->SetActiveWidgetIndex(LayoutSwitcher->GetActiveWidgetIndex() + 1);
	}
	else {
		// JOIN
	}
}

void UWDMainMenuWidget::HostGame() {
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UWDMainMenuWidget::OnSubmitName() 
{

}