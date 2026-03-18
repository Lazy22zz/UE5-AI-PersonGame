// GeoSiege - Wave Manager / Game State Controller

#include "WaveManager.h"
#include "Engine/World.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "Math/UnrealMathUtility.h"

AWaveManager::AWaveManager()
{
	PrimaryActorTick.bCanEverTick = true;

	ArenaRadius = 2000.f;
	CurrentWave = 0;
	Score = 0;
	bGameOver = false;
	bGameStarted = false;
	bBetweenWaves = true;
	EnemiesAlive = 0;
	EnemiesThisWave = 0;
	StateTimer = 3.5f;
	WaveCountdown = 3.5f;
	TimeBetweenWaves = 4.0f;
}

void AWaveManager::BeginPlay()
{
	Super::BeginPlay();
	BuildArenaWalls();
	bGameStarted = true;
}

void AWaveManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!bGameStarted || bGameOver) return;

	if (bBetweenWaves)
	{
		StateTimer -= DeltaSeconds;
		WaveCountdown = FMath::Max(0.f, StateTimer);
		if (StateTimer <= 0.f)
		{
			StartNextWave();
		}
	}
	else
	{
		WaveCountdown = 0.f;
		if (EnemiesAlive <= 0)
		{
			bBetweenWaves = true;
			StateTimer = TimeBetweenWaves;
			WaveCountdown = TimeBetweenWaves;
		}
	}
}

void AWaveManager::StartNextWave()
{
	CurrentWave++;
	bBetweenWaves = false;

	int32 Count = GetEnemyCountForWave();
	EEnemyType Type = GetEnemyTypeForWave();
	float SpeedMult = GetSpeedMultiplierForWave();

	EnemiesThisWave = Count;
	EnemiesAlive = Count;

	for (int32 i = 0; i < Count; i++)
	{
		float Angle = (float)i / (float)Count * 2.f * PI;
		float Jitter = FMath::RandRange(-300.f, 300.f);
		FVector SpawnPos(
			FMath::Sin(Angle) * (ArenaRadius - 150.f) + FMath::RandRange(-100.f, 100.f),
			FMath::Cos(Angle) * (ArenaRadius - 150.f) + Jitter,
			80.f
		);
		SpawnEnemyAt(SpawnPos, Type, SpeedMult);
	}
}

void AWaveManager::SpawnEnemyAt(FVector Location, EEnemyType Type, float SpeedMult)
{
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AEnemyCharacter* Enemy = GetWorld()->SpawnActor<AEnemyCharacter>(
		AEnemyCharacter::StaticClass(), Location, FRotator::ZeroRotator, Params);

	if (Enemy)
	{
		Enemy->SetupEnemy(Type, SpeedMult);
		Enemy->OnEnemyDied.AddDynamic(this, &AWaveManager::OnEnemyKilledDelegate);
	}
}

void AWaveManager::OnEnemyKilledDelegate(int32 ScoreValue)
{
	OnEnemyKilled(ScoreValue);
}

void AWaveManager::OnEnemyKilled(int32 ScoreValue)
{
	Score += ScoreValue;
	EnemiesAlive = FMath::Max(0, EnemiesAlive - 1);
}

void AWaveManager::TriggerGameOver()
{
	bGameOver = true;
}

void AWaveManager::BuildArenaWalls()
{
	UStaticMesh* CubeMesh = Cast<UStaticMesh>(StaticLoadObject(
		UStaticMesh::StaticClass(), nullptr, TEXT("/Engine/BasicShapes/Cube.Cube")));

	UMaterialInterface* BaseMat = Cast<UMaterialInterface>(StaticLoadObject(
		UMaterialInterface::StaticClass(), nullptr,
		TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial")));

	if (!CubeMesh) return;

	const float R = ArenaRadius;
	const float WallH = 180.f;
	const float WallT = 80.f;
	const float WallZ = WallH * 0.5f;
	const float WallLen = R * 2.f + WallT * 2.f;

	struct FWallData { FVector Loc; FVector Scale; };
	TArray<FWallData> Walls = {
		{ FVector(0.f,  R + WallT * 0.5f, WallZ), FVector(WallLen / 100.f, WallT / 100.f, WallH / 100.f) },
		{ FVector(0.f, -R - WallT * 0.5f, WallZ), FVector(WallLen / 100.f, WallT / 100.f, WallH / 100.f) },
		{ FVector( R + WallT * 0.5f, 0.f, WallZ), FVector(WallT / 100.f, WallLen / 100.f, WallH / 100.f) },
		{ FVector(-R - WallT * 0.5f, 0.f, WallZ), FVector(WallT / 100.f, WallLen / 100.f, WallH / 100.f) },
	};

	for (const FWallData& W : Walls)
	{
		FActorSpawnParameters Params;
		AStaticMeshActor* WallActor = GetWorld()->SpawnActor<AStaticMeshActor>(
			AStaticMeshActor::StaticClass(), W.Loc, FRotator::ZeroRotator, Params);

		if (!WallActor) continue;

		UStaticMeshComponent* SMC = WallActor->GetStaticMeshComponent();
		SMC->SetMobility(EComponentMobility::Movable);
		SMC->SetStaticMesh(CubeMesh);
		WallActor->SetActorScale3D(W.Scale);

		if (BaseMat)
		{
			UMaterialInstanceDynamic* DynMat = UMaterialInstanceDynamic::Create(BaseMat, WallActor);
			DynMat->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.02f, 0.04f, 0.18f));
			SMC->SetMaterial(0, DynMat);
		}
	}
}

EEnemyType AWaveManager::GetEnemyTypeForWave() const
{
	if (CurrentWave <= 3) return EEnemyType::Small;
	if (CurrentWave <= 7) return EEnemyType::Medium;
	return EEnemyType::Large;
}

float AWaveManager::GetSpeedMultiplierForWave() const
{
	return 1.0f + (CurrentWave - 1) * 0.08f;
}

int32 AWaveManager::GetEnemyCountForWave() const
{
	return FMath::Min(4 + CurrentWave * 2, 30);
}

AWaveManager* AWaveManager::GetInstance(UWorld* World)
{
	if (!World) return nullptr;

	TArray<AActor*> Managers;
	UGameplayStatics::GetAllActorsOfClass(World, AWaveManager::StaticClass(), Managers);

	if (Managers.Num() > 0)
	{
		return Cast<AWaveManager>(Managers[0]);
	}
	return nullptr;
}
