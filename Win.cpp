#include"Win.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h> // Using SDL
#include <SDL2_gfxPrimitives.h> // Using SDL2_gfx
#include <SDL_image.h>
#include "RenderWindow.h"
#include <SDL_ttf.h> // Using truetype font
#include "system.h"
#include<string.h>

/* New in this example*/
#include "System.h"
#include "Text.h"
#include "TextInput.h"

void win(int* dijits)
{
	Text name(" ", "../fonts/lazy.ttf", 50, TTF_STYLE_NORMAL, { 0,0,0 }, BLENDED, { NULL, NULL, NULL }, renderer, { 100, 550 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	Text textPrompt("Enter Your Name:", "../fonts/TaipeiSansTCBeta-Regular.ttf", 70, TTF_STYLE_UNDERLINE, { 101,81,82 }, BLENDED, { NULL, NULL, NULL }, renderer, { 400, 100 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	Text win("You Win!!!", "../fonts/TaipeiSansTCBeta-Regular.ttf", 150, TTF_STYLE_NORMAL, { 101,81,82 }, BLENDED, { NULL, NULL, NULL }, renderer, { 400, 100 }, { NULL, NULL }, NULL, SDL_FLIP_NONE, 255);
	TextInput tin(name);
	name.close();

	textPrompt.setPos({ (WIDTH - textPrompt.getWidth()) / 2, 50 });
	win.setAlpha(100);
	win.setPos({ (WIDTH - win.getWidth()) / 2, 250 });
	textPrompt.generateTexture();
	win.generateTexture();

	bool quit = false;
	SDL_Event e;
	char c[] = " ";
	char* s = c;
	SDL_StartTextInput();
	SDL_SetRenderDrawColor(renderer, 255, 228, 181, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	FILE* rkl, * rklb;
	fopen_s(&rkl, "rankinglist.txt", "a");
	fopen_s(&rklb, "rankinglist.dat", "wb");


	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			tin.setPos({ (WIDTH - tin.getWidth()) / 2, 550 });
			s = tin.edit(e);
			if (e.key.keysym.sym == SDLK_RETURN)
			{
				quit = true;
				break;
			}
		}

		// Clear screen
		SDL_RenderClear(renderer);

		textPrompt.draw();
		win.draw();
		tin.draw();

		// Update screen
		SDL_RenderPresent(renderer);
	}
	if (rkl)
	{
		fputs(s, rkl);
		fputs("\n", rkl);
		fclose(rkl);
	}
	if (rklb)
	{
		fseek(rklb, sizeof(s) * (*dijits), SEEK_SET);
		fwrite(&s, sizeof(s), 1, rklb);
		(*dijits)++;
		fclose(rklb);
	}
	screen = MainMenu;
	name.close();
	textPrompt.close();
	win.close();
	tin.close();
}