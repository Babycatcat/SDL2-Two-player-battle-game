#include"menu.h"
#include"image.h"
#include"button.h"
#include"system.h"
#include"text.h"
void Menu()
{
	bool quit = false;
	Button b_rankinglist("RANKINGLIST", WIDTH / 2 - 200, 220, 400, 80);
	Button b_enter("START", WIDTH / 2 - 100, 300, 200, 80);
	Button b_quit("EXIT", WIDTH / 2 - 65, 380, 130, 80);

	char deco0[100] = "../image/background/house.png";
	char deco1[100] = "../image/background/grass.png";
	char waffle[100] = "../image/background/waffle.png";
	char brownie[100] = "../image/background/bronnie.png";
	char cake[100] = "../image/background/cake.png";
	char cupcake[100] = "../image/background/cupcake.png";
	char icecream[100] = "../image/background/icecream.png";
	char macaron[100] = "../image/background/macaron.png";
	char ginger[100] = "../image/background/ginger.png";
	ImageData w0 = loadImgTexture(waffle, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w1 = loadImgTexture(brownie, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w2 = loadImgTexture(cake, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w3 = loadImgTexture(cupcake, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w4 = loadImgTexture(icecream, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w5 = loadImgTexture(macaron, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w6 = loadImgTexture(deco0, 1, 1, 1, true, 1, 0xFF, 0xFF);
	ImageData w7 = loadImgTexture(deco1, 1, 1, 1, true, 1, 0xFF, 0xFF);
	ImageData w8 = loadImgTexture(ginger, 1, 1, 1, true, 1, 0xFF, 0xFF);

	bool textFlag;
	SDL_StartTextInput();
	while (!quit)
	{
		SDL_Event e;
		MouseRefreshState();
		textFlag = false;
		while (SDL_PollEvent(&e) != 0)
		{

			switch (e.type)
			{
			case SDL_QUIT: // User requests quit
				quit = true;
				exitgame = true;
				break;
			}
			mouseKeyEvent(&e);
		}

		b_enter.Buttondetect();
		b_rankinglist.Buttondetect();
		b_quit.Buttondetect();

		if (b_enter.state == Release) {
			screen = Choosechar;
			quit = true;
		}
		else if (b_rankinglist.state == Release) {
			screen = Ranking;
			quit = true;
		}
		else if (b_quit.state == Release) {
			quit = true;
			exitgame = true;
		}
		SDL_SetRenderDrawColor(renderer, 255, 228, 181, 255);
		SDL_RenderClear(renderer);

		b_enter.ButtonDraw();
		b_rankinglist.ButtonDraw();
		b_quit.ButtonDraw();
		Role lolid("../image/background/loli.png", 10, 2, 5, renderer);
		imgRender(renderer, w0, 200, 450, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		imgRender(renderer, w1, 260, 100, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		imgRender(renderer, w2, 375, 450, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		imgRender(renderer, w3, 460, 100, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		imgRender(renderer, w4, 575, 450, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		imgRender(renderer, w5, 660, 100, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		imgRender(renderer, w6, 790, 100, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		imgRender(renderer, w8, 775, 380, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		imgRender(renderer, w7, 775, 450, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		lolid.setPosition(880, -60);
		lolid.draw();
		MouseDraw();
		SDL_RenderPresent(renderer);
	}
	SDL_StopTextInput();
	b_enter.text.close();
	b_rankinglist.text.close();
	b_quit.text.close();
	SDL_DestroyTexture(w0.texture);
	SDL_DestroyTexture(w1.texture);
	SDL_DestroyTexture(w2.texture);
	SDL_DestroyTexture(w3.texture);
	SDL_DestroyTexture(w4.texture);
	SDL_DestroyTexture(w5.texture);
	SDL_DestroyTexture(w6.texture);
	SDL_DestroyTexture(w7.texture);
	SDL_DestroyTexture(w8.texture);
}