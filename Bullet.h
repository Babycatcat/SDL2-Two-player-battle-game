#pragma once
#include<stdio.h>
#include"Attack.h"
class Bullet :public Attack {
public:
	Bullet() {};
	//Bullet(const char* path, SDL_Renderer* ren);
	//Bullet(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren);
	Bullet(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b);
	void setPosition1(Role &r);
	void getBarriar();
	void move1(int pos, Role &r);
	//int hitBarriar();
private:
	SDL_Renderer* renderer;
	char* path;
	int bx;//bullet location
	int by;
	int barriar[12][16];
	int num;
	int wn; // New in this example, image number in width
	int hn; // New in this example, image number in height
	//Image image;  // Renew in this example, change from pointer to object because of only one file	
	int frame;
};