// Fill out your copyright notice in the Description page of Project Settings.


#include "RabbitMaterialsSelectorComponent.h"

// Sets default values for this component's properties
URabbitMaterialsSelectorComponent::URabbitMaterialsSelectorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	static ConstructorHelpers::FObjectFinder<UMaterial> default(TEXT("/Game/Materials/RabbitMat.RabbitMat"));
	DefaultMaterial =  default.Object;
	static ConstructorHelpers::FObjectFinder<UMaterial> runAway(TEXT("/Game/Materials/RabbitRunAwayMat.RabbitRunAwayMat"));
	RunAwayMaterial = runAway.Object;
	static ConstructorHelpers::FObjectFinder<UMaterial> tired1(TEXT("/Game/Materials/RabbitTired1Mat.RabbitTired1Mat"));
	TiredMaterial1 =  tired1.Object;
	static ConstructorHelpers::FObjectFinder<UMaterial> tired2(TEXT("/Game/Materials/RabbitTired2Mat.RabbitTired2Mat"));
	TiredMaterial2 =  tired2.Object;



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
void URabbitMaterialsSelectorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UMaterialInterface* mat;
	switch (CurrentState)
	{
	case RabbitState::Run:
		mat = RunAwayMaterial;
		break;
	case RabbitState::Tired:
		currentTime += DeltaTime;
		if (currentTime > blinkSecond)
		{
			mat1 = !mat1;
			currentTime = 0;
		}
		if (mat1)
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
