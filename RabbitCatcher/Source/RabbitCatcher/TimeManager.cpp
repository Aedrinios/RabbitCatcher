// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"
#include <limits>

#include "Kismet/GameplayStatics.h"

float ATimeManager::bestTime = std::numeric_limits<float>::max();


// Sets default values
ATimeManager::ATimeManager()
{
	win = false;
	timeElapsed = 0;
	bestTime = 0;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATimeManager::Tick(float DeltaTime)
{
	if(!win)
	{
		timeElapsed += DeltaTime;
	}
	else
	{
		if(timeElapsed < bestTime)
		{
			ATimeManager::bestTime = timeElapsed;
			UGameplayStatics::OpenLevel(GetWorld(), "Menu");

		}
	}	
}

std::string ATimeManager::GetBestTime()
{
	return std::to_string(bestTime);
}