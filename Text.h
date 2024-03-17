#pragma once
#include "system.h"
#include <SDL_ttf.h>


class Text
{
public:
	Text();
	Text(const char* str, const char* fontPath, int fontSize, int style, SDL_Color fgColor, int textType, SDL_Color bgColor, SDL_Renderer* renderer, SDL_Point pos, SDL_Point center, double angle, SDL_RendererFlip flip, int alpha);
	void generateTexture();
	void close();
	void draw();
	void draw(SDL_Renderer* renderer, SDL_Point pos, SDL_Point center, double angle, SDL_RendererFlip flip, int alpha);

	int getWidth();
	int getHeight();
	void TextInit(const char* str, const char* fontPath, int fontSize, int style, SDL_Color fgColor, int textType, SDL_Color bgColor, SDL_Renderer* renderer, SDL_Point pos, SDL_Point center, double angle, SDL_RendererFlip flip, int alpha);
	void setString(const char* s);
	void setFontPath(const char* f);
	void setFontSize(int s);
	void setStyle(int s);
	void setFgColor(SDL_Color fc);
	void setTextType(int t);
	void setBgColor(SDL_Color bc);
	void setRenderer(SDL_Renderer* r);

	void setPos(SDL_Point p);
	void setCenterAngle(SDL_Point c, double a);
	void setFlip(SDL_RendererFlip f);
	void setAlpha(int a);

	/* New in this example */
	char* getString();
	/***********************/
	int width;
	int height;

private:
	// texture data member
	SDL_Texture* texture;
	

	// font data member
	char* str;
	char* fontPath;
	int fontSize;
	int style;
	SDL_Color fgColor;
	int textType;
	SDL_Color bgColor;
	SDL_Renderer* renderer;

	// Display data member
	SDL_Point pos;
	SDL_Point center;
	double angle;
	SDL_RendererFlip flip;
	int alpha;
}; 
enum TextType { SOLID, BLENDED, SHADED };
/*struct TextData
{
	SDL_Texture* texture;
	int width;
	int height;
};
enum TextType { SOLID, BLENDED, SHADED };
TextData loadTextTexture(const char* str, const char* fontPath, int fontSize, Uint8 fr, Uint8 fg, Uint8 fb, TextType textType, Uint8 br, Uint8 bg, Uint8  bb);
int textRender(SDL_Renderer* renderer, TextData text, int posX, int posY, int cx, int cy, double angle, SDL_RendererFlip flip, int alpha);
*/