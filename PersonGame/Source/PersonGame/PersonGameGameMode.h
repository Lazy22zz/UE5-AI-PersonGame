// GeoSiege - Game Mode

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PersonGameGameMode.generated.h"

UCLASS(minimalapi)
class APersonGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APersonGameGameMode();

	virtual void BeginPlay() override;
};
