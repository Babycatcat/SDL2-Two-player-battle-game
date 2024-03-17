#pragma once
#include "system.h"
#include"Image.h"
#include"Role.h"

enum MouseState
{
	NONE = 0,
	OUT = 1, // Mouse out
	IN_LB_SC = 2,  // Inside, Left Button, Single Click
	IN_RB_SC = 3,  // Inside, RIGHT Button, Single Click
	//IN_LB_DC = 4,  // Inside, Left Button, Double Click
	//IN_RB_DC = 5,  // Inside, RIGHT Button, Double Click
	IN_LB_PR = 6,  // Inside, Left Button, Press
	IN_RB_PR = 7,  // Inside, Left Button, Press
	IN_WU = 8,  // Inside, Wheel UP
	IN_WD = 9,  // Inside, Wheel DOWN
	HOVER = 10, // Mouse hover
	IN_LB_PR_HOVER = 11 // Inside, Left Button, Press, Hover
};
enum Mouse_State_L
{
	L_N, //none
	L_C,  //click
	L_R //release

};
enum Mouse_State_R
{
	R_N,
	R_C,
	R_R

};
enum Mouse_State_M
{
	M_N,
	M_C,
	M_R,
	M_U,
	M_D
};
struct Mouse {

	//Role candy("../image/background/candy.png", 1, 1, 1, renderer);
	int x, y;
	bool lcon = true;
	bool rcon = true;
	bool mcon = true;
	Mouse_State_L lstate = L_N;
	Mouse_State_R rstate = R_N;
	Mouse_State_M mstate = M_N;

};
extern Mouse mouse;
void MouseRefreshState();
void mouseKeyEvent(SDL_Event* e);
void mouseHandleEvent(SDL_Event* e, MouseState* mouseState);
void MouseDraw();