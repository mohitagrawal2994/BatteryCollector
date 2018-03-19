// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

//enum to store current state of the gameplay
UENUM(BlueprintType)
enum class EBatteryPlayState:uint8
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	//Returns the power to win needed for the HUD
	UFUNCTION(BlueprintPure, Category="Power")
	float GetPowerToWin() const ;

	//returns the current playing state
	UFUNCTION(BlueprintPure, Category="Power")
	EBatteryPlayState GetCurrentState() const;

	//sets the new playing state
	void SetCurrentState(EBatteryPlayState NewState);

protected:
	//The rate at which the character loses the power
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta=(BlueprintProtected="true"))
	float DecayRate;

	//The Power To Win
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	float PowerToWin;

	//WIdget class to use for HUD screeen
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	//Actual Instance
	UPROPERTY()
	class UUserWidget* CurrentWidget;

private:
	//Keeps Track of the current playing State
	EBatteryPlayState CurrentState;

	TArray<class ASpawnVolume*> SpawnVolumeActors;
};



