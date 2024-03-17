#include "Image.h"
#include "SDL_image.h" 
#include <stdio.h>
#include <SDL.h> // Using SDL
#include <string.h>
#include "system.h"


Image::Image()
{
}

Image::Image(const char* path, SDL_Renderer* renderer)
{
	setPath(path);
	setColorKey(NO_TRANSPARENT_BG);
	setRenderer(renderer);

	generateTexture();
}

Image::Image(const char* path, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b)
{
	setPath(path);
	setColorKey({ r ,g , b });
	setRenderer(renderer);
	generateTexture();
}

void Image::generateTexture()
{
	// Load a surface from a PNG file.	
	SDL_Surface* imgSurface = IMG_Load(path);
	if (imgSurface == NULL)
	{
		// Call IMG_GetError to get the error string.
		printf("SDL_LoadBMP failed: %s\n", IMG_GetError());
		exit(0);
	}
	else
	{
		if (colorKey.a == 0)
		{
			// Set the color key (transparent pixel) in a surface.		
			SDL_SetColorKey(imgSurface, true, SDL_MapRGB(imgSurface->format, colorKey.r, colorKey.g, colorKey.b));
		}

		// Create texture from surface pixels	
		texture = SDL_CreateTextureFromSurface(renderer, imgSurface);

		// Also, you can use IMG_LoadTexture() to replace IMG_Load and SDL_CreateTextureFromSurface
		// texture = IMG_LoadTexture(renderer, path);

		if (texture == NULL)
		{
			printf("SDL_CreateTextureFromSurface failed: %s\n", SDL_GetError());
		}

		width = imgSurface->w;
		height = imgSurface->h;

		// Get rid of old loaded surface
		SDL_FreeSurface(imgSurface);
	}
}

void Image::close()
{
	// Free loaded image	
	SDL_DestroyTexture(texture);
}

void Image::draw()
{
	SDL_Rect* d = &dstRegion, * s = &srcRegion;

	if (dstRegion.x == ALLREGION)
	{
		d = NULL;
	}
	if (srcRegion.x == ALLREGION)
	{
		s = NULL;
	}

	SDL_RenderCopy(renderer, texture, s, d);
}

void Image::draw(SDL_Renderer* renderer, SDL_Rect dst, SDL_Rect src)
{
	setSrcRegion(src);
	setDstRegion(dst);

	draw();
}

int Image::getWidth()
{
	return width;
}

int Image::getHeight()
{
	return height;
}

void Image::setPath(const char* p)
{
	path = new char[strlen(p)];
	strcpy_s(path, strlen(p) + 1, p);
}

void Image::setColorKey(SDL_Color c)
{
	colorKey = c;
}

void Image::setRenderer(SDL_Renderer* r)
{
	renderer = r;
}

void Image::setSrcRegion(SDL_Rect s)
{
	srcRegion = s;
}

void Image::setDstRegion(SDL_Rect d)
{
	dstRegion = d;
}

ImageData loadImgTexture(char* path, int num, int hn, int wn, bool ckEnable, Uint8 r, Uint8 g, Uint8 b) {
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);

	if (loadedSurface == NULL)
	{
		("IMG_Load failed: %s\n", IMG_GetError());
		return { NULL };
	}
	else
	{
		ImageData img;

		// Set the color key (transparent pixel) in a surface.		
		SDL_SetColorKey(loadedSurface, ckEnable, SDL_MapRGB(loadedSurface->format, r, g, b));

		// Create texture from surface pixels
		img.texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (img.texture == NULL)
		{
			("SDL_CreateTextureFromSurface failed: %s\n", SDL_GetError());
		}

		//Get image dimensions and information
		img.width = loadedSurface->w;
		img.height = loadedSurface->h;
		img.num = num;
		img.wn = wn;
		img.hn = hn;

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);

		//return newTexture;
		return img;
	}
}

ImageData loadBackTexture(const char* path, int num, int hn, int wn, bool ckEnable, Uint8 r, Uint8 g, Uint8 b)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path);

	if (loadedSurface == NULL)
	{
		("IMG_Load failed: %s\n", IMG_GetError());
		return { NULL };
	}
	else
	{
		ImageData img;

		// Set the color key (transparent pixel) in a surface.		
		SDL_SetColorKey(loadedSurface, ckEnable, SDL_MapRGB(loadedSurface->format, r, g, b));

		// Create texture from surface pixels
		img.texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (img.texture == NULL)
		{
			("SDL_CreateTextureFromSurface failed: %s\n", SDL_GetError());
		}

		img.width = 1000;
		img.height = 1000;
		img.num = num;
		img.wn = wn;
		img.hn = hn;

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);

		//return newTexture;
		return img;
	}
}
int imgRender(SDL_Renderer* renderer, ImageData img, int posX, int posY, int frame, int cx, int cy, double angle, SDL_RendererFlip flip, int alpha)
{
	img.wn = 1;
	img.hn = 1;
	int wc = frame % img.wn;
	int hc = frame / img.wn;

	SDL_Rect src, dst;
	src.x = img.width / img.wn * wc;
	src.y = img.height / img.hn * hc;
	src.w = img.width / (img.wn);
	src.h = img.height / (img.hn);
	dst.x = posX;
	dst.y = posY;
	dst.w = src.w;
	dst.h = src.h;

	if (SDL_SetTextureBlendMode(img.texture, SDL_BLENDMODE_BLEND) == -1)
	{
		("SDL_SetTextureBlendMode failed: %s\n", SDL_GetError());
		return -1;
	}

	// Modulate texture alpha
	// https://wiki.libsdl.org/SDL_SetTextureAlphaMod
	if (SDL_SetTextureAlphaMod(img.texture, alpha) == -1)
	{
		("SDL_SetTextureAlphaMod failed: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Point center = { cx, cy };
	SDL_RenderCopyEx(renderer, img.texture, &src, &dst, angle, &center, flip);
	return 1;
}