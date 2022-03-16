// Fill out your copyright notice in the Description page of Project Settings.


#include "RabbitMaterialsSelectorComponent.h"

// Sets default values for this component's properties
URabbitMaterialsSelectorComponent::URabbitMaterialsSelectorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void URabbitMaterialsSelectorComponent::SetState(RabbitState state)
{
	this->CurrentState = state;	
}


// Called when the game starts
void URabbitMaterialsSelectorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URabbitMaterialsSelectorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UMaterialInterface* mat;
	switch (CurrentState) {
	case RabbitState::Run:
			mat = RunAwayMaterial;
			break;
		case RabbitState::Tired:
			currentTime += DeltaTime;
			if(currentTime > blinkSecond)
			{
				mat1 = !mat1;
				currentTime =0;
			}
			if(mat1)
				mat = TiredMaterial1;
			else
				mat = TiredMaterial2;
			break;
		case RabbitState::Wait:
		default:
			mat = DefaultMaterial;
			break;
	}
	UStaticMeshComponent* mesh = this->GetOwner()->FindComponentByClass<UStaticMeshComponent>();
	mesh->SetMaterial(0, mat);

	// ...
}

