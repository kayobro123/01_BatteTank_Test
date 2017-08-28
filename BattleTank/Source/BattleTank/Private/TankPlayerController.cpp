// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	/*Auto is visible only within the function it is declared and its lifetime is same as the lifetime of the function as well.
	Once the execution of function is finished, the variable is destroyed.*/

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is pessessing %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

//ATank gets input from TankPlayerController (AI or Player). But to do that we need to cast it in TankPlayerController. We control the pawn from the controller

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayhitLocation(HitLocation)) //Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());

		//TODO Tell controlled tank to aim at this point
	}
}

//Get World location of linetrace through crosshair, true if its landscape
bool ATankPlayerController::GetSightRayhitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);

	return true;
}
