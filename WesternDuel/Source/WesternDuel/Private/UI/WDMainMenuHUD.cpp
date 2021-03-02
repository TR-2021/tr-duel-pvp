// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WDMainMenuHUD.h"
#include "Blueprint/UserWidget.h"

void AWDMainMenuHUD::BeginPlay() {
	Super::BeginPlay();
	if (MenuWidgetClass) {
		auto MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
		MenuWidget->AddToViewport();
	}
}