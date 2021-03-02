// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WDPlayerController.h"

AWDPlayerController::AWDPlayerController() {
	bReplicates = true;
}



void AWDPlayerController::BeginPlay() 
{
	SetInputMode(FInputModeGameOnly());
	UGameViewportClient* ViewportClient = GetWorld()->GetGameViewport();
	ViewportClient->RemoveAllViewportWidgets();
};
