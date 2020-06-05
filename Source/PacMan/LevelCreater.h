// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelCreater.generated.h"

UCLASS()
class PACMAN_API ALevelCreater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelCreater();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Variables")
	UTexture2D* LevelImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Variables")
	TSubclassOf<AActor> CubeClass;

	UFUNCTION(BlueprintCallable)
	void ReadPixelValues(UTexture2D* TextureToRead);

	UFUNCTION(BlueprintCallable)
	void CopyTextureToArray(UTexture2D *Texture, TArray<FColor> &Array);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
