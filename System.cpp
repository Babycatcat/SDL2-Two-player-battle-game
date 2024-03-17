#include "System.h"
#include <stdio.h>
#include <SDL.h> // Using SDL
#include "SDL_image.h"  // Using SDL2 image extension library 

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int System::init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		printf("SDL_Init failed: %s\n", SDL_GetError());
		return 0;
	}

	int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image failed: %s\n", IMG_GetError());
		return 0;
	}

	return 1;
}

void System::close()
{
	IMG_Quit();
	SDL_Quit();
}
int  P1=0,P2=0;
bool exitgame = false;
bool pause=false;
enum Screen screen = MainMenu;
int again = 0;

