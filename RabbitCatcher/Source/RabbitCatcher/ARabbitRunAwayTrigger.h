// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/TriggerSphere.h"
#include "Engine/TriggerSphere.h"
#include "ARabbitRunAwayTrigger.generated.h"

/**
 * 
 */
UCLASS()
class RABBITCATCHER_API ARabbitRunAwayTrigger : public ATriggerSphere
{
	GENERATED_BODY()
protected:
    virtual void BeginPlay();

public:
    ARabbitRunAwayTrigger();
    UFUNCTION()
        void Event(class AActor* overlappedActor, class AActor* otherActor);

    UPROPERTY(EditAnywhere)
        AActor* ball;
};
