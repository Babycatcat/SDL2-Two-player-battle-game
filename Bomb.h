#pragma once
#include"Role.h"

class Bomb :public Role
{
public:
	Bomb();
	Bomb(const char* path, SDL_Renderer* ren);
	Bomb(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren);
	Bomb(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b);
	void setBomb(int, int, int[12][16]);
	void getBp(int[12][16]);
private:
	int bx;
	int by;
	int bp[12][16];//bombposition
	//Image I("../image/attack/bomb.png", ren, 0xFF, 0xFF, 0xFF);

	//bool explosion;//§ìÃz¬µÀþ¶¡
};