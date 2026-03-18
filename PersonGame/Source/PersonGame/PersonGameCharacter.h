// GeoSiege - Player Character

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PersonGameCharacter.generated.h"

UCLASS(Blueprintable)
class APersonGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APersonGameCharacter();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;

	// --- Camera ---
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	// --- Health ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float MaxHealth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	float CurrentHealth;

	// --- Shooting ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	bool IsAlive() const { return CurrentHealth > 0.f && !bDead; }

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BodyMesh;

	UPROPERTY()
	UMaterialInstanceDynamic* DynBodyMat;

	float FireTimer;
	float DamageFlashTimer;
	bool bDead;

	void ShootAtNearestEnemy();
	void Die();
	void SetupBodyMesh();
};
