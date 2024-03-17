#include "TextInput.h"
#include <string.h>
#include <iostream>

using namespace std;

TextInput::TextInput(){}

TextInput::TextInput(Text t)
{
	text = t;
	text.setString(" ");
	text.generateTexture();
}

char* TextInput::edit(SDL_Event& e)
{
	bool textFlag = false;
	char* str = new char[strlen(text.getString()) + 1]();  // must be initialized with ()
	strcpy_s(str, strlen(text.getString()) + 1, text.getString());

	switch (e.type)
	{
	case SDL_KEYDOWN: // Special key input
		if (e.key.keysym.sym == SDLK_BACKSPACE && strlen(str) > 0)
		{
			str[strlen(str) - 1] = '\0';
			textFlag = true;
		}
		else if (e.key.keysym.sym == SDLK_c && (SDL_GetModState() & KMOD_CTRL))
		{
			SDL_SetClipboardText(str + 1); // the first element is " "			
		}
		else if (e.key.keysym.sym == SDLK_v && (SDL_GetModState() & KMOD_CTRL))
		{
			char* strtmp = new char[strlen(str) + strlen(SDL_GetClipboardText()) + 1]();
			strcpy_s(strtmp, strlen(str) + 1, str);
			strcat_s(strtmp, strlen(str) + strlen(SDL_GetClipboardText()) + 1, SDL_GetClipboardText());
			str = strtmp;
			textFlag = true;
		}
		break;

	case SDL_TEXTINPUT: // Special text input event
		if (!((SDL_GetModState() & KMOD_CTRL) && (e.text.text[0] == 'c' || e.text.text[0] == 'C' || e.text.text[0] == 'v' || e.text.text[0] == 'V')))
		{
			char* strtmp = new char[strlen(str) + strlen(e.text.text) + 1]();
			strcpy_s(strtmp, strlen(str) + 1, str);
			
			strcat_s(strtmp, strlen(str) + strlen(e.text.text) + 1, e.text.text);
			str = strtmp;
			textFlag = true;
		}
		break;
	}

	cout << str << endl;
	if (textFlag)
	{
		if (strcmp(str, "") != 0)
		{
			setText(str);
			generateTexture();
		}
		else
		{
			strcpy_s(str, 2, " ");
			setText(str);
			generateTexture();
		}
	}
	return str;
}


void TextInput::generateTexture()
{
	text.generateTexture();
}

void TextInput::setText(char* s)
{
	text.setString(s);
}

void TextInput::setPos(SDL_Point p)
{
	text.setPos(p);
}

int TextInput::getWidth()
{
	return text.getWidth();
}

void TextInput::draw()
{
	text.draw();
}

void TextInput::draw(SDL_Renderer* ren, SDL_Point pos)
{
	text.setRenderer(ren);
	text.setPos(pos);
	draw();
}

void TextInput::close()
{
	text.close();
}