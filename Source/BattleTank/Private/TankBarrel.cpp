// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,1);
	UE_LOG(LogTemp, Warning, TEXT("Rotator.Pitch: %f"),RelativeSpeed);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation,MinElevationDegrees,MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation,0,0));
}

