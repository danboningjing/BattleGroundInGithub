// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (ensure(PlayerTank))
	{
		//Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm or m

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	
		// Fire if ready
		ControlledTank->Fire();//TODO lingt firing rate
	}
}

//ATank* ATankAIController::GetControlledTank() const
//{
//	return Cast<ATank>(GetPawn());
//}
//
//ATank* ATankAIController::GetPlayerTank() const
//{
//	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
//	if (!PlayerPawn) { return nullptr; } // Note the !, very important
//	return Cast<ATank>(PlayerPawn);
//}
//have already made these inline
