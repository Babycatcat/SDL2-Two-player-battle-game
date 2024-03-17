#include"pausemenu.h"
#include"Button.h"
#include"text.h"

PauseMenu::PauseMenu(){}

PauseMenu::PauseMenu(int cxx, int cyy, int ww, int hh) {
	cx = cxx;
	cy = cyy;
	w = ww;
	h = hh;
}

void PauseMenu::PauseMenuInit(int cxx, int cyy, int ww, int hh) {
	cx = cxx;
	cy = cyy;
	w = ww;
	h = hh;
	b_resume.ButtonInit("Resume", 433, 400, 70, 70);
	b_restart.ButtonInit("Restart", 556, 400, 70, 70);
	b_exit.ButtonInit("EXIT", 699, 400, 70, 70);
}

void PauseMenu::PauseMenuOn(bool& quit) {
	b_resume.Buttondetect();
	b_restart.Buttondetect();
	b_exit.Buttondetect();
	if (b_resume.state == Release && pause == true) {
		pause = false;
	}
	else if (b_restart.state == Release && pause == true) {
		screen = Choosechar;
		pause = false;
		quit = true;
	}
	else if (b_exit.state == Release && pause == true) {
			screen = MainMenu;
		pause = false;
		quit = true;
	}
}

void PauseMenu::PauseMenuDraw() {
	Text textblended1("GAME ", "../fonts/akabara-cinderella.ttf", 70, TTF_STYLE_NORMAL, { 101,81,82 }, BLENDED, { NULL, NULL, NULL }, renderer, { 495, 200 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	Text textblended2("PAUSE", "../fonts/akabara-cinderella.ttf", 70, TTF_STYLE_NORMAL, { 101,81,82 }, BLENDED, { NULL, NULL, NULL }, renderer, { 490, 270}, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	boxRGBA(renderer, 400, 150, 800, 500, 154, 154, 154, 255);
	boxRGBA(renderer, 425, 380, 525, 450, 255, 246, 143, 255);
	boxRGBA(renderer, 550, 380, 650, 450, 255, 246, 143, 255);
	boxRGBA(renderer, 675, 380, 775, 450, 255, 246, 143, 255);
	textblended1.draw();
	textblended2.draw();
	b_resume.ButtonDraw();
	b_restart.ButtonDraw();
	b_exit.ButtonDraw();
}

PauseMenu::~PauseMenu() {
	b_resume.text.close();
	b_restart.text.close();
	b_exit.text.close();
}
