#pragma once
#include <SDL.h> // Using SDL
#include <stdlib.h>
#include <time.h>
#include "Image.h"
#include"Renderwindow.h"

class Role:
	public Image
{
public:
	/* Renew in this example */
	Role();
	Role(const char* path, SDL_Renderer* ren);
	Role(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren);
	Role(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b);
	
	
	
	void close();
	void setPosition(int xx, int yy);
	void movePosition(int xx, int yy, int n);
	void getBarriar1(int w[12][16]);
	void checkBarriar1(int q[12][16]);
	void getGrass(int g[12][16]);
	void returnPo(int& a, int& b);
	void returnBarriar(int b[12][16]);
	void printarray();
	int getWidth();
	int getHeight();
	virtual void draw();
	void startTimer(Uint32 t);
	void stopTimer();
	int move(int n);
	int getVX(); // get the value of velX
	int getVY();
	void setVX(int x); // set the value of velX
	void setVY(int y);
	int anipar[50];
	void setPoint(int pp);///new
	int getPoint(int pp); ///new


	virtual void random(){};
	void heartmove(int condition); /////new
	int heartrandom1();/////new
	int heartrandom2(int);/////new
	int Posx;
	int Posy;
protected:
	
	int point;

private:
	SDL_Renderer* renderer;
	char* path;
	int num;
	int wn;
	int hn;	
	int frame;
	SDL_TimerID timerID;
	Uint32 time;
	static Uint32 changeData(Uint32 interval, void* param); // Timer callback 
	int velX;
	int velY;
	int direction;/////
};