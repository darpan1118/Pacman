// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PacmanController.generated.h"

/**
 * 
 */
UCLASS()
class PACMAN_API APacmanController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Packman)
		AActor* PacmanCam;*/

protected:
	virtual void BeginPlay() override;
};
