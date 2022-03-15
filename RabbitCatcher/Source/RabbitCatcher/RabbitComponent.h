// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "RabbitComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RABBITCATCHER_API URabbitComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URabbitComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	float runSince = 0;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
		float maxSpeed = 10;

	UPROPERTY(EditAnywhere)
		float outStaminaFactorSpeed= 0.5;
	UPROPERTY(EditAnywhere)
		float minDistanceToRunAwayFromPlayer = 200;
	UPROPERTY(EditAnywhere)
		float staminaTime = 10;

};
