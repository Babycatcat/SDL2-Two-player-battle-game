#include <stdlib.h>
#include <SDL.h> // Using SDL
#include <SDL2_gfxPrimitives.h> // Using SDL2_gfx
#include <SDL_image.h>
#include<stdio.h>
#include "RenderWindow.h"
#include "System.h"
#include "Image.h"
#include "TextInput.h"
#include "Role.h"
#include "Wall.h"
#include "Attack.h"
#include "Grass.h"
#include "Bullet.h"
#include "Bomb.h"
#include "text.h"
#include "mouse.h"
#include"player.h"
#include"menu.h"
#include"button.h"
#include"choosechar.h"
#include"rankinglist.h"
#include "Game.h"
#include"Win.h"
#include"Game2.h"

const int BUTTON_X = WIDTH / 4;
const int BUTTON_Y = HEIGHT / 4;
const int BUTTON_WIDTH = WIDTH / 2;
const int BUTTON_HEIGHT = HEIGHT / 2;

ImageData loadImgTexture(char* path, int num, int hn, int wn, bool ckEnable, Uint8 r, Uint8 g, Uint8 b);


SDL_Surface* scrSurface = NULL;


SDL_Surface* imgSurface1 = NULL;
SDL_Surface* imgSurface2 = NULL;
SDL_Surface* imgSurface3 = NULL;
SDL_Surface* imgSurface4 = NULL;
SDL_Surface* imgSurface5 = NULL;
SDL_Surface* imgSurface6 = NULL;
SDL_Surface* imgSurface7 = NULL;


int initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		("SDL_Init failed: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("OOP SDL Tutorial", 50, 50, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		("SDL_CreateWindow failed: %s\n", SDL_GetError());
		SDL_Quit();
		return 2;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		("SDL_image failed: %s\n", IMG_GetError());
		return 3;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		("SDL_CreateRenderer failed: %s\n", SDL_GetError());
		SDL_Quit();
		return 3;
	}
	if (TTF_Init() == -1)
	{
		// https://www.libsdl.org/projects/SDL_ttf/docs/SDL_ttf_frame.html
		("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return 4;
	}
	return 0;
}

void closeSDL()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	if (initSDL())
	{
		("Failed to initialize SDL!\n");
		return -1;
	}
	
	SDL_ShowCursor(SDL_DISABLE);
	srand(time(NULL));
	int d = 0;
	while (!exitgame) {
		if (screen == MainMenu) { Menu(); }
		else if (screen == Choosechar) { Menu1(); }
		else if (screen == Back) { Menu(); }
		else if (screen == Game) { game(); }
		else if (screen == Game2) { game2(); }
		else if (screen == Win)win(&d);
		else if (screen == Ranking)RankingList(&d);
	}
	printf("exit");

	closeSDL();
	return 0;
}
