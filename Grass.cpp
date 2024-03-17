#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL.h>
#include "SDL_image.h" 
#include "Grass.h"
#include"system.h"
#include"Image.h"
#include"Renderwindow.h"

Grass::Grass() {}

Grass::Grass(const char* path, SDL_Renderer* renderer) {

	Image::setPath(path);
	Image::setColorKey(NO_TRANSPARENT_BG);
	Image::setRenderer(renderer);

	Image::generateTexture();

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			g[i][j] = 0;
		}
	}
}

void Grass::random() {
	int i, j, k, **p;
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 16; j++) {
			g[i][j] = 0;
		}
	}
	for (k = 0; k < 60; k++) {
		i = rand() % 11 ;
		j = rand() % 15 ;
		if (i >= 4 && i < 8 && j >= 6 && j < 10) {
			g[i][j] = 0;
			k--;
		}
		else g[i][j] = 1;

		if (i == 0 || j == 0)
			g[i][j] = 0;
	}
	g[11][15] = 0;
	Role::checkBarriar1(g);
	getGrass(g);
}
void Grass::draw(SDL_Renderer* renderer)
{
	int i, j;
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 15; j++) {
			if (g[i][j] == 1) {//設定位子
				SDL_Rect d;
				d.x = 50 * j+EDGE;
				d.y = 50 * i;
				d.w = getWidth();
				d.h = getHeight();
				Image::draw(renderer, d, { ALLREGION });
			}
		}
	}
}

void Grass::bombhere(int bp[12][16])
{
	int b[12][16];
	Role::returnBarriar(b);
	for (int i = 0; i <= 11; i++)
		for (int j = 0; j <= 15; j++)
		{
			if (bp[i][j]) {
				if ((b[i - 1][j] != 1) || (b[i][j - 1] != 1)) g[i - 1][j - 1] = 0;
				if ((b[i - 1][j] != 1) || (b[i][j + 1] != 1)) g[i - 1][j + 1] = 0;
				if ((b[i + 1][j] != 1) || (b[i][j - 1] != 1)) g[i + 1][j - 1] = 0;
				if ((b[i + 1][j] != 1) || (b[i][j + 1] != 1)) g[i + 1][j + 1] = 0;
				g[i - 1][j] = 0, g[i][j - 1] = 0, g[i][j + 1] = 0, g[i + 1][j] = 0;
			}


		}
	SDL_Delay(200);
	Role::getGrass(g);
}