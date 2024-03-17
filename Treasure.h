#pragma once
#include "system.h"
#include"image.h"
#include "player.h"
enum tType { hpplus, mpplus, shield }; // 1, 2...
struct Treasure {
	int x, y;
	int exist;
	ImageData img;
	SDL_TimerID tt, appear, heart, shield_ID;
	int starPar = 1, heartPar = 0, shieldPar = 0;
	tType type;
};


void TreasureInit(Treasure& treasure, Player& player, tType type, int x, int y);
void TreasureEvent(Player& player, Treasure& treasure, tType type);
void TreasureDraw(Treasure& treasure, tType type);
void TreasureFree(Treasure& treasure);