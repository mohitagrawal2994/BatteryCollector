// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryPickup.h"
#include "Components/StaticMeshComponent.h"

ABatteryPickup::ABatteryPickup()
{
	GetMesh()->SetSimulatePhysics(true);
	BatteryPower = 150.0f;
}

void ABatteryPickup::WasCollected_Implementation()
{
	//Use base Pickup behaviour
	Super::WasCollected_Implementation();

	//Destroy The Battery
	Destroy();
}

//Reports back the power level of the battery 
float ABatteryPickup::GetPower()
{
	return BatteryPower;
}
