// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

bool UMainMenuWidget::Initialize()
{
	UE_LOG(LogTemp, Warning, TEXT("In Initialize Block"));

	Super::Initialize();

	if (MessageTextBlock == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("No textblock class found"));
		return false;
	}

	MessageTextBlock->SetText(FText::FromString("Hello this is a change from c++"));

	if (ToggleButton == nullptr) return false;

	ToggleButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnToggleButtonClicked);

	return true;
}

void UMainMenuWidget::OnToggleButtonClicked()
{
	if (MessageTextBlock == nullptr) return;

	if (bShow)
	{
		MessageTextBlock->SetVisibility(ESlateVisibility::Hidden);
		bShow = false;
	}
	else
	{
		MessageTextBlock->SetVisibility(ESlateVisibility::Visible);
		bShow = true;
	}
}
