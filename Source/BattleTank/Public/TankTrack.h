// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximun driving force ,and to apply forces  to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Sets a throttle between -1 to +1
	UFUNCTION(BlueprintCallable,Category=Input)
	void SetThrottle(float Throttle);
	
	//TODO clamp actual throttle value so player cannot over-drive
	
};
