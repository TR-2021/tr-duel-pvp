// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/WDMainMenuPlayerController.h"


void AWDMainMenuPlayerController::BeginPlay() {
	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
};
