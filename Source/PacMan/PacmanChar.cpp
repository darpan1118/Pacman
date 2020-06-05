// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanChar.h"
#include "Components/InputComponent.h"
#include "GameFramework/DefaultPawn.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "PacmanController.h"

// Sets default values
APacmanChar::APacmanChar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Player = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PacmanMesh"));
	Player->SetupAttachment(RootComponent);

	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	PacmanSpeed = 150.f;
}

// Called when the game starts or when spawned
void APacmanChar::BeginPlay()
{
	Super::BeginPlay();
}

void APacmanChar::MoveForward(float Value)
{
	
	// Rotate pacman 
	if(Value > 0)
		SetActorRotation(FRotator(0, 0, 0));
	else if(Value < 0)
		SetActorRotation(FRotator(0, 180, 0));
}

void APacmanChar::MoveRight(float Value)
{
	if (Value > 0)
		SetActorRotation(FRotator(0, 90, 0));
	else if (Value < 0)
		SetActorRotation(FRotator(0, 270, 0));
}

// Called every frame
void APacmanChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*FVector NewLocation = GetActorLocation() + (GetActorForwardVector() * (PacmanSpeed * DeltaTime));
	SetActorLocation(NewLocation);*/
}

// Called to bind functionality to input
void APacmanChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APacmanChar::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APacmanChar::MoveRight);

}

