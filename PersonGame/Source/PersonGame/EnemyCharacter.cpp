// GeoSiege - Enemy Character

#include "EnemyCharacter.h"
#include "PersonGameCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/DamageEvents.h"

AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	bDying = false;
	ContactDamageTimer = 0.f;

	// Movement setup
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 720.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Hide default skeletal mesh
	GetMesh()->SetHiddenInGame(true);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Visual body mesh — centred on the capsule so it aligns with the collision volume
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	BodyMesh->SetupAttachment(GetCapsuleComponent());
	BodyMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	BodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Default stats
	MaxHealth = 2.0f;
	CurrentHealth = MaxHealth;
	MoveSpeed = 300.f;
	ContactDamage = 1.0f;
	ScoreValue = 10;
	EnemyType = EEnemyType::Small;

	// Capsule collision: overlap pawns so enemies walk through each other
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	ApplyEnemyVisuals();
	GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::OnBodyOverlap);
}

void AEnemyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bDying) return;

	if (ContactDamageTimer > 0.f)
	{
		ContactDamageTimer -= DeltaSeconds;
	}

	// Chase the player
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC && PC->GetPawn())
	{
		FVector Direction = (PC->GetPawn()->GetActorLocation() - GetActorLocation()).GetSafeNormal2D();
		AddMovementInput(Direction, 1.0f);
	}

	// Spin the body for visual effect
	if (BodyMesh)
	{
		BodyMesh->AddRelativeRotation(FRotator(0.f, DeltaSeconds * 120.f, 0.f));
	}
}

void AEnemyCharacter::SetupEnemy(EEnemyType Type, float SpeedMultiplier)
{
	EnemyType = Type;

	switch (Type)
	{
	case EEnemyType::Small:
		MaxHealth = 1.0f;
		MoveSpeed = 320.0f * SpeedMultiplier;
		ContactDamage = 1.0f;
		ScoreValue = 10;
		GetCapsuleComponent()->SetCapsuleSize(28.f, 44.f);
		break;

	case EEnemyType::Medium:
		MaxHealth = 3.0f;
		MoveSpeed = 230.0f * SpeedMultiplier;
		ContactDamage = 1.0f;
		ScoreValue = 25;
		GetCapsuleComponent()->SetCapsuleSize(40.f, 60.f);
		break;

	case EEnemyType::Large:
		MaxHealth = 7.0f;
		MoveSpeed = 160.0f * SpeedMultiplier;
		ContactDamage = 2.0f;
		ScoreValue = 50;
		GetCapsuleComponent()->SetCapsuleSize(55.f, 80.f);
		break;
	}

	CurrentHealth = MaxHealth;
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = MoveSpeed;
	}

	// Re-apply visuals now that EnemyType / capsule size are final
	ApplyEnemyVisuals();
}

float AEnemyCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	if (bDying) return 0.f;

	CurrentHealth -= DamageAmount;

	if (CurrentHealth <= 0.f)
	{
		Die();
	}
	return DamageAmount;
}

void AEnemyCharacter::Die()
{
	bDying = true;
	OnEnemyDied.Broadcast(ScoreValue);

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCharacterMovement()->StopMovementImmediately();

	if (BodyMesh)
	{
		BodyMesh->SetRelativeScale3D(FVector(0.05f));
	}

	SetLifeSpan(0.15f);
}

void AEnemyCharacter::ApplyEnemyVisuals()
{
	UStaticMesh* MeshAsset = nullptr;
	FLinearColor Color;
	FVector MeshScale;

	switch (EnemyType)
	{
	case EEnemyType::Small:
		MeshAsset = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr,
			TEXT("/Engine/BasicShapes/Cube.Cube")));
		Color = FLinearColor(1.f, 0.08f, 0.08f);
		MeshScale = FVector(0.55f, 0.55f, 0.55f);
		break;

	case EEnemyType::Medium:
		MeshAsset = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr,
			TEXT("/Engine/BasicShapes/Cylinder.Cylinder")));
		Color = FLinearColor(1.f, 0.45f, 0.0f);
		MeshScale = FVector(0.8f, 0.8f, 0.8f);
		break;

	case EEnemyType::Large:
		MeshAsset = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr,
			TEXT("/Engine/BasicShapes/Sphere.Sphere")));
		Color = FLinearColor(0.6f, 0.0f, 1.0f);
		MeshScale = FVector(1.1f, 1.1f, 1.1f);
		break;
	}

	if (MeshAsset)
	{
		BodyMesh->SetStaticMesh(MeshAsset);
		BodyMesh->SetRelativeScale3D(MeshScale);
	}

	UMaterialInterface* BaseMat = Cast<UMaterialInterface>(StaticLoadObject(
		UMaterialInterface::StaticClass(), nullptr,
		TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial")));

	if (BaseMat)
	{
		UMaterialInstanceDynamic* DynMat = UMaterialInstanceDynamic::Create(BaseMat, this);
		DynMat->SetVectorParameterValue(TEXT("Color"), Color);
		BodyMesh->SetMaterial(0, DynMat);
	}
}

void AEnemyCharacter::OnBodyOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (bDying || ContactDamageTimer > 0.f) return;

	APersonGameCharacter* Player = Cast<APersonGameCharacter>(OtherActor);
	if (Player)
	{
		FDamageEvent DamageEvent;
		Player->TakeDamage(ContactDamage, DamageEvent, nullptr, this);
		ContactDamageTimer = 0.7f;
	}
}
