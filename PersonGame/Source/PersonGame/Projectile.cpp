// GeoSiege - Player Projectile

#include "Projectile.h"
#include "EnemyCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "Engine/DamageEvents.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	Speed = 1400.f;
	Damage = 1.0f;
	Lifetime = 2.2f;
	AliveTime = 0.f;
	bHit = false;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->InitSphereRadius(10.f);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComp->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(CollisionComp);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetRelativeScale3D(FVector(0.2f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (SphereMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(SphereMesh.Object);
	}
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	CollisionComp->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnBeginOverlap);

	UMaterialInterface* BaseMat = Cast<UMaterialInterface>(StaticLoadObject(
		UMaterialInterface::StaticClass(), nullptr,
		TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial")));

	if (BaseMat)
	{
		UMaterialInstanceDynamic* DynMat = UMaterialInstanceDynamic::Create(BaseMat, this);
		DynMat->SetVectorParameterValue(TEXT("Color"), FLinearColor(1.f, 0.95f, 0.1f));
		MeshComp->SetMaterial(0, DynMat);
	}
}

void AProjectile::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bHit) return;

	AliveTime += DeltaSeconds;
	if (AliveTime >= Lifetime)
	{
		Destroy();
		return;
	}

	FVector NewLocation = GetActorLocation() + MoveDirection * Speed * DeltaSeconds;
	FHitResult Hit;
	SetActorLocation(NewLocation, true, &Hit);
	if (Hit.bBlockingHit)
	{
		bHit = true;
		Destroy();
	}
}

void AProjectile::Launch(FVector InDirection)
{
	MoveDirection = InDirection.GetSafeNormal();
	SetActorRotation(MoveDirection.Rotation());
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!bHit)
	{
		bHit = true;
		Destroy();
	}
}

void AProjectile::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (bHit) return;

	AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(OtherActor);
	if (Enemy && Enemy->IsAlive())
	{
		FDamageEvent DamageEvent;
		Enemy->TakeDamage(Damage, DamageEvent, nullptr, this);
		bHit = true;
		Destroy();
	}
}
