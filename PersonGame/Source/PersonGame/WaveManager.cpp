// GeoSiege - Wave Manager / Game State Controller

#include "WaveManager.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

AWaveManager::AWaveManager()
{
	PrimaryActorTick.bCanEverTick = true;

	// ArenaRadius defines the safe inner spawn zone (must fit inside map walls)
	ArenaRadius = 800.f;
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
	// No wall building — the map already has its own walls
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

	// Get current player location so we can maintain a safe distance
	FVector PlayerLoc = FVector::ZeroVector;
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC && PC->GetPawn())
	{
		PlayerLoc = PC->GetPawn()->GetActorLocation();
	}

	const float MinPlayerDist = 450.f;   // don't spawn too close to player
	const float MaxRadius     = ArenaRadius * 0.9f; // stay well inside map walls

	for (int32 i = 0; i < Count; i++)
	{
		FVector SpawnPos;
		int32 Attempts = 0;

		// Retry until we find a spot that is inside the arena AND far enough from the player
		do
		{
			float Angle  = FMath::RandRange(0.f, 2.f * PI);
			float Radius = FMath::RandRange(MinPlayerDist, MaxRadius);

			SpawnPos = FVector(
				FMath::Sin(Angle) * Radius,
				FMath::Cos(Angle) * Radius,
				80.f
			);
			Attempts++;
		}
		while (FVector::Dist2D(SpawnPos, PlayerLoc) < MinPlayerDist && Attempts < 20);

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
