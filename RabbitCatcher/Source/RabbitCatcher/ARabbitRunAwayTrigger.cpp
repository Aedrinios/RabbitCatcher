// Fill out your copyright notice in the Description page of Project Settings.


#include "ARabbitRunAwayTrigger.h"

ARabbitRunAwayTrigger::ARabbitRunAwayTrigger() {
    OnActorBeginOverlap.AddDynamic(this, &ARabbitRunAwayTrigger::Event);
}

void ARabbitRunAwayTrigger::BeginPlay() {
    Super::BeginPlay();
}

void ARabbitRunAwayTrigger::Event(class AActor* overlappedActor, class AActor* otherActor) {
    if (otherActor && otherActor != this) {
        if (ball) {
            ball->FindComponentByClass<UStaticMeshComponent>()
                ->SetSimulatePhysics(true);
        }
    }
}