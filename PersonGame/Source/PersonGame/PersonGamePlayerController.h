// GeoSiege - Player Controller

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "PersonGamePlayerController.generated.h"

class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS()
class APersonGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APersonGamePlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SetDestinationClickAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SetDestinationTouchAction;

	/** World-space position the player is currently aiming at (mouse cursor or last touch point). */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Aim")
	FVector AimWorldLocation;

	/** True when AimWorldLocation has been set at least once this session. */
	bool bHasValidAim;

protected:
	uint32 bMoveToMouseCursor : 1;

	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();
	void OnTouchTriggered();
	void OnTouchReleased();

private:
	FVector CachedDestination;
	bool bIsTouch;
	float FollowTime;
	bool bRestartPending;
};
