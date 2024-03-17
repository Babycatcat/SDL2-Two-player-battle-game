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

class Grass :
    public Role
{
public:
    Grass();
    Grass(const char* path, SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer);//µe¥X¯ó
    void random();//¯ó¦ì¸m
    void bombhere(int[12][16]);

private:
    //char* path;
    //SDL_Renderer* renderer;
    int g[12][16];

};

