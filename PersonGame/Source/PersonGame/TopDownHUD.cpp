// GeoSiege - Canvas HUD

#include "TopDownHUD.h"
#include "PersonGameCharacter.h"
#include "WaveManager.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ATopDownHUD::ATopDownHUD()
{
	static ConstructorHelpers::FObjectFinder<UFont> FontFinder(
		TEXT("/Engine/EngineFonts/RobotoDistanceField.RobotoDistanceField"));
	if (FontFinder.Succeeded())
	{
		HUDFont = FontFinder.Object;
	}
}

void ATopDownHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!Canvas) return;

	AWaveManager* WM = AWaveManager::GetInstance(GetWorld());

	APersonGameCharacter* Player = nullptr;
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		Player = Cast<APersonGameCharacter>(PC->GetPawn());
	}

	if (WM && WM->bGameOver)
	{
		DrawGameOver(WM->Score);
		return;
	}

	if (Player)
	{
		DrawHealthBar(Player->CurrentHealth, Player->MaxHealth, 20.f, 20.f, 220.f, 28.f);
	}

	if (WM)
	{
		DrawScoreAndWave(WM->Score, WM->CurrentWave, WM->GetEnemiesRemaining());

		if (WM->bBetweenWaves && WM->WaveCountdown > 0.f)
		{
			DrawWaveAnnounce(WM->CurrentWave, WM->WaveCountdown);
		}
	}

	if (!WM || WM->CurrentWave == 0)
	{
		DrawControlsHint();
	}
}

void ATopDownHUD::DrawHealthBar(float Health, float MaxHealth, float X, float Y, float W, float H)
{
	// Shadow/border
	DrawRect(FLinearColor(0.f, 0.f, 0.f, 0.7f), X - 2.f, Y - 2.f, W + 4.f, H + 4.f);

	// Empty portion
	DrawRect(FLinearColor(0.25f, 0.0f, 0.0f, 0.8f), X, Y, W, H);

	float FillRatio = FMath::Clamp(Health / FMath::Max(MaxHealth, 1.f), 0.f, 1.f);
	// Lerp from red (low health) to green (full health)
	FLinearColor RedColor(0.9f, 0.1f, 0.1f);
	FLinearColor GreenColor(0.1f, 0.9f, 0.3f);
	FLinearColor HealthColor = FLinearColor(
		FMath::Lerp(RedColor.R, GreenColor.R, FillRatio),
		FMath::Lerp(RedColor.G, GreenColor.G, FillRatio),
		FMath::Lerp(RedColor.B, GreenColor.B, FillRatio)
	);
	DrawRect(HealthColor, X, Y, W * FillRatio, H);

	if (HUDFont)
	{
		DrawText(FString::Printf(TEXT("HP  %.0f / %.0f"), Health, MaxHealth),
			FLinearColor::White, X + 6.f, Y + 6.f, HUDFont, 0.85f);
	}
}

void ATopDownHUD::DrawScoreAndWave(int32 Score, int32 Wave, int32 EnemiesLeft)
{
	if (!HUDFont || !Canvas) return;

	const float ScreenW = Canvas->SizeX;

	FString ScoreStr = FString::Printf(TEXT("SCORE  %d"), Score);
	float TW, TH;
	GetTextSize(ScoreStr, TW, TH, HUDFont, 1.3f);
	// Shadow
	DrawText(ScoreStr, FLinearColor(0.f, 0.f, 0.f, 0.6f), ScreenW - TW - 18.f, 21.f, HUDFont, 1.3f);
	DrawText(ScoreStr, FLinearColor(1.f, 0.92f, 0.2f), ScreenW - TW - 20.f, 20.f, HUDFont, 1.3f);

	FString WaveStr = Wave > 0 ? FString::Printf(TEXT("WAVE  %d"), Wave) : TEXT("GEO SIEGE");
	GetTextSize(WaveStr, TW, TH, HUDFont, 1.0f);
	DrawText(WaveStr, FLinearColor(0.f, 0.f, 0.f, 0.6f), ScreenW - TW - 18.f, 52.f, HUDFont, 1.0f);
	DrawText(WaveStr, FLinearColor(0.7f, 0.8f, 1.f), ScreenW - TW - 20.f, 51.f, HUDFont, 1.0f);

	if (Wave > 0 && EnemiesLeft > 0)
	{
		FString EnemyStr = FString::Printf(TEXT("Enemies  %d"), EnemiesLeft);
		GetTextSize(EnemyStr, TW, TH, HUDFont, 0.85f);
		DrawText(EnemyStr, FLinearColor(1.f, 0.4f, 0.4f), ScreenW - TW - 20.f, 78.f, HUDFont, 0.85f);
	}
}

void ATopDownHUD::DrawWaveAnnounce(int32 Wave, float Countdown)
{
	if (!HUDFont || !Canvas) return;

	const float ScreenW = Canvas->SizeX;
	const float ScreenH = Canvas->SizeY;

	float Alpha = FMath::Min(1.f, Countdown * 0.8f);

	FString Announce;
	if (Wave == 0)
	{
		Announce = FString::Printf(TEXT("GEO SIEGE  %.0f"), Countdown);
	}
	else
	{
		Announce = FString::Printf(TEXT("WAVE %d CLEAR!  Next: %.0f"), Wave, Countdown);
	}

	float TW, TH;
	GetTextSize(Announce, TW, TH, HUDFont, 1.8f);

	// Background bar
	DrawRect(FLinearColor(0.f, 0.f, 0.f, Alpha * 0.55f),
		(ScreenW - TW) * 0.5f - 20.f, ScreenH * 0.25f - 8.f, TW + 40.f, TH * 1.8f + 16.f);

	DrawText(Announce,
		FLinearColor(0.2f, 1.f, 0.4f, Alpha),
		(ScreenW - TW) * 0.5f, ScreenH * 0.25f, HUDFont, 1.8f);
}

void ATopDownHUD::DrawGameOver(int32 FinalScore)
{
	if (!Canvas) return;

	const float ScreenW = Canvas->SizeX;
	const float ScreenH = Canvas->SizeY;

	DrawRect(FLinearColor(0.f, 0.f, 0.f, 0.75f), 0.f, 0.f, ScreenW, ScreenH);

	if (!HUDFont) return;

	float TW, TH;

	FString GoStr = TEXT("GAME OVER");
	GetTextSize(GoStr, TW, TH, HUDFont, 3.5f);
	DrawText(GoStr, FLinearColor(0.f, 0.f, 0.f, 0.8f),
		(ScreenW - TW) * 0.5f + 2.f, ScreenH * 0.32f + 2.f, HUDFont, 3.5f);
	DrawText(GoStr, FLinearColor(1.f, 0.15f, 0.15f),
		(ScreenW - TW) * 0.5f, ScreenH * 0.32f, HUDFont, 3.5f);

	FString ScoreStr = FString::Printf(TEXT("Final Score:  %d"), FinalScore);
	GetTextSize(ScoreStr, TW, TH, HUDFont, 2.0f);
	DrawText(ScoreStr, FLinearColor(1.f, 0.92f, 0.2f),
		(ScreenW - TW) * 0.5f, ScreenH * 0.5f, HUDFont, 2.0f);

	// Pulsing restart prompt
	float PulseAlpha = 0.6f + 0.4f * FMath::Sin(GetWorld()->GetTimeSeconds() * 3.f);
	FString RestartStr = TEXT("ENTER / TAP to Restart");
	GetTextSize(RestartStr, TW, TH, HUDFont, 1.1f);
	DrawText(RestartStr, FLinearColor(0.85f, 0.85f, 0.85f, PulseAlpha),
		(ScreenW - TW) * 0.5f, ScreenH * 0.65f, HUDFont, 1.1f);
}

void ATopDownHUD::DrawControlsHint()
{
	if (!HUDFont || !Canvas) return;

	const float ScreenH = Canvas->SizeY;

	DrawText(TEXT("PC: WASD to move  |  Mobile: Tap to move  |  Auto-aim ON"),
		FLinearColor(0.7f, 0.7f, 0.7f, 0.6f), 20.f, ScreenH - 36.f, HUDFont, 0.75f);
}
