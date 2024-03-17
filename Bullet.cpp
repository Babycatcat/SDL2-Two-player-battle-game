#include<stdio.h>
#include"Bullet.h"

Bullet::Bullet(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b)
{
	Image::setPath(path);
	Image::setRenderer(ren);
	Image::setColorKey({ r, g, b });
	Image::generateTexture();
	renderer = ren;

}

void Bullet::setPosition1(Role &r) {
	bx = r.Posx;
	by = r.Posy;
	printf("in setPosition bx=%d by=%d\n", bx, by);
	system("pause");
}

void Bullet::getBarriar() {
	Role::returnBarriar(barriar);
}