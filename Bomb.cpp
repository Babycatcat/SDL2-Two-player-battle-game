#include<stdio.h>
#include"Bomb.h"
#include<time.h>
#include"system.h"

Bomb::Bomb() {}
Bomb::Bomb(const char* path, SDL_Renderer* ren) :Role(path, ren) {
	Image("../image/attack/bomb.png", ren, 0xFF, 0xFF, 0xFF);
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 16; j++)
			bp[i][j] = 0;
}
Bomb::Bomb(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren) :Role(path, n, hhn, wwn, ren) {
	Image("../image/attack/bomb.png", ren, 0xFF, 0xFF, 0xFF);
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 16; j++)
			bp[i][j] = 0;
}
Bomb::Bomb(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b)
	:Role(path, n, hhn, wwn, ren, r, g, b) {
	printf("bomb role & image are set!!\n");
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 16; j++)
			bp[i][j] = 0;
}
void Bomb::setBomb(int a, int b, int rbp[12][16])
{
	Role::setPosition((a - 1) * 50+EDGE, (b - 1) * 50 - 40);
	bp[b][a] = 1;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 16; j++)
			rbp[i][j] = bp[i][j];
	bp[b][a] = 0;
}
void Bomb::getBp(int a[12][16])
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 16; j++)
			a[i][j] = bp[i][j];
}