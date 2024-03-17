#pragma once
#include"system.h"
#include"Button.h"
#include"menu.h"
#include"game.h"
//#include "audio.h"


class PauseMenu
{
public:
	PauseMenu();	
	PauseMenu(int cx, int cy, int w, int h);
	void PauseMenuInit(int cx, int cy, int w, int h);
	void PauseMenuOn(bool& quit);
	void PauseMenuDraw();
	//void PauseMenuFree();
	~PauseMenu();
	Button b_resume;
	Button b_restart;
	Button b_exit;
private:
	int cx, cy, w, h;
};