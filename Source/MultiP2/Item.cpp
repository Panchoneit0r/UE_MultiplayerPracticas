// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "MultiP2Character.h"
#include "Components/SphereComponent.h"
// Sets default values
AItem::AItem()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
	SphereComp->SetupAttachment(MeshComp);

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	AMultiP2Character* MyCharacter = Cast<AMultiP2Character>(OtherActor);

	if(MyCharacter)
	{
		MyCharacter->bIsCarryingItem = true;
		Destroy();
	}
}

