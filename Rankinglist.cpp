#define _CRT_SECURE_NO_WARNINGS
#include"rankinglist.h"
#include"slider.h"
#include"text.h"
#include"image.h"
#include"mouse.h"
#include"button.h"
#include"System.h"
#include"Menu.h"
void RankingList(int* dijits) {

	printf("dijits=%d\n", *dijits);
	SDL_SetRenderDrawColor(renderer, 255, 228, 181, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	Button b_back;
	b_back.ButtonInit("BACK", 10, 30, 130, 40);

	bool quit = false;
	printf("%d\n", quit);
	FILE* fp;
	char s[100];
	Text w0("ANYA", "../fonts/akabara-cinderella.ttf", 50, TTF_STYLE_NORMAL, { 98,91,87 }, BLENDED, { NULL, NULL, NULL }, renderer, { 180, 50 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	Text w1("WAKUWAKU", "../fonts/akabara-cinderella.ttf", 50, TTF_STYLE_NORMAL, { 98,91,87 }, BLENDED, { NULL, NULL, NULL }, renderer, { 180, 50 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	Text w2("HAHA", "../fonts/akabara-cinderella.ttf", 50, TTF_STYLE_NORMAL, { 98,91,87 }, BLENDED, { NULL, NULL, NULL }, renderer, { 180, 50 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	Text w3("CHICHI", "../fonts/akabara-cinderella.ttf", 50, TTF_STYLE_NORMAL, { 98,91,87 }, BLENDED, { NULL, NULL, NULL }, renderer, { 180, 50 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	Text w4("FAMILY", "../fonts/akabara-cinderella.ttf", 50, TTF_STYLE_NORMAL, { 98,91,87 }, BLENDED, { NULL, NULL, NULL }, renderer, { 180, 50 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);

	fp = fopen("rankinglist.txt", "r");
	int i = 0;
	//printf("%s", fp);
	if (fp != NULL)
	{
		while (fscanf(fp, "%s ", &s) != EOF)
		{
			printf("%s\n", s);
			switch (i % 5)
			{
			case(0):
				w0.setString(s);
				w0.setPos({ 500,200 });
				w0.generateTexture();
				break;
			case(1):
				w1.setString(s);
				w1.setPos({ 500, 270 });
				w1.generateTexture();
				break;
			case(2):
				w2.setString(s);
				w2.setPos({ 500, 340 });
				w2.generateTexture();
				break;
			case(3):
				w3.setString(s);
				w3.setPos({ 500, 410 });
				w3.generateTexture();
				break;
			case(4):
				w4.setString(s);
				w4.setPos({ 500, 480 });
				w4.generateTexture();
				break;
			}
			i++;
		}
		fclose(fp);
	}
	Text textPrompt("WINNER'S NAME:", "../fonts/TaipeiSansTCBeta-Regular.ttf", 70, TTF_STYLE_UNDERLINE, { 101,81,82 }, BLENDED, { NULL, NULL, NULL }, renderer, { 400, 100 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	textPrompt.setPos({ (WIDTH - textPrompt.getWidth()) / 2, 50 });
	textPrompt.generateTexture();
	while (!quit)
	{
		SDL_Event e;
		MouseRefreshState();
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			mouseKeyEvent(&e);
		}
		b_back.Buttondetect();

		// Clear screen
		SDL_RenderClear(renderer);
		w0.draw();
		w1.draw();
		w2.draw();
		w3.draw();
		w4.draw();
		textPrompt.draw();
		b_back.ButtonDraw();
		if (b_back.state == Release) {
			screen = MainMenu;
			quit = true;
			printf("%d\n", quit);
		}
		MouseDraw();
		SDL_RenderPresent(renderer);
	}
	printf("out!!");
	screen = MainMenu;
	textPrompt.close();
	w0.close();
	w1.close();
	w2.close();
	w3.close();
	w4.close();
	b_back.text.close();
}
