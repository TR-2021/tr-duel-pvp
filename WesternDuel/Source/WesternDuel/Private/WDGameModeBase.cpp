// Fill out your copyright notice in the Description page of Project Settings.


#include "WDGameModeBase.h"
#include "Character/WDPlayerController.h"

AWDGameModeBase::AWDGameModeBase() {
	PlayerControllerClass = AWDPlayerController::StaticClass();
}


