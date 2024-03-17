#pragma once
#include "system.h"
#include"mouse.h"
#include "text.h"
#include"Role.h"
#include"Bomb.h"
#include"Bullet.h"
#include"Grass.h"
//#include "audio.h"

//extern int VELOCITY;
//extern int angle;
//extern int angle1;

class Player:
	public Role
{
public:
	Player();
	Player(const char* path, SDL_Renderer* ren);
	Player(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren);
	Player(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b);
	friend Player& operator+(Player &p,int);//operator overloading!
	friend Player& operator-(Player& p, int);//operator overloading!
	friend Player& operator+=(Player& p, int );//operator overloading!


	double HP;
	SDL_Point v[4];
	//SDL_TimerID tr_timer, shieldhold_ID;
	//int tr_num, tr_par = 0, tr_hold; // what kind of effect, treasure parameter
	//int shield = 0;//盾牌
	Text score;
	friend void PlayerInit(Player& player, int num, int x, int y, int  HP);
	friend int handleEvent1b(SDL_Event& e, Role& R1, Role& R2, Bomb& b, Bullet& At, Grass& g, int& setb, int& hit);
	friend int handleEvent2b(SDL_Event& e, Role& R1, Role& R2, Bomb& b, Bullet& At, Grass& g, int& setb, int& hit);
	friend void handleEvent1(SDL_Event& e, Role& Ro);//, int setb, int bhit);
	friend void handleEvent2(SDL_Event& e, Role& Ro);// , int setb, int bhit);
	//void PlayerRefresh(Player& p);
	//void AttackKeyEvent(Player& player);
	//void move(Role& ro); role 裡面就寫了
	//void PlayerDraw(Player& player);
	//void PlayerShooting(struct Player& player);
	friend void PlayerFree(Player& player);
};

