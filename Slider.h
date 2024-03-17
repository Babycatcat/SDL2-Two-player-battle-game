#pragma once
#include"system.h"
//#include "audio.h"
enum S_Bstate { Idle, Pulled, S_Up, S_Down };
struct Slider {
	int orx, ory, orw, orh;
	int cx, cy, w, h;
	S_Bstate state = Idle;
};
void SliderInit(Slider& slider, int orx, int ory, int orw, int orh, int w, int y);
void SliderDetect(Slider& slider);
void BarDetect(Slider& slider, int num);
void SliderDraw(Slider& slider);