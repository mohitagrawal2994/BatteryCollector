// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	//Base Decay Rate
	DecayRate = 0.01f;

	PrimaryActorTick.bCanEverTick = true;
}

void ABatteryCollectorGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Check we are using battery collecter character
	ABatteryCollectorCharacter* MyCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (MyCharacter)
	{
		//If our power is greater than power to win
		if (MyCharacter->GetCurrentPower() > PowerToWin)
		{
			SetCurrentState(EBatteryPlayState::EWon);
		}
		//if character power is positive
		else if (MyCharacter->GetCurrentPower() > 0)
		{
			//decrease the character power, delta time->if frame rate changes, initial power->to decrease a fraction of the power
			MyCharacter->UpdatePower((-DeltaTime)*DecayRate*(MyCharacter->GetInitialPower()));
		}
		else
			SetCurrentState(EBatteryPlayState::EGameOver);
	}
}

void ABatteryCollectorGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EBatteryPlayState::EPlaying);

	//Set The score to beat
	ABatteryCollectorCharacter* MyCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if(MyCharacter)
	{
		PowerToWin = (MyCharacter->GetInitialPower())*1.25f;
	}
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

float ABatteryCollectorGameMode::GetPowerToWin() const
{
	return PowerToWin;
}

EBatteryPlayState ABatteryCollectorGameMode::GetCurrentState() const
{
	return CurrentState;
}

void ABatteryCollectorGameMode::SetCurrentState(EBatteryPlayState NewState)
{
	CurrentState = NewState;
}
