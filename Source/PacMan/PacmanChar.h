// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"
#include "PacmanChar.generated.h"

UCLASS()
class PACMAN_API APacmanChar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APacmanChar();


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Player;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	// Input variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Packman)
	float PacmanSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Packman)
	AActor* PacmanCam;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
