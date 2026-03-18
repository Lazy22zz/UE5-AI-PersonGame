// GeoSiege - Wave Manager / Game State Controller

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyCharacter.h"
#include "WaveManager.generated.h"

UCLASS()
class PERSONGAME_API AWaveManager : public AActor
{
	GENERATED_BODY()

public:
	AWaveManager();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arena")
	float ArenaRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	int32 CurrentWave;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	int32 Score;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	bool bGameOver;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	bool bGameStarted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	bool bBetweenWaves;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	float WaveCountdown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	float TimeBetweenWaves;

	void OnEnemyKilled(int32 ScoreValue);

	UFUNCTION()
	void OnEnemyKilledDelegate(int32 ScoreValue);

	void TriggerGameOver();

	int32 GetEnemiesRemaining() const { return EnemiesAlive; }

	static AWaveManager* GetInstance(UWorld* World);

private:
	int32 EnemiesAlive;
	int32 EnemiesThisWave;
	float StateTimer;

	void StartNextWave();
	void SpawnEnemyAt(FVector Location, EEnemyType Type, float SpeedMult);

	EEnemyType GetEnemyTypeForWave() const;
	float GetSpeedMultiplierForWave() const;
	int32 GetEnemyCountForWave() const;
};
