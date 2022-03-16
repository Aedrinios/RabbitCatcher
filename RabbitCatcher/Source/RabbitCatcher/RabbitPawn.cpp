// Fill out your copyright notice in the Description page of Project Settings.


#include "RabbitPawn.h"

#include "RabbitComponent.h"
#include "ThirdParty/openexr/Deploy/OpenEXR-2.3.0/OpenEXR/include/ImathFun.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ARabbitPawn::ARabbitPawn()
{
	StaminaMax = 10;
	MoveSpeed  = 500;
	RunSpeed = 1000;
	
	//Begin : Add Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BunnyMesh(TEXT("/Game/Meshes/Bunny.Bunny"));
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BunnyMesh"));
	RootComponent = meshComponent;
	meshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	meshComponent->SetStaticMesh(BunnyMesh.Object);

	//End : Add Mesh
	//Begin : Add RabbitComponent
	rabbitComponent = CreateDefaultSubobject<URabbitComponent>(TEXT("RabbitComponent"));
	rabbitComponent->SetupAttachment(RootComponent);
	//End : Add RabbitComponent

	//Begin : Add Material Selector Component
	materialComponent = CreateDefaultSubobject<URabbitMaterialsSelectorComponent>(TEXT("RabbitMaterial"));
	materialComponent->SetupAttachment(RootComponent);
	//End : Add Material Selector Component

	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARabbitPawn::BeginPlay()
{
	currentStamina = StaminaMax;
	refilledStamina = true;
	Super::BeginPlay();
}

// Called every frame
void ARabbitPawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = 1;
	const float RightValue = 0;

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	FVector Movement = FVector(0, 0, 0);
	// Calculate  movement
	materialComponent = this->FindComponentByClass<URabbitMaterialsSelectorComponent>();

	FVector MoveDirection;

	if (rabbitComponent->GetRunAway())
	{
		MoveDirection = rabbitComponent->GetPlayerDirectionNormalize();
		MoveDirection.Z = 0;
		if (this->currentStamina > 0 && refilledStamina)
		{
			materialComponent->SetState(RabbitState::Run);
			currentStamina = FMath::Clamp(currentStamina, 0.0f, currentStamina - DeltaSeconds);
			Movement = MoveDirection * RunSpeed * DeltaSeconds;
		}
		else
		{
			materialComponent->SetState(RabbitState::Tired);
			refilledStamina = false;
			Movement = MoveDirection * MoveSpeed * DeltaSeconds;
		}
	}
	else
	{
		materialComponent->SetState(RabbitState::Wait);
		Movement = FVector(0, 0, 0);
		currentStamina = FMath::Clamp(currentStamina, currentStamina + DeltaSeconds, StaminaMax);
		if (currentStamina >= StaminaMax)
		{
			refilledStamina = true;
		}
	}

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
}

// Called to bind functionality to input
void ARabbitPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
