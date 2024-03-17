#include "Attack.h"
#include"Role.h"
#include"Image.h"
#include<SDL.h>
#include<stdio.h>
#include"System.h"

Attack::Attack() {};

Attack::Attack(const char* path, SDL_Renderer* ren) {
	Image::setPath(path);
	Image::setColorKey(NO_TRANSPARENT_BG);
	Image::setRenderer(ren);
	Image::generateTexture();
	renderer = ren;
	num = 1;
	frame = 0;
	hn = 1;
	wn = 1;
}

void Attack::weaponPosition(Role &c) {
	wx = c.Posx;
	wy = c.Posy;
	Posx = c.Posx;
	Posy = c.Posy;
	
}
//new!!
int Attack::hit(Attack& a, Role& r) {/// 
	int rx1, ry1, rx2, ry2,  ax, ay;
	rx1 = (r.Posx) ;
	ry1 = (r.Posy) ;
	rx2 = (r.Posx + M_WIDTH) ;
	ry2 = (r.Posy + M_HEIGHT);
	ax = (a.Posx + B_WIDTH / 2);
	ay = (a.Posy + B_HEIGHT / 2);
	if (rx1 <= ax && rx2 >= ax && ry1 <= ay && ry2 >= ay) {
		printf("hit\n");
		return 1;// hit
	}
	else
		return 0;
}
void Attack::setCount(int a) {
	count = a;
}
void Attack::setCount(Attack& a, Role& r) {
	if (a.hit(a, r) == 0) {
		count = 0;
	}
	else {
		count = 1;
	}
}

int Attack::getCount() {
	return count;
}