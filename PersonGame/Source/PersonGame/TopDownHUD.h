// GeoSiege - Canvas HUD

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TopDownHUD.generated.h"

UCLASS()
class PERSONGAME_API ATopDownHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATopDownHUD();

	virtual void DrawHUD() override;

private:
	UPROPERTY()
	UFont* HUDFont;

	void DrawHealthBar(float Health, float MaxHealth, float X, float Y, float W, float H);
	void DrawScoreAndWave(int32 Score, int32 Wave, int32 EnemiesLeft);
	void DrawWaveAnnounce(int32 Wave, float Countdown);
	void DrawGameOver(int32 FinalScore);
	void DrawControlsHint();
};
