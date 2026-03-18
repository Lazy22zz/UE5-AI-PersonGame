// GeoSiege - Player Character

#include "PersonGameCharacter.h"
#include "Projectile.h"
#include "EnemyCharacter.h"
#include "WaveManager.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"

APersonGameCharacter::APersonGameCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->MaxWalkSpeed = 550.f;

	// Camera boom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-65.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false;

	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false;

	// Visual body — blue sphere
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	BodyMesh->SetupAttachment(GetCapsuleComponent());
	BodyMesh->SetRelativeLocation(FVector(0.f, 0.f, -40.f));
	BodyMesh->SetRelativeScale3D(FVector(0.9f));
	BodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(
		TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (SphereMesh.Succeeded())
	{
		BodyMesh->SetStaticMesh(SphereMesh.Object);
	}

	// Hide default skeletal mesh
	GetMesh()->SetHiddenInGame(true);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Stats
	MaxHealth = 5.0f;
	CurrentHealth = 5.0f;
	FireRate = 1.8f;
	FireTimer = 0.f;
	DamageFlashTimer = 0.f;
	bDead = false;

	// Set projectile class directly (no Blueprint dependency)
	ProjectileClass = AProjectile::StaticClass();

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void APersonGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	SetupBodyMesh();
}

void APersonGameCharacter::SetupBodyMesh()
{
	UMaterialInterface* BaseMat = Cast<UMaterialInterface>(StaticLoadObject(
		UMaterialInterface::StaticClass(), nullptr,
		TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial")));

	if (BaseMat)
	{
		DynBodyMat = UMaterialInstanceDynamic::Create(BaseMat, this);
		DynBodyMat->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.1f, 0.5f, 1.0f));
		BodyMesh->SetMaterial(0, DynBodyMat);
	}
}

void APersonGameCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (bDead) return;

	// Auto-shoot timer
	FireTimer += DeltaSeconds;
	if (FireTimer >= 1.0f / FMath::Max(FireRate, 0.1f))
	{
		ShootAtNearestEnemy();
		FireTimer = 0.f;
	}

	// Recover from damage flash
	if (DamageFlashTimer > 0.f)
	{
		DamageFlashTimer -= DeltaSeconds;
		if (DamageFlashTimer <= 0.f && DynBodyMat)
		{
			DynBodyMat->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.1f, 0.5f, 1.0f));
		}
	}
}

float APersonGameCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	if (bDead) return 0.f;

	CurrentHealth -= DamageAmount;
	CurrentHealth = FMath::Max(CurrentHealth, 0.f);

	// Flash red
	if (DynBodyMat)
	{
		DynBodyMat->SetVectorParameterValue(TEXT("Color"), FLinearColor(1.f, 0.1f, 0.1f));
		DamageFlashTimer = 0.25f;
	}

	if (CurrentHealth <= 0.f)
	{
		Die();
	}
	return DamageAmount;
}

void APersonGameCharacter::Die()
{
	if (bDead) return;
	bDead = true;

	// Notify wave manager
	AWaveManager* WM = AWaveManager::GetInstance(GetWorld());
	if (WM)
	{
		WM->TriggerGameOver();
	}

	// Disable player input
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC)
	{
		DisableInput(PC);
	}

	BodyMesh->SetRelativeScale3D(FVector(0.1f));
}

void APersonGameCharacter::ShootAtNearestEnemy()
{
	if (!ProjectileClass) return;

	TArray<AActor*> AllEnemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyCharacter::StaticClass(), AllEnemies);

	AEnemyCharacter* Target = nullptr;
	float NearestDistSq = FLT_MAX;

	for (AActor* A : AllEnemies)
	{
		AEnemyCharacter* E = Cast<AEnemyCharacter>(A);
		if (E && E->IsAlive())
		{
			float D = FVector::DistSquared(GetActorLocation(), E->GetActorLocation());
			if (D < NearestDistSq)
			{
				NearestDistSq = D;
				Target = E;
			}
		}
	}

	if (!Target) return;

	FVector Origin = GetActorLocation() + FVector(0.f, 0.f, 20.f);
	FVector Dir = (Target->GetActorLocation() - Origin).GetSafeNormal();
	Dir.Z = 0.f;
	Dir.Normalize();

	FVector SpawnLoc = Origin + Dir * 65.f;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AProjectile* Proj = GetWorld()->SpawnActor<AProjectile>(
		ProjectileClass, SpawnLoc, Dir.Rotation(), SpawnParams);
	if (Proj)
	{
		Proj->Launch(Dir);
	}

	// Face the target
	SetActorRotation(FRotator(0.f, Dir.Rotation().Yaw, 0.f));
}
