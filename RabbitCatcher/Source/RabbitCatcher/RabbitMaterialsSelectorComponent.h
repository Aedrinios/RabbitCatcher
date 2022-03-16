// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RabbitState.h"
#include "Components/ActorComponent.h"
#include "RabbitMaterialsSelectorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RABBITCATCHER_API URabbitMaterialsSelectorComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URabbitMaterialsSelectorComponent();
	void SetState(const RabbitState state);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	bool mat1;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere)
	RabbitState CurrentState = RabbitState::Wait;
	UPROPERTY(EditAnywhere)
	float blinkSecond = 0.5f;
	UPROPERTY(EditAnywhere)
	float currentTime = 0;
	UPROPERTY(EditAnywhere, Category="Materials")
	UMaterial* DefaultMaterial;
	UPROPERTY(EditAnywhere, Category="Materials")
	UMaterial* RunAwayMaterial;
	UPROPERTY(EditAnywhere, Category="Materials")
	UMaterial* TiredMaterial1;
	UPROPERTY(EditAnywhere, Category="Materials")
	UMaterial* TiredMaterial2;

		
};
