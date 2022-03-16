// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "CatchingBox.generated.h"

/**
 * 
 */
UCLASS()
class RABBITCATCHER_API ACatchingBox : public ATriggerBox
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay();

public:
	ACatchingBox();
	UFUNCTION()
		void Event(class AActor* overlappedActor, class AActor* otherActor);
};
