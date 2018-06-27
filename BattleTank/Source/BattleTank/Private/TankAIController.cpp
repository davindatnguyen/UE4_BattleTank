// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	CheckAIControlledTank();
}

void ATankAIController::CheckAIControlledTank()
{
	auto AIControlledTank = GetAIControlledTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Not Possessing Tank"));
	}
	else { UE_LOG(LogTemp, Warning, TEXT("AIController Possessing: %s"), *AIControlledTank->GetName()); }
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

