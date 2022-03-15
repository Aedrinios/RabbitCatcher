// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "RabbitComponent.h"
#include "Math/Vector.h"

// Sets default values for this component's properties
URabbitComponent::URabbitComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URabbitComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...

}


// Called every frame
void URabbitComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector CharacterLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	FVector vOrigin = this->GetOwner()->GetTransform().GetTranslation();
	//FVector vDestinaton = this->player->GetOwner()->GetTransform().GetTranslation();
	if (FVector::Dist(vOrigin, CharacterLocation) <= this->minDistanceToRunAwayFromPlayer) {
		DrawDebugLine(GetWorld(), vOrigin, CharacterLocation, FColor::Red);
	}
	else {
		DrawDebugLine(GetWorld(), vOrigin, CharacterLocation, FColor::Green);
	}


	// ...
}

