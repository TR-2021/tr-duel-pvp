// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WDMainMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/WDMainMenuWidget.h"
#include "UI/WDLobbySearchWidget.h"

void AWDMainMenuHUD::BeginPlay() {
	Super::BeginPlay();
	if (MenuWidgetClass) {
		auto MenuWidget = Cast<UWDMainMenuWidget>(CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass));
		MenuWidget->OnJoinRequest.AddUObject(this, &AWDMainMenuHUD::OnJoinRequest);
		MenuWidget->AddToViewport();
	}
}


void AWDMainMenuHUD::OnJoinRequest() {
	if (LobbySearchWidgetClass) {
		auto LobbyWidget = Cast<UWDLobbySearchWidget>(CreateWidget<UUserWidget>(GetWorld(), LobbySearchWidgetClass));
		LobbyWidget->AddToViewport();
	}
}