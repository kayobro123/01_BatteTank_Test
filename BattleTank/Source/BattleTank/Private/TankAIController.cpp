// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*Auto is visible only within the function it is declared and its lifetime is same as the lifetime of the function as well.
	Once the execution of function is finished, the variable is destroyed.*/

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController is pessessing %s"), *(ControlledTank->GetName()));
	}
}

// ATank gets input from TankPlayerController (AI or Player). But to do that we need to cast it in TankPlayerController. We control the pawn from the controller

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}