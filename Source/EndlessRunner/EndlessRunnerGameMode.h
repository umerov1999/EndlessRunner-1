// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "GameFramework/GameModeBase.h"
#include "FloorTile.h"
#include "EndlessRunnerGameMode.generated.h"

UCLASS(minimalapi)
class AEndlessRunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEndlessRunnerGameMode();

	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = FloorTile)
	FTransform NextSpawnPoint;
	int straightInARow;

	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = FloorTile)
	TSubclassOf<AFloorTile> BP_FloorTile_Basic;
	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = FloorTile)
	TSubclassOf<AFloorTile> BP_FloorTile_Up;
	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = FloorTile)
	TSubclassOf<AFloorTile> BP_FloorTile_Left;
	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = FloorTile)
	TSubclassOf<AFloorTile> BP_FloorTile_Right;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void AddRandomFloorTile();

	UFUNCTION(BlueprintCallable)
	void AddFloorTile(TSubclassOf<AFloorTile> tileToSpawn, bool WithObstacle, bool WithGold);
};



