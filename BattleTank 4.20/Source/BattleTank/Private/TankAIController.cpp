// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	CheckAIControlledTank();
	CheckPlayerPawn();

}

void ATankAIController::CheckPlayerPawn()
{
	auto PlayerTank = GetPlayerControlledTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI has not located player tank"));
	}
	else { UE_LOG(LogTemp, Warning, TEXT("AI has located: %s"), *PlayerTank->GetName()); }
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

ATank* ATankAIController::GetPlayerControlledTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

