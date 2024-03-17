
#pragma once
#include "SDL_image.h" 
#include "Image.h"
#include"Role.h"
#include <SDL.h> // Using SDL
#include"Renderwindow.h"
#include "constants.h"

class Attack :
	public Role
{
public:
	Attack();
	Attack(const char* path, SDL_Renderer* ren);
	void weaponPosition(Role &c);
	//void weaponMove(int n);
	//void draw();
	//void yShown();
	//void nShown();

	//new
	int hit(Attack& a, Role& r);///
	void setCount(int n);///
	void setCount(Attack& a, Role& r);///
	int getCount();
private:
	SDL_Renderer* renderer;
	char* path;
	int wx;//weapon location
	int wy;
	int num;
	int wn; 
	int hn; 
	int frame;
	
	int count;///new

};
