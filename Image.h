#pragma once
#include <SDL.h> // Using SDL

class Image
{
public:
	Image();
	Image(const char* path, SDL_Renderer* renderer);
	Image(const char* path, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b);
	void generateTexture();
	void close();
	void draw();
	void draw(SDL_Renderer* renderer, SDL_Rect dst, SDL_Rect src);
	int getWidth();
	int getHeight();

	void setPath(const char* p);
	void setColorKey(SDL_Color c);
	void setRenderer(SDL_Renderer* r);
	void setSrcRegion(SDL_Rect s);
	void setDstRegion(SDL_Rect d);

	//Image loadImgTexture(char* path, int num, int hn, int wn, bool ckEnable, Uint8 r, Uint8 g, Uint8 b);
	//Image loadBackTexture(const char* path, int num, int hn, int wn, bool ckEnable, Uint8 r, Uint8 g, Uint8 b);
	//ImageData loadBackTexture(char* path, int num, int hn, int wn, bool ckEnable, Uint8 r, Uint8 g, Uint8 b);
	//int imgRender(SDL_Renderer* renderer, Image img, int posX, int posY, int frame, int cx, int cy, double angle, SDL_RendererFlip flip, int alpha);


protected:
	char* path;
	SDL_Texture* texture;
	int width;
	int height;
	SDL_Color colorKey;
	SDL_Renderer* renderer;
	SDL_Rect srcRegion;
	SDL_Rect dstRegion;


};



struct ImageData {
	SDL_Texture* texture;
	int width;
	int height;
	int num;
	int wn;
	int hn;

	int x;
	int y;
	int vx;
	int vy;
	int dx;
	int dy;
	int health;
	int fire;
};
ImageData loadImgTexture(char* path, int num, int hn, int wn, bool ckEnable, Uint8 r, Uint8 g, Uint8 b);
ImageData loadBackTexture(const char* path, int num, int hn, int wn, bool ckEnable, Uint8 r, Uint8 g, Uint8 b);
//ImageData loadBackTexture(char* path, int num, int hn, int wn, bool ckEnable, Uint8 r, Uint8 g, Uint8 b);
int imgRender(SDL_Renderer* renderer, ImageData img, int posX, int posY, int frame, int cx, int cy, double angle, SDL_RendererFlip flip, int alpha);
