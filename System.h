#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <vector>
#include <SDL.h> 
#include "SDL2_gfxPrimitives.h"
#include "SDL_ttf.h"
using namespace std;

#define WIDTH  1200
#define HEIGHT 600
#define RIGHT_EDGE  1000 ///
#define LEFT_EDGE   200 ///
#define EDGE   200 ///
#define ALLREGION -1
#define NO_TRANSPARENT_BG {0, 0, 0, 0}
const int M_WIDTH = 45;//¨¤¦â¤j¤p!
const int M_HEIGHT = 30;
const int VELOCITY = 3;
const int B_WIDTH = 5;
const int B_HEIGHT = 3;

extern SDL_Window* window;//= SDL_CreateWindow("OOP SDL Tutorial", 50, 50, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
extern SDL_Renderer* renderer;// = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


extern bool  exitgame;
extern bool pause;
enum Screen { MainMenu, Choosechar, Ranking, Exit, Game, Back,Win,Game2};
extern Screen screen;
extern int  P1,P2;
extern int again;
class System
{
public:
	int init();
	void close();
};