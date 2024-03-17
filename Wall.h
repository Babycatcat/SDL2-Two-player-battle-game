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
    void draw(SDL_Renderer* renderer);//���X��򪽪����SDL_Renderer* renderer
    void random();//�����m

private:
    //char* path;
    //SDL_Renderer* renderer;
    int w[12][16];
    
};

