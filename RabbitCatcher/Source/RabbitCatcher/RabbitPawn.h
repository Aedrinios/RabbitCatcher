	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RabbitMaterialsSelectorComponent.h"
#include "GameFramework/Pawn.h"
#include "RabbitPawn.generated.h"

UCLASS()
class RABBITCATCHER_API ARabbitPawn : public APawn
{
	GENERATED_BODY()
	/* The mesh component */
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* meshComponent;
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class URabbitComponent* rabbitComponent;
	UPROPERTY(Category = Mesh, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class URabbitMaterialsSelectorComponent* materialComponent;

public:
	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float MoveSpeed;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float RunSpeed;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float StaminaMax;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	float currentStamina;
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	bool refilledStamina;


	// Sets default values for this pawn's properties
	ARabbitPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
