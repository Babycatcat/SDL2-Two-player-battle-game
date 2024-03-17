#include"choosechar.h"
#include"image.h"
#include"system.h"
#include"menu.h"
SDL_Point a1 = { 350,100 }, c1 = { 380,130 }, b1 = { 320,130 };//left up
SDL_Point a2 = { 350,500 }, c2 = { 380,470 }, b2 = { 320,470 };//left down
SDL_Point a3 = { 830,100 }, c3 = { 800,130 }, b3 = { 860,130 };//right up
SDL_Point a4 = { 830,500 }, c4 = { 800,470 }, b4 = { 860,470 };//right down

void Menu1()
{

	bool quit = false;
	char waffle[100] = "../image/player/wafflebig.png";
	char brownie[100] = "../image/player/bronniebig.png";
	char cake[100] = "../image/player/cakebig.png";
	char cupcake[100] = "../image/player/cupcakebig.png";
	char icecream[100] = "../image/player/icecreambig.png";
	char macaron[100] = "../image/player/macaronbig.png";
	P1 = 0, P2 = 0;
	ImageData w0 = loadImgTexture(waffle, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w1 = loadImgTexture(brownie, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w2 = loadImgTexture(cake, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w3 = loadImgTexture(cupcake, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w4 = loadImgTexture(icecream, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
	ImageData w5 = loadImgTexture(macaron, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);

	Button bu_P1, bu_P2, bd_Pl, bd_P2;
	Button b_enter("ENTER", 1000, 30, 130, 100);
	Button b_back("BACK", 10, 30, 130, 40);
	Text textblended1("Player1", "../fonts/akabara-cinderella.ttf", 30, TTF_STYLE_NORMAL, { 98,91,87 }, BLENDED, { NULL, NULL, NULL }, renderer, { 180, 50 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	Text textblended2 ("Player2", "../fonts/akabara-cinderella.ttf", 30, TTF_STYLE_NORMAL, { 98,91,87 }, BLENDED, { NULL, NULL, NULL }, renderer, { 650, 50 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);

	while (!quit)
	{
		SDL_Event e;
		MouseRefreshState();
		while (SDL_PollEvent(&e) != 0) {
			// User requests quit
			if (e.type == SDL_QUIT) {
				exitgame = true;
				quit = true; // try to comment this line
			}
			mouseKeyEvent(&e);
		}
		b_enter.Buttondetect();
		b_back.Buttondetect();
		bu_P1.SwitchButtonDetect(340, 135, 30, 0, 0);
		bu_P2.SwitchButtonDetect(820, 135, 30, 0, 0);
		if (bu_P1.state == Pressed) {
			P1 = bu_P1.chara;
			bd_Pl.chara = bu_P1.chara;
		}
		if (bu_P2.state == Pressed) {
			P2 = bu_P2.chara;
			bd_P2.chara = bu_P2.chara;
		}
		
		bd_Pl.SwitchButtonDetect(340, 470, 50, 1, 0);
		bd_P2.SwitchButtonDetect(820, 465, 50, 1, 0);
		if (bd_Pl.state == Pressed) {
			P1 = bd_Pl.chara;
		}
		if (bd_P2.state == Pressed) {
			P2 = bd_P2.chara;
		}

		SDL_SetRenderDrawColor(renderer, 255, 228, 181, 255);
		SDL_RenderClear(renderer);
		b_enter.ButtonDraw();
		b_back.ButtonDraw();

		textblended1.draw();
		textblended2.draw();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		rectangleRGBA(renderer, 180, 140, 530, 460, 0, 0, 0, 255);//¥ª¤W
		rectangleRGBA(renderer, 650, 140, 1000, 460, 0, 0, 0, 255);//right up
		SDL_RenderDrawLine(renderer, a1.x, a1.y, b1.x, b1.y);
		SDL_RenderDrawLine(renderer, a1.x, a1.y, c1.x, c1.y);
		SDL_RenderDrawLine(renderer, b1.x, b1.y, c1.x, c1.y);
		SDL_RenderDrawLine(renderer, a2.x, a2.y, b2.x, b2.y);
		SDL_RenderDrawLine(renderer, a2.x, a2.y, c2.x, c2.y);
		SDL_RenderDrawLine(renderer, b2.x, b2.y, c2.x, c2.y);
		SDL_RenderDrawLine(renderer, a3.x, a3.y, b3.x, b3.y);
		SDL_RenderDrawLine(renderer, a3.x, a3.y, c3.x, c3.y);
		SDL_RenderDrawLine(renderer, b3.x, b3.y, c3.x, c3.y);
		SDL_RenderDrawLine(renderer, a4.x, a4.y, b4.x, b4.y);
		SDL_RenderDrawLine(renderer, a4.x, a4.y, c4.x, c4.y);
		SDL_RenderDrawLine(renderer, b4.x, b4.y, c4.x, c4.y);


		if (P1 == 0) {
			imgRender(renderer, w0, 225, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P1 == 1) {
			imgRender(renderer, w1, 225, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P1 == 2) {
			imgRender(renderer, w2, 225, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P1 == 3) {
			imgRender(renderer, w3, 225, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P1 == 4) {
			imgRender(renderer, w4, 225, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P1 == 5)
			imgRender(renderer, w5, 225, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);

		
		if (P2 == 0) {
			imgRender(renderer, w0, 695, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P2 == 1) {
			imgRender(renderer, w1, 695, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P2 == 2) {
			imgRender(renderer, w2, 695, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P2 == 3) {
			imgRender(renderer, w3, 695, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P2 == 4) {
			imgRender(renderer, w4, 695, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		}
		else if (P2 == 5)
			imgRender(renderer, w5, 695, 170, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
		
		if (b_enter.state == Release) {
			screen = Game;
			quit = true;
		}
		if (b_back.state == Release) {
			screen = MainMenu;
			quit = true;
		}
		MouseDraw();
		SDL_RenderPresent(renderer);
	}
	textblended1.close();
	textblended2.close();
	b_enter.text.close();
	b_back.text.close();
	SDL_DestroyTexture(w0.texture);
	SDL_DestroyTexture(w1.texture);
	SDL_DestroyTexture(w2.texture);
	SDL_DestroyTexture(w3.texture);
	SDL_DestroyTexture(w4.texture);
	SDL_DestroyTexture(w5.texture);
}