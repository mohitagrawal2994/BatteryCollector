// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//All pickups start active
	bIsActive = true;

	//Create a static mesh component
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Returns active state of pickup
bool APickup::IsActive()
{
	return bIsActive;
}

//Changes the state of the pickup
void APickup::SetActive(bool NewPickupState)
{
	bIsActive = NewPickupState;
}

//Defines what happens after the pickup is collected
void APickup::WasCollected_Implementation()
{
	//Log a debug message
	FString PickupDebugString = GetName();
	UE_LOG(LogClass, Log, TEXT("You Have Collected %s"), *PickupDebugString);
}
