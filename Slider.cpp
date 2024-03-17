#include"slider.h"
#include"button.h"
#include"mouse.h"
void SliderInit(Slider& slider, int orx, int ory, int orw, int orh, int w, int h) {
	slider.orx = orx;
	slider.ory = ory;
	slider.orh = orh;
	slider.orw = orw;
	slider.cx = orx;
	slider.cy = ory - orh / 2 + h / 2;
	slider.h = h;
	slider.w = w;
}
void SliderDetect(Slider& slider) {
	if (slider.state == S_Up || slider.state == S_Down)
		slider.state = Idle;
	if (mouse.x<slider.cx + slider.w / 2 && mouse.x>slider.cx - slider.w / 2 && mouse.y<slider.cy + slider.h / 2 && mouse.y>slider.cy - slider.h / 2) {
		if (mouse.lstate == L_C && mouse.lcon == true && slider.state == Idle) {
			slider.state = Pulled;
			slider.cy = mouse.y;
		}
		else if (mouse.lstate == L_C && slider.state == Pulled) {
			slider.cy = mouse.y;
		}
	}
	else
		if (mouse.lstate == L_N) slider.state = Idle;
		else if (mouse.lstate == L_C && slider.state == Pulled) {
			slider.state = Pulled;
			slider.cy = mouse.y;
		}
		else if (mouse.lstate == L_R && slider.state == Pulled) slider.state = Idle;
	if (mouse.mstate != Pulled)
		if (mouse.mstate == M_U) {
			slider.state = S_Up;
			slider.cy -= 40;
		}
		else if (mouse.mstate == M_D) {
			slider.state = S_Down;
			slider.cy += 40;
		}
	if (slider.state == Pulled || slider.state == S_Up || slider.state == S_Down) {
		if (slider.cy < slider.ory - slider.orh / 2 + slider.h / 2) slider.cy = slider.ory - slider.orh / 2 + slider.h / 2;
		else if (slider.cy > slider.ory + slider.orh / 2 - slider.h / 2) slider.cy = slider.ory + slider.orh / 2 - slider.h / 2;
	}
}
void BarDetect(Slider& slider, int num) {
	if (slider.state == S_Up || slider.state == S_Down)
		slider.state = Idle;
	if (mouse.y<slider.cy + slider.h / 2 && mouse.y>slider.cy - slider.h / 2 && mouse.x<slider.cx + slider.w / 2 && mouse.x>slider.cx - slider.w / 2) {
		if (mouse.lstate == L_C && mouse.lcon == true && slider.state == Idle) {
			slider.state = Pulled;
			slider.cx = mouse.x;
		}
		else if (mouse.lstate == L_C && slider.state == Pulled) {
			slider.cx = mouse.x;
		}
	}
	else {
		if (mouse.lstate == L_N) slider.state = Idle;
		else if (mouse.lstate == L_C && slider.state == Pulled) {
			slider.state = Pulled;
			slider.cx = mouse.x;
			//if (num == 0)
			//	Mix_VolumeMusic((slider.cx - 375) * 0.4);
			//else
			//	Mix_Volume(-1, (slider.cx - 375) * 0.4);
		}
		else if (mouse.lstate == L_R && slider.state == Pulled) slider.state = Idle;

		if (slider.state == Pulled || slider.state == S_Up || slider.state == S_Down) {
			if (slider.cx < slider.orx - slider.orw / 2 + slider.w / 2) slider.cx = slider.orx - slider.orw / 2 + slider.w / 2;
			else if (slider.cx > slider.orx + slider.orw / 2 - slider.w / 2) slider.cx = slider.orx + slider.orw / 2 - slider.w / 2;
		}
	}

}
void SliderDraw(Slider& slider) {
	SDL_RendererFlip no = SDL_FLIP_NONE;
	int alpha = 255;
	if (slider.state == Idle)
		alpha = 20;
	else
		alpha = 255;
	boxRGBA(renderer, slider.orx - slider.orw / 2, slider.ory - slider.orh / 2, slider.orx + slider.orw / 2, slider.ory + slider.orh / 2, 0, 0, 0, 255);
	boxRGBA(renderer, slider.cx - slider.w / 2, slider.cy - slider.h / 2, slider.cx + slider.w / 2, slider.cy + slider.h / 2, 255, 255, 255, 255);
}