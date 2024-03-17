#include "system.h"
#include "Mouse.h"

Mouse mouse;
void mouseKeyEvent(SDL_Event* e)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEWHEEL)
	{
		{
			static int lasttime = SDL_GetTicks();
			static int curtime = SDL_GetTicks();
			int timediv;

			lasttime = curtime;
			curtime = SDL_GetTicks();
			timediv = curtime - lasttime;

			switch (e->type)
			{
			case SDL_MOUSEBUTTONDOWN:
				if (e->button.button == SDL_BUTTON_LEFT) { mouse.lstate = L_C; }
				if (e->button.button == SDL_BUTTON_RIGHT) { mouse.rstate = R_C; }
				if (e->button.button == SDL_BUTTON_MIDDLE) mouse.mstate = M_C;
				break;

			case SDL_MOUSEBUTTONUP:
				if (e->button.button == SDL_BUTTON_LEFT) mouse.lstate = L_R;
				if (e->button.button == SDL_BUTTON_RIGHT) mouse.rstate = R_R;
				if (e->button.button == SDL_BUTTON_MIDDLE) mouse.mstate = M_R;
				break;
			case SDL_MOUSEWHEEL:
				if (e->wheel.y > 0) mouse.mstate = M_U;
				else if (e->wheel.y < 0) mouse.mstate = M_D;
				break;
			}
		}
	}
}
void MouseRefreshState()
{
	SDL_GetMouseState(&mouse.x, &mouse.y);

	if (mouse.lstate == L_R)
	{
		mouse.lcon = true;
		mouse.lstate = L_N;
	}
	else if (mouse.lstate == L_C) mouse.lcon = false;
	if (mouse.rstate == R_R)
	{
		mouse.rcon = true;
		mouse.rstate = R_N;
	}
	else if (mouse.rstate == R_R) mouse.rcon = false;

	if (mouse.mstate == M_R)
	{
		mouse.mcon = true;
		mouse.mstate = M_N;
	}
	else if (mouse.mstate == L_C) mouse.mcon = false;
}
void mouseHandleEvent(SDL_Event* e, MouseState* mouseState)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEWHEEL)
	{	
		SDL_GetMouseState(&mouse.x, &mouse.y);




		static int lasttime = SDL_GetTicks();
		static int curtime = SDL_GetTicks();
		int timediv;

		lasttime = curtime;
		curtime = SDL_GetTicks();
		timediv = curtime - lasttime;

		switch (e->type)
		{
		case SDL_MOUSEBUTTONDOWN:

			if (e->button.button == SDL_BUTTON_LEFT && e->button.clicks == 1 && timediv < 800 && timediv > 100)
			{
				*mouseState = IN_LB_SC;
			}
			break;

		case SDL_MOUSEBUTTONUP:
			break;

		case SDL_MOUSEWHEEL:
			if (e->wheel.y > 0) // scroll up
			{
				mouse.y = e->wheel.y;
				*mouseState = IN_WU;
			}
			else if (e->wheel.y < 0) // scroll down
			{
				mouse.y = e->wheel.y;
				*mouseState = IN_WD;
			}
			break;

		case SDL_MOUSEMOTION:
			*mouseState = HOVER;
			if (e->button.button == SDL_BUTTON_LEFT)
			{
				*mouseState = IN_LB_PR_HOVER;
			}
			break;
		}

	}
}
void MouseDraw() {
	Role candy("../image/background/candy.png", 1, 1, 1, renderer);
	candy.setPosition(mouse.x - 15, mouse.y - 25);
	candy.draw();
}