#include"Button.h"

Button::Button() {
	chara = 0;
}

Button::Button(const char* s, int xx, int yy, int ww, int hh)
{
	dir = NP;
	state = No;
	chara = 0;
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	if (w == 70 && h == 70)
		text.TextInit(s, "../fonts/akabara-cinderella.ttf", 25, TTF_STYLE_NORMAL, { 0, 0, 0 }, BLENDED, { NULL, NULL, NULL }, renderer, { x, y }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);

	else
		text.TextInit(s, "../fonts/akabara-cinderella.ttf", 60, TTF_STYLE_NORMAL, { 0, 0, 0 }, BLENDED, { NULL, NULL, NULL }, renderer, { x,y }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
}

void Button::ButtonInit(const char* s, int xx, int yy, int ww, int hh)
{
	dir = NP;
	state = No;
	chara = 0;
	x = xx;
	y = yy;
	w = ww;
	h = hh;
	if (w == 70 && h == 70)
		text.TextInit(s, "../fonts/akabara-cinderella.ttf", 25, TTF_STYLE_NORMAL, { 0, 0, 0 }, BLENDED, { NULL, NULL, NULL }, renderer, { x, y }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);

	else
		text.TextInit(s, "../fonts/akabara-cinderella.ttf", 60, TTF_STYLE_NORMAL, {0, 0, 0 }, BLENDED, { NULL, NULL, NULL }, renderer, { x,y}, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
}

void Button::SwitchButtonDetect(int xx, int yy, int rr, int dirr,int bmpp)//(x,y)=上三角底邊中點,r=三角形的高&底邊的一半,dir(0上1下)
{
	const int n = 6;//角色數量
	x1[0] = xx - rr;
	x1[1] = yy;
	x2[0] = xx + rr;
	x2[1] = yy;
	x3[0] = xx;
	x3[1] = yy - rr;
	x4[0] = xx - rr;
	x4[1] = yy;//240是中間圖示大小
	x5[0] = xx + rr;
	x5[1] = yy ;
	x6[0] = xx;
	x6[1] = yy + rr ;
	if (dirr == 0) dir = Up;
	else dir = Down;
	if (dir == Up) {
		if (mouse.y + mouse.x > x1[0] + x1[1] && mouse.y - mouse.x > x2[1] - x2[0] && mouse.y < x1[1]) {
			if (mouse.lstate == L_C && mouse.lcon == true && state == Hovered) {
				state = Pressed;
				chara = (chara - 1 + n) % n;//角色有幾個
			}
			else if (mouse.lstate == L_R && state == Pressed) state = No;
			else if (mouse.lstate == L_N && state == No) state = Hovered;
			else if (mouse.lstate == L_C && state == No && mouse.lcon == false) state = Hovered;
		}
		else {
			state = No;
		}
	}
	else if (dir == Down) {
		if (mouse.y + mouse.x < x5[0] + x5[1] && mouse.y - mouse.x < x4[1] - x4[0] && mouse.y > x5[1])
		{
			if (mouse.lstate == L_C && mouse.lcon == true && state == Hovered) {
				state = Pressed;
				chara = (chara + 1) % n;//角色有幾個
			}
			else if (mouse.lstate == L_R && state == Pressed) state = No;
			else if (mouse.lstate == L_N && state == No) state = Hovered;
			else if (mouse.lstate == L_C && state == No && mouse.lcon == false) state = Hovered;
		}
		else
		{
			state = No;
		}
	}
}


void Button::Buttondetect()
{
	if (mouse.x > x && mouse.x<x + w && mouse.y>y && mouse.y < y + h) {

		if (mouse.lstate == L_C && mouse.lcon == true && state == Hovered) { state = Pressed; /*Mix_PlayChannel(-1, eclick, 0); */
		}
		else if (mouse.lstate == L_R && state == Pressed) state = Release;
		else if (mouse.lstate == L_N && state == No) state = Hovered;
		else if (mouse.lstate == L_C && state == No && mouse.lcon == false) state = Hovered;
	}
	else
	{
		if (mouse.lstate == L_N) state = No;
		else if (mouse.lstate == L_C && state == Pressed) { state = Pressed; }
		else if (mouse.lstate == L_R && state == Pressed) state = No;
		else if (state == Hovered) state = No;
	}
}

void Button::ButtonDraw()
{
	SDL_RendererFlip no = SDL_FLIP_NONE;
	int alpha;
	if (state == No)
		text.setAlpha(20);
	else if (state == Hovered)
		text.setAlpha(150);
	else if (state == Pressed)
		text.setAlpha(255);
	else
		text.setAlpha(150);
	text.draw();

}