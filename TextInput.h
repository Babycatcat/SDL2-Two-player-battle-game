#pragma once
#include "Text.h"

class TextInput
{
public:
	TextInput();
	TextInput(Text t);
	char* edit(SDL_Event& e);
	void generateTexture();
	void setText(char* s);
	void setPos(SDL_Point p);
	int getWidth();
	void draw();
	void draw(SDL_Renderer* renderer, SDL_Point pos);
	void close();

private:
	Text text;
};

