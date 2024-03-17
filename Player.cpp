#include "player.h"
#include"Role.h"
#include"Bullet.h"
#include"Bomb.h"
#include"Grass.h"
#include"System.h"

Player::Player(){}
Player::Player(const char* path, SDL_Renderer* ren) :Role(path,ren) {}
Player::Player(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren) : Role(path, n, hhn, wwn, ren) {}
Player::Player(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b):Role(path, n, hhn, wwn, ren, r, g, b) {}


Player& operator-(Player& p, int n) {
	p.point = p.getPoint(n);
	return p;
}
Player& operator+(Player&p, int n) {
	p.point =p.point+ n;
	return p;
}

Player& operator+=(Player& p,int n) {
	p.point += n;
	return p;
}
void handleEvent1(SDL_Event& e, Role& Ro)
{
	static int n = 1;
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			int bp[12][16];
			if (!pause) {
		case SDLK_UP:   Ro.setVY(Ro.getVY() - VELOCITY); break;
		case SDLK_DOWN: Ro.setVY(Ro.getVY() + VELOCITY); break; 
		case SDLK_LEFT: Ro.setVX(Ro.getVX() - VELOCITY); break; 
		case SDLK_RIGHT:Ro.setVX(Ro.getVX() + VELOCITY); break; 
		}

		case SDLK_ESCAPE:
			if (!pause)
				pause = true;
			else
				pause = false;
			break;
		}
	}
	else if (e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:    Ro.setVY(Ro.getVY() + VELOCITY); break;
		case SDLK_DOWN:  Ro.setVY(Ro.getVY() - VELOCITY); break;
		case SDLK_LEFT:  Ro.setVX(Ro.getVX() + VELOCITY); break; 
		case SDLK_RIGHT: Ro.setVX(Ro.getVX() - VELOCITY); break; 
		}
	}
}
int handleEvent1b(SDL_Event& e, Role& R1, Role& R2, Bomb& b, Bullet& At, Grass& g, int& setb, int& hit) {
	int space = 0;
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		
		printf("in 1b\n\n\n");
		if (setb == 1 || hit == 1) {

			At.setPosition(R1.Posx, R1.Posy);
		}
		At.setVX(0); At.setVY(0);
		int bp[12][16];
		switch (e.key.keysym.sym) {
		case SDLK_i:At.setPosition(R1.Posx, R1.Posy); At.setVY(At.getVY() - 2*VELOCITY);  space = 2; break;
		case SDLK_k:At.setPosition(R1.Posx, R1.Posy); At.setVY(At.getVY() + 2*VELOCITY);  space = 2; break;
		case SDLK_j:At.setPosition(R1.Posx, R1.Posy); At.setVX(At.getVX() - 2*VELOCITY);  space = 2; break;
		case SDLK_l:At.setPosition(R1.Posx, R1.Posy); At.setVX(At.getVX() + 2*VELOCITY);  space = 2; break;

		case SDLK_p:b.setBomb((R1.Posx + M_WIDTH / 2 - EDGE) / 50, (R1.Posy + M_HEIGHT / 2) / 50, bp);
			g.bombhere(bp); space = 1; break;
		}

	}

	else if (e.type == SDL_KEYUP)
	{
		space = 0;
	}
	return space;
}

int handleEvent2b(SDL_Event& e, Role& R1, Role& R2, Bomb& b, Bullet& At, Grass& g, int& setb, int& hit) {
	int space = 0;
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		
			printf("in 1b\n\n\n");
		if (setb == 1 || hit == 1) {
			At.setPosition(R2.Posx, R2.Posy);
		}
		At.setVX(0); At.setVY(0);
		int bp[12][16];
		switch (e.key.keysym.sym) {
		case SDLK_g:At.setPosition(R2.Posx, R2.Posy); At.setVY(At.getVY() - 2*VELOCITY);  space = 2; break;
		case SDLK_b:At.setPosition(R2.Posx, R2.Posy); At.setVY(At.getVY() + 2*VELOCITY);  space = 2; break;
		case SDLK_v:At.setPosition(R2.Posx, R2.Posy); At.setVX(At.getVX() - 2*VELOCITY);  space = 2; break;
		case SDLK_n:At.setPosition(R2.Posx, R2.Posy); At.setVX(At.getVX() + 2*VELOCITY);  space = 2; break;

		case SDLK_r:b.setBomb((R2.Posx + M_WIDTH / 2 - EDGE) / 50, (R2.Posy + M_HEIGHT / 2) / 50, bp);
			g.bombhere(bp); space = 1; break;
		}

	}

	else if (e.type == SDL_KEYUP)
	{
		space = 0;
	}
	return space;
}

void handleEvent2(SDL_Event& e, Role& Ro)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
			int bp[12][16];
		case SDLK_w: Ro.setVY(Ro.getVY() - VELOCITY); break; 
		case SDLK_s: Ro.setVY(Ro.getVY() + VELOCITY); break; 
		case SDLK_a: Ro.setVX(Ro.getVX() - VELOCITY); break; 
		case SDLK_d: Ro.setVX(Ro.getVX() + VELOCITY); break; 
		}

	}

	else if (e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_w: Ro.setVY(Ro.getVY() + VELOCITY); break; 
		case SDLK_s: Ro.setVY(Ro.getVY() - VELOCITY); break; 
		case SDLK_a: Ro.setVX(Ro.getVX() + VELOCITY); break;
		case SDLK_d: Ro.setVX(Ro.getVX() - VELOCITY); break; 
		}
	}
}


void PlayerInit(Player& player, int num, int x, int y, int  HP)
{
	player.HP = HP;
}

void PlayerFree(Player& player) {
	player.score.close();
}