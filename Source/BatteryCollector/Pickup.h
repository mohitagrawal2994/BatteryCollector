// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//True When Pickup can be used and false when pickup is deactivated
	bool bIsActive;


public:	
	// Called every frame 
	virtual void Tick(float DeltaTime) override;

	//Returns the mesh for the pickup
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	//Returns the whether the pickup is active or not
	UFUNCTION(BlueprintPure, Category = "Pickup")
	bool IsActive();

	//Allows other classes to change the state of the pickup
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetActive(bool NewPickupState);

	//Function to call when the pickup is collected
	UFUNCTION(BlueprintNativeEvent)
	void WasCollected();
	virtual void WasCollected_Implementation();

private:
	//Static mesh to represent pickup in the level
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta=(AllowPrivateAccess = "true"))
	class UStaticMeshComponent* PickupMesh;
	
};
