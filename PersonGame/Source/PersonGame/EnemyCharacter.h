// GeoSiege - Enemy Character

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UENUM(BlueprintType)
enum class EEnemyType : uint8
{
	Small	UMETA(DisplayName = "Small"),
	Medium	UMETA(DisplayName = "Medium"),
	Large	UMETA(DisplayName = "Large"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDied, int32, Score);

UCLASS()
class PERSONGAME_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	EEnemyType EnemyType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	float ContactDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	int32 ScoreValue;

	void SetupEnemy(EEnemyType Type, float SpeedMultiplier = 1.0f);
	bool IsAlive() const { return CurrentHealth > 0.0f && !bDying; }

	UPROPERTY(BlueprintAssignable)
	FOnEnemyDied OnEnemyDied;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BodyMesh;

	float ContactDamageTimer;
	bool bDying;

	void Die();
	void ApplyEnemyVisuals();

	UFUNCTION()
	void OnBodyOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);
};
