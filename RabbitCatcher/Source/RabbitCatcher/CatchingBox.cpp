// Fill out your copyright notice in the Description page of Project Settings.


#include "CatchingBox.h"

#include <string>

#include "TimeManager.h"
#include "Kismet/GameplayStatics.h"

ACatchingBox::ACatchingBox()
{
	rabbitCatched = 0;
	rabbitToCatch = 3;
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
			rabbitCatched++;
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(rabbitCatched));
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::FromInt(rabbitToCatch));
			if (rabbitCatched == rabbitToCatch)
			{
				UGameplayStatics::OpenLevel(GetWorld(), "Menu");

				UWorld* world = GetWorld();
				for (TObjectIterator<ATimeManager> It; It; ++It)
				{
					ATimeManager* timer = *It;
					if (timer->GetWorld() == world)
					{
						GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "SALUT LES POTES");
						timer->win = true;
					}
				}
			}
			otherActor->Destroy();
		}
	}
}
