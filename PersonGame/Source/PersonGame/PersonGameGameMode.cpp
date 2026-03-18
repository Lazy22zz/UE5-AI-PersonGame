// GeoSiege - Game Mode

#include "PersonGameGameMode.h"
#include "PersonGamePlayerController.h"
#include "PersonGameCharacter.h"
#include "WaveManager.h"
#include "TopDownHUD.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "EngineUtils.h"

APersonGameGameMode::APersonGameGameMode()
{
	// Set C++ classes as defaults; Blueprint subclasses in Content override these if they exist
	PlayerControllerClass = APersonGamePlayerController::StaticClass();
	DefaultPawnClass = APersonGameCharacter::StaticClass();
	HUDClass = ATopDownHUD::StaticClass();

	// Use Blueprint subclasses if available (standard TopDown template content)
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(
		TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if (PlayerControllerBPClass.Class != nullptr)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void APersonGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (!World) return;

	// Spawn the WaveManager if none exists in the level
	TArray<AActor*> Existing;
	for (TActorIterator<AWaveManager> It(World); It; ++It)
	{
		Existing.Add(*It);
	}

	if (Existing.Num() == 0)
	{
		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		World->SpawnActor<AWaveManager>(AWaveManager::StaticClass(),
			FVector::ZeroVector, FRotator::ZeroRotator, Params);
	}

}
