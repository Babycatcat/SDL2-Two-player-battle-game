#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h> // Using SDL
#include <string.h>
#include <time.h>
#include "SDL_image.h" 

#include "Image.h"
#include"Role.h"
#include "constants.h"
class Wall :
    public Role
{
public:
    Wall();
    Wall(const char* path, SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer);//劃出橫的跟直的牆壁SDL_Renderer* renderer
    void random();//牆壁位置

private:
    //char* path;
    //SDL_Renderer* renderer;
    int w[12][16];
    
};

