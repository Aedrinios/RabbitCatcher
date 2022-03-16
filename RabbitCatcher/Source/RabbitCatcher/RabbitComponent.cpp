// Fill out your copyright notice in the Description page of Project Settings.

#include "RabbitComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Math/Vector.h"

// Sets default values for this component's properties
URabbitComponent::URabbitComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

bool URabbitComponent::GetRunAway()
{
	return this->runAway;
}

FVector URabbitComponent::GetPlayerDirectionNormalize()
{
	FVector v = playerDirection;
	v.Normalize();
	return v;
}


// Called when the game starts
void URabbitComponent::BeginPlay()	
{
	Super::BeginPlay();
	// ...
}


// Called every frame
void URabbitComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	this->CheckPlayerDistance();

	// ...
}

void URabbitComponent::CheckPlayerDistance()
{
	APlayerController* pc = GetWorld()->GetFirstPlayerController();
	//Get location of playerpawn
	FVector playerLocation = pc->GetPawn()->GetActorLocation();
	//Get selft location
	FVector selfLocation = this->GetOwner()->GetTransform().GetTranslation();
	this->distanceFromPlayer = FVector::Dist(selfLocation, playerLocation);
	this->playerDirection = selfLocation - playerLocation;
	if (this->distanceFromPlayer <= this->distanceDetectPlayer)
	{
		FHitResult OutHit;

		FCollisionQueryParams CollisionParms;
		CollisionParms.AddIgnoredActor(this->GetOwner());
		
		bool isHit = GetWorld()->LineTraceSingleByChannel(OutHit,
														selfLocation,
														playerLocation,
														ECC_Camera,
														CollisionParms,
														FCollisionResponseParams::DefaultResponseParam);
		this->runAway = isHit && OutHit.GetActor()->Tags.Contains(TEXT("Player")); 
		if (runAway)
		{
			DrawDebugLine(GetWorld(), selfLocation, playerLocation, FColor::Red);
		}
		else
		{
			DrawDebugLine(GetWorld(), selfLocation, playerLocation, FColor::Green);
		}
	}
	else
	{
		runAway = false;
		//DrawDebugLine(GetWorld(), selfLocation, playerLocation, FColor::Blue);
	}
}
