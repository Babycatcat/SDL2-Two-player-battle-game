#pragma once
#include"system.h"
#include"text.h"
#include"mouse.h"
//#include "audio.h"

enum Bstate { No, Hovered, Pressed, Release };
enum Bdirection { NP, Up, Down };
class Button 
{
public:
	Button();
	Button(const char* s, int x, int y, int w, int h);
	//~Button();
	void ButtonInit(const char* s, int x, int y, int w, int h);
	void SwitchButtonDetect(int x, int y, int r, int dir, int bmp);
	void Buttondetect();
	void ButtonDraw();
	Bstate state;
	Text text;
	int chara;
private:
	int x, y, w, h; 
	Bdirection dir;
	int x1[2];
	int x2[2];
	int x3[2];
	int x4[2];
	int x5[2];
	int x6[2];
};//選單上下鍵
