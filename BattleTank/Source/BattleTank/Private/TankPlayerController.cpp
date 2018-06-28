// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Core/Public/Math/Vector.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	CheckControlledTank();
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrossHair();

}

void ATankPlayerController::CheckControlledTank()
{
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("User Not Controlling Tank")); 
	} else { UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing: %s"), *ControlledTank->GetName()); }
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewPortSizeX;
	int32 ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);

	return true;
}
