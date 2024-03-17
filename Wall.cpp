#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#include <SDL2_gfxPrimitives.h>
#include <SDL.h>
#include "SDL_image.h" 
#include "Wall.h"
#include"system.h"
#include"Image.h"
#include"Renderwindow.h"

Wall::Wall() {}

Wall::Wall(const char* path, SDL_Renderer* renderer) {
	
	Image::setPath(path);
	Image::setColorKey(NO_TRANSPARENT_BG);
	Image::setRenderer(renderer);
	Image::generateTexture();

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			w[i][j] = 0;
		}
	}
}

void Wall::random() {//跑出牆壁位置
	int i, j, k;
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 16; j++) {
			w[i][j] = 0;
		}
	}
	for (k = 0; k < 50; k++) {
		i = rand() % 11;
		j = rand() % 15;
		if ((j > 2 && j < 14) || (j == 2  && (i < 5 || i>7)) || (j == 14 && (i < 5 || i>7))) //避開堡壘
			w[i][j] = 1;
		else k--;
		if (i == 0 || j == 0)
			w[i][j] = 0;
	}
	w[11][15] = 0;
	Role::getBarriar1(w);
}
void Wall::draw(SDL_Renderer* renderer) {//
	int i, j;
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 15; j++) {
			if (w[i][j] == 1){//設定位子
				SDL_Rect d;
				d.x = 50 * j+EDGE;
				d.y = 50 * i ;
				d.w = getWidth();
				d.h = getHeight();
				Image::draw(renderer, d, { ALLREGION });
			}
		}
	}
}