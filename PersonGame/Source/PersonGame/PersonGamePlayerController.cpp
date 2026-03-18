// GeoSiege - Player Controller

#include "PersonGamePlayerController.h"
#include "WaveManager.h"
#include "PersonGameCharacter.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

APersonGamePlayerController::APersonGamePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
	bRestartPending = false;
}

void APersonGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void APersonGamePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// --- Game Over: restart on Enter/Space or any touch ---
	AWaveManager* WM = AWaveManager::GetInstance(GetWorld());
	if (WM && WM->bGameOver)
	{
		if (IsInputKeyDown(EKeys::Enter) || IsInputKeyDown(EKeys::SpaceBar) ||
			IsInputKeyDown(EKeys::Gamepad_FaceButton_Bottom))
		{
			if (!bRestartPending)
			{
				bRestartPending = true;
				UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
			}
		}
		return;
	}

	// --- WASD keyboard movement ---
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn)
	{
		FVector MoveDir = FVector::ZeroVector;

		if (IsInputKeyDown(EKeys::W) || IsInputKeyDown(EKeys::Up))
			MoveDir += FVector(1.f, 0.f, 0.f);
		if (IsInputKeyDown(EKeys::S) || IsInputKeyDown(EKeys::Down))
			MoveDir += FVector(-1.f, 0.f, 0.f);
		if (IsInputKeyDown(EKeys::A) || IsInputKeyDown(EKeys::Left))
			MoveDir += FVector(0.f, -1.f, 0.f);
		if (IsInputKeyDown(EKeys::D) || IsInputKeyDown(EKeys::Right))
			MoveDir += FVector(0.f, 1.f, 0.f);

		if (!MoveDir.IsNearlyZero())
		{
			StopMovement();
			ControlledPawn->AddMovementInput(MoveDir.GetSafeNormal(), 1.0f);
		}

		// Touch fallback — works even without Blueprint input actions
		float TouchX = 0.f, TouchY = 0.f;
		bool bTouchActive = false;
		GetInputTouchState(ETouchIndex::Touch1, TouchX, TouchY, bTouchActive);
		if (bTouchActive && MoveDir.IsNearlyZero())
		{
			FHitResult TouchHit;
			if (GetHitResultAtScreenPosition(FVector2D(TouchX, TouchY),
				ECollisionChannel::ECC_Visibility, true, TouchHit))
			{
				FVector TouchDir = (TouchHit.Location - ControlledPawn->GetActorLocation());
				TouchDir.Z = 0.f;
				if (!TouchDir.IsNearlyZero(20.f))
				{
					ControlledPawn->AddMovementInput(TouchDir.GetSafeNormal(), 1.0f);
				}
			}
		}
	}
}

void APersonGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultMappingContext)
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (SetDestinationClickAction)
		{
			EIC->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this,
				&APersonGamePlayerController::OnInputStarted);
			EIC->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this,
				&APersonGamePlayerController::OnSetDestinationTriggered);
			EIC->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this,
				&APersonGamePlayerController::OnSetDestinationReleased);
			EIC->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this,
				&APersonGamePlayerController::OnSetDestinationReleased);
		}

		if (SetDestinationTouchAction)
		{
			EIC->BindAction(SetDestinationTouchAction, ETriggerEvent::Started, this,
				&APersonGamePlayerController::OnInputStarted);
			EIC->BindAction(SetDestinationTouchAction, ETriggerEvent::Triggered, this,
				&APersonGamePlayerController::OnTouchTriggered);
			EIC->BindAction(SetDestinationTouchAction, ETriggerEvent::Completed, this,
				&APersonGamePlayerController::OnTouchReleased);
			EIC->BindAction(SetDestinationTouchAction, ETriggerEvent::Canceled, this,
				&APersonGamePlayerController::OnTouchReleased);
		}
	}

	// Fallback legacy bindings for mouse/touch when no Enhanced Input mapping exists
	if (InputComponent && !SetDestinationClickAction)
	{
		InputComponent->BindKey(EKeys::LeftMouseButton, IE_Pressed, this,
			&APersonGamePlayerController::OnInputStarted);
		InputComponent->BindKey(EKeys::LeftMouseButton, IE_Released, this,
			&APersonGamePlayerController::OnSetDestinationReleased);
	}
}

void APersonGamePlayerController::OnInputStarted()
{
	AWaveManager* WM = AWaveManager::GetInstance(GetWorld());
	if (WM && WM->bGameOver)
	{
		if (!bRestartPending)
		{
			bRestartPending = true;
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
		}
		return;
	}
	StopMovement();
}

void APersonGamePlayerController::OnSetDestinationTriggered()
{
	AWaveManager* WM = AWaveManager::GetInstance(GetWorld());
	if (WM && WM->bGameOver) return;

	FollowTime += GetWorld()->GetDeltaSeconds();

	FHitResult Hit;
	bool bHitSuccessful = false;
	if (bIsTouch)
	{
		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1,
			ECollisionChannel::ECC_Visibility, true, Hit);
	}
	else
	{
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	}

	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}

	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		WorldDirection.Z = 0.f;
		ControlledPawn->AddMovementInput(WorldDirection, 1.0f, false);
	}
}

void APersonGamePlayerController::OnSetDestinationReleased()
{
	AWaveManager* WM = AWaveManager::GetInstance(GetWorld());
	if (WM && WM->bGameOver) return;

	if (FollowTime <= ShortPressThreshold)
	{
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		if (FXCursor)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination,
				FRotator::ZeroRotator, FVector(1.f), true, true, ENCPoolMethod::None, true);
		}
	}

	FollowTime = 0.f;
}

void APersonGamePlayerController::OnTouchTriggered()
{
	bIsTouch = true;
	OnSetDestinationTriggered();
}

void APersonGamePlayerController::OnTouchReleased()
{
	bIsTouch = false;
	OnSetDestinationReleased();
}
