// Fill out your copyright notice in the Description page of Project Settings.


#include "CatchingBox.h"

ACatchingBox::ACatchingBox()
{
	OnActorBeginOverlap.AddDynamic(this, &ACatchingBox::Event);
}

void ACatchingBox::BeginPlay()
{
	Super::BeginPlay();
}

void ACatchingBox::Event(class AActor* overlappedActor, class AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		if (otherActor->Tags.Contains(TEXT("Rabbit")))
		{
			otherActor->Destroy();	
		}
	}
}
