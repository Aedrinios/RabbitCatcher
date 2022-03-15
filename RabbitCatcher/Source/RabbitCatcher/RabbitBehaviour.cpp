// Fill out your copyright notice in the Description page of Project Settings.


#include "RabbitBehaviour.h"

// Sets default values
ARabbitBehaviour::ARabbitBehaviour()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BunnyMesh(TEXT("/Game/Meshes/Bunny.Bunny"));
	BunnyMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BunnyMesh"));
	RootComponent = BunnyMeshComponent;
	BunnyMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	BunnyMeshComponent->SetStaticMesh(BunnyMesh.Object);
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARabbitBehaviour::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARabbitBehaviour::Tick(float DeltaTime)
{
	// Find movement direction
	const float ForwardValue = 1;
	const float RightValue = 0;

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaTime;

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
void ARabbitBehaviour::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

