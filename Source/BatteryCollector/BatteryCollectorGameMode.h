// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

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
};



