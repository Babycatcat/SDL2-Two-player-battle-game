#pragma once
#include "Role.h"
#include "Wall.h"
#include "Attack.h"
#include "Grass.h"
#include "Bullet.h"
#include"Bomb.h"
#include"System.h"
/*
int handleEvent1(SDL_Event& e, Role& Ro, Bomb& b, Bullet& At, Grass& g, int setb, int bhit);//上下左右
int handleEvent1(SDL_Event& e, Role& Ro, Bomb& b, Bullet& At, Grass& g, int setb, int bhit)
{
	/* The method for "Debunce" 

	// If a key was pressed
	// repeat: non-zero if this is a key repeat
	// https://wiki.libsdl.org/SDL_KeyboardEvent
	//if (e.type == SDL_KEYDOWN)
	static int space = 0;
	static int position = 3;
	//printf("setb=%d\n\n\n", setb);
;

	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{

		//Adjust the velocity
		//keyboard https://wiki.libsdl.org/SDL_Keycode
		/*
		if (e.key.keysym.sym == SDLK_o) {
			printf("Bullet shoot\n");
			switch (position) {

			case 1:
				while (At.hit() != 1) At.setVY(At.getVY() - VELOCITY);
				break;

			case 2:
				while (At.hit() != 1) At.setVY(At.getVY() + VELOCITY);
				break;
			case 3:
				while (At.hit() != 1) At.setVX(At.getVX() - VELOCITY);
				break;
			case 4:
				while (At.hit() != 1) At.setVX(At.getVX() + VELOCITY);
				break;

			}
		}
		//if (e.key.keysym.sym == SDLK_KP_ENTER) {
			//At.weaponMove(1);
		//}
		//if(setb==0)At.setPosition(Ro.Posx, Ro.Posy);
		switch (e.key.keysym.sym)
		{
			int bp[12][16];
		case SDLK_UP: Ro.setVY(Ro.getVY() - VELOCITY); if (setb == 0)At.setVY(At.getVY() - VELOCITY); position = 1;  break;
		case SDLK_DOWN: Ro.setVY(Ro.getVY() + VELOCITY); if (setb == 0)At.setVY(At.getVY() + VELOCITY); position = 2;  break;
		case SDLK_LEFT: Ro.setVX(Ro.getVX() - VELOCITY); if (setb == 0)At.setVX(At.getVX() - VELOCITY); position = 3;  break;
		case SDLK_RIGHT: Ro.setVX(Ro.getVX() + VELOCITY); if (setb == 0)At.setVX(At.getVX() + VELOCITY); position = 4;  break;
		case SDLK_p:b.setBomb((Ro.Posx + M_WIDTH / 2 - EDGE) / 50, (Ro.Posy + M_HEIGHT / 2) / 50, bp); space = 1;
			g.bombhere(bp);
			break;
		}
		/*
		switch (e.key.keysym.sym){
			
		case SDLK_i:At.setVY(At.getVY() - VELOCITY); space = 2; break;
		case SDLK_k:At.setVY(At.getVY() + VELOCITY); space = 2; break;
		case SDLK_j:At.setVX(At.getVX() - VELOCITY); space = 2; break;
		case SDLK_l:At.setVX(At.getVX() + VELOCITY); space = 2; break;
			//可能要減掉EDGE
		
		}
	}


	else if (e.type == SDL_KEYUP )//&& e.key.repeat == 0)
	{
		space = 0;

		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:    Ro.setVY(Ro.getVY() + VELOCITY); if (setb == 0)At.setVY(At.getVY() + VELOCITY); break;
		case SDLK_DOWN:  Ro.setVY(Ro.getVY() - VELOCITY); if (setb == 0)At.setVY(At.getVY() - VELOCITY); break;
		case SDLK_LEFT:  Ro.setVX(Ro.getVX() + VELOCITY); if (setb == 0)At.setVX(At.getVX() + VELOCITY); break;
		case SDLK_RIGHT: Ro.setVX(Ro.getVX() - VELOCITY); if (setb == 0)At.setVX(At.getVX() - VELOCITY); break;
		}
	}
	return space;

}*/
void handleEvent1b(SDL_Event& e, Role& R1, Role& R2, Bullet& At, Grass& g, int &setb);
void handleEvent1b(SDL_Event& e, Role& R1, Role& R2, Bullet& At, Grass& g, int &setb) {
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{

		//Adjust the velocity
		//keyboard https://wiki.libsdl.org/SDL_Keycode
		/*
		if (e.key.keysym.sym == SDLK_o) {
			printf("Bullet shoot\n");
			switch (position) {

			case 1:
				while (At.hit() != 1) At.setVY(At.getVY() - VELOCITY);
				break;

			case 2:
				while (At.hit() != 1) At.setVY(At.getVY() + VELOCITY);
				break;
			case 3:
				while (At.hit() != 1) At.setVX(At.getVX() - VELOCITY);
				break;
			case 4:
				while (At.hit() != 1) At.setVX(At.getVX() + VELOCITY);
				break;

			}
		}*/
		//if (e.key.keysym.sym == SDLK_KP_ENTER) {
			//At.weaponMove(1);
		//}
		/*
		switch (e.key.keysym.sym)
		{

		case SDLK_UP:    Ro.setVY(Ro.getVY() - VELOCITY); At.setVY(At.getVY() - VELOCITY); position = 1; break;
		case SDLK_DOWN:  Ro.setVY(Ro.getVY() + VELOCITY); At.setVY(At.getVY() + VELOCITY); position = 2; break;
		case SDLK_LEFT:  Ro.setVX(Ro.getVX() - VELOCITY); At.setVX(At.getVX() - VELOCITY); position = 3; break;
		case SDLK_RIGHT: Ro.setVX(Ro.getVX() + VELOCITY); At.setVX(At.getVX() + VELOCITY); position = 4; break;
		}
		*/
		//At.setVX(0); At.setVY(0);
		switch (e.key.keysym.sym) {
			
		case SDLK_i:At.setPosition(R1.Posx, R1.Posy); At.setVY(At.getVY() - VELOCITY); setb = 1; break;//space = 2; break;
		case SDLK_k:At.setPosition(R1.Posx, R1.Posy); At.setVY(At.getVY() + VELOCITY); setb = 1; break;//space = 2; break;
		case SDLK_j:At.setPosition(R1.Posx, R1.Posy); At.setVX(At.getVX() - VELOCITY); setb = 1; break;//space = 2; break;
		case SDLK_l:At.setPosition(R1.Posx, R1.Posy); At.setVX(At.getVX() + VELOCITY); setb = 1; break;//space = 2; break;
			//可能要減掉EDGE
		}
		
		if ((At.Posx >= R2.Posx && At.Posx <= (R2.Posx + M_WIDTH)) && (At.Posy >= R2.Posy && At.Posy <= (R2.Posy + M_HEIGHT))) {
			setb = 0;
			
			At.setPosition(R1.Posx, R1.Posy);
		}
	}
	/*
	else if (e.type == SDL_KEYUP)//&& e.key.repeat == 0)
	{
		

		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_w:    At.setVY(At.getVY() + VELOCITY); break;
		case SDLK_s:  At.setVY(At.getVY() - VELOCITY); break;
		case SDLK_a:  At.setVX(At.getVX() + VELOCITY); break;
		case SDLK_d: At.setVX(At.getVX() - VELOCITY); break;
		}
	}*/
	//return space;

}




/*
int handleEvent2(SDL_Event& e, Role& Ro, Bomb& b, Bullet& At, Grass& g, int setb, int bhit);//上下左右
int handleEvent2(SDL_Event& e, Role& Ro, Bomb& b, Bullet& At, Grass& g, int setb, int bhit)
{
	/* The method for "Debunce" 

	// If a key was pressed
	// repeat: non-zero if this is a key repeat
	// https://wiki.libsdl.org/SDL_KeyboardEvent-*
	//if (e.type == SDL_KEYDOWN)
	static int space = 0;
	static int position = 3;
	if (setb == 1 || (bhit == 1 && space != 2)) {
		At.setPosition(Ro.Posx, Ro.Posy);
		At.setVX(0); At.setVY(0);
	}
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		//keyboard https://wiki.libsdl.org/SDL_Keycode

		switch (e.key.keysym.sym)
		{
			int bp[12][16];
		case SDLK_w: Ro.setVY(Ro.getVY() - VELOCITY); At.setVY(At.getVY() - VELOCITY); position = 1; space = 0; break;
		case SDLK_s: Ro.setVY(Ro.getVY() + VELOCITY); At.setVY(At.getVY() + VELOCITY); position = 2; space = 0; break;
		case SDLK_a: Ro.setVX(Ro.getVX() - VELOCITY); At.setVX(At.getVX() - VELOCITY); position = 3; space = 0; break;
		case SDLK_d: Ro.setVX(Ro.getVX() + VELOCITY); At.setVX(At.getVX() + VELOCITY); position = 4; space = 0; break;
		case SDLK_g: At.setVY(At.getVY() - VELOCITY); space = 2; break;
		case SDLK_b: At.setVY(At.getVY() + VELOCITY); space = 2; break;
		case SDLK_v: At.setVX(At.getVX() - VELOCITY); space = 2; break;
		case SDLK_n: At.setVX(At.getVX() + VELOCITY); space = 2; break;
		case SDLK_r: b.setBomb((Ro.Posx+M_WIDTH/2-EDGE) / 50, (Ro.Posy+M_HEIGHT/2) / 50, bp); space = 1;
			g.bombhere(bp);
			break;
		}
	
	}

	else if (e.type == SDL_KEYUP)// && e.key.repeat == 0)
	{
		space = 0;
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_w: Ro.setVY(Ro.getVY() + VELOCITY); At.setVY(At.getVY() + VELOCITY); break;
		case SDLK_s: Ro.setVY(Ro.getVY() - VELOCITY); At.setVY(At.getVY() - VELOCITY); break;
		case SDLK_a: Ro.setVX(Ro.getVX() + VELOCITY); At.setVX(At.getVX() + VELOCITY); break;
		case SDLK_d: Ro.setVX(Ro.getVX() - VELOCITY); At.setVX(At.getVX() - VELOCITY); break;
		}
	}
	return space;
	/*
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{At.setVY(At.getVY() - VELOCITY);
		 At.setVY(At.getVY() + VELOCITY);
		 At.setVX(At.getVX() - VELOCITY);
		 At.setVX(At.getVX() + VELOCITY);
			int space = 0;
			//Adjust the velocity
			//keyboard https://wiki.libsdl.org/SDL_Keycode
			/*
			switch (e.key.keysym.sym)
			{
			case SDLK_w:Ro.movePosition(0, -50, 1); At.weaponPosition(Ro); space = 0; break;
			case SDLK_s:Ro.movePosition(0, 50, 2); At.weaponPosition(Ro); space = 0; break;
			case SDLK_a:Ro.movePosition(-50, 0, 3); At.weaponPosition(Ro); space = 0; break;
			case SDLK_d:Ro.movePosition(50, 0, 4); At.weaponPosition(Ro); space = 0; break;
			case SDLK_f:At.weaponMove(1); break;
			case SDLK_r:b.setPosition(Ro.Posx - 60, Ro.Posy - 80); space = 1; printf("bomb!\n"); break;
			}

			return space;

		}
		
}
*/