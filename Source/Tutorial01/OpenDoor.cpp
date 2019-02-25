// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	this->Owner = GetOwner();
	this->ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (this->PressurePlate->IsOverlappingActor(this->ActorThatOpens))
	{
		OpenDoor();
		this->LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - this->LastDoorOpenTime > this->DoorCloseDelay)
	{
		CloseDoor();
	}

}

void UOpenDoor::OpenDoor()
{
	this->Owner->SetActorRotation(FRotator(0.f, this->OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor()
{
	this->Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));

}

