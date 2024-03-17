#include "Role.h"
#include "Image.h"
#include <stdio.h>
#include "system.h"

int p[12][16] = { 0 };//橫的
int gg[12][16] = { 0 };//長草的位置


Role::Role() {}
Role::Role(const char* path, SDL_Renderer* ren)
{
	Image::setPath(path);
	Image::setRenderer(ren);
	Image::setColorKey(NO_TRANSPARENT_BG);
	Image::generateTexture();

	renderer = ren;
	num = 1;
	frame = 0;
	hn = 1;
	wn = 1;
}

// Ren-ew in this example
Role::Role(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren)
{
	Image::setPath(path);
	Image::setRenderer(ren);
	Image::setColorKey(NO_TRANSPARENT_BG);
	Image::generateTexture();
	renderer = ren;
	num = n;
	frame = 0;
	hn = hhn;
	wn = wwn;
}

// Renew in this example
Role::Role(const char* path, int n, int hhn, int wwn, SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b)
{
	Image::setPath(path);
	Image::setRenderer(ren);
	Image::setColorKey({ r, g, b });
	Image::generateTexture();
	renderer = ren;
	num = n;
	frame = 0;
	hn = hhn;
	wn = wwn;
}

// Renew in this example
void Role::close()
{
	Image::close();
	SDL_RemoveTimer(timerID);
}

int Role::move(int n)
{
	Posx += velX;
	Posy += velY;
	int hit = 0;
	int i1, j1, i2, j2, i3, j3, i4, j4;//判斷角色的四角
	int W, H;
	if (n == 1) { W = M_WIDTH, H = M_HEIGHT; }
	else { W = B_WIDTH, H = B_HEIGHT; }
	j1 = (Posx - EDGE) / 50;
	i1 = Posy / 50;
	j2 = (Posx + W - EDGE) / 50;
	i2 = (Posy) / 50;
	j3 = (Posx + W - EDGE) / 50;
	i3 = (Posy + H) / 50;
	j4 = ((Posx - EDGE)) / 50;
	i4 = (Posy + H) / 50;
	if (p[i1][j1] == 1 || gg[i1][j1] == 1 || p[i2][j2] == 1 || gg[i2][j2] == 1 || p[i3][j3] == 1 || gg[i3][j3] == 1 || p[i4][j4] == 1 || gg[i4][j4] == 1) {
		Posx -= velX;
		Posy -= velY;
		hit = 1;
	}

	if ((Posx <= LEFT_EDGE) || (Posx + M_WIDTH >= RIGHT_EDGE))
	{
		Posx -= velX;
		hit = 1;
	}

	if ((Posy <= 0) || (Posy + M_HEIGHT >= HEIGHT))
	{
		Posy -= velY;
		hit = 1;
	}

	if ((Posx + M_WIDTH > 400 + EDGE && Posx < 550 + EDGE) && Posy + M_HEIGHT >= 250 && Posy < 350) {
		Posx -= velX;
		Posy -= velY;
		hit = 1;
	}
	return hit;
}

int Role::getVX() 
{
	return velX;
}
int Role::getVY()
{
	return velY;
}
void Role::setVX(int x) 
{
	velX = x;
}
void Role::setVY(int y)
{
	velY = y;
}



void Role::returnPo(int& a, int& b)
{
	a = Posx;
	b = Posy;
}

void Role::getBarriar1(int w[12][16]) {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			p[i][j] = w[i][j];
		}
	}
}
void Role::checkBarriar1(int q[12][16]) {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			if (q[i][j] == p[i][j] && p[i][j] == 1)
				q[i][j] = 0;
		}
	}
}

void Role::getGrass(int g[12][16]) {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			gg[i][j] = g[i][j];
		}
	}
}


void Role::returnBarriar(int b[12][16]) {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			if (p[i][j] == 1 || gg[i][j] == 1)
				b[i][j] = 1;
			else b[i][j] = 0;
		}
	}
}
void Role::printarray() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 16; j++) {
			printf("wall p[%d][%d]=%d\n  ", i, j, p[i][j]);
			printf("grass gg[%d][%d]=%d\n", i, j, gg[i][j]);
		}
		printf("\n");
	}
}

void Role::setPosition(int xx, int yy)
{
	Posx = xx;
	Posy = yy;
}

int Role::getWidth()
{
	if (wn == 0)wn = 1;
	return Image::getWidth() / wn;
}

int Role::getHeight()
{
	if (hn == 0)hn = 1;
	return Image::getHeight() / hn;
}

void Role::draw()
{
	if (wn == 0)wn = 1;
	if (hn == 0)hn = 1;
	int wc = frame % wn;
	int hc = frame / wn;

	SDL_Rect s, d;
	s.x = getWidth() * wc;
	s.y = getHeight() * hc;
	s.w = getWidth();
	s.h = getHeight();
	d.x = Posx;
	d.y = Posy;
	d.w = s.w;
	d.h = s.h;
	Image::setSrcRegion(s);
	Image::setDstRegion(d);
	Image::draw();
}

Uint32 Role::changeData(Uint32 interval, void* param)
{
	Role* p = (Role*)param;
	if (p->num == 0)p->num = 1;
	if (p->time != 0)
	{
		p->frame = (p->frame + 1) % p->num;  // image frame	
		return interval;
	}
	else
	{
		return 0;
	}

}

void Role::startTimer(Uint32 t)
{
	time = t;
	timerID = SDL_AddTimer(time, changeData, this); // Set Timer callback
}

void Role::stopTimer()
{
	time = 0;
}

//new!

void Role::setPoint(int pp) {///
	point = pp;
	printf("setpoints: = %d\n", point);
}

int Role::getPoint(int h) {///
	if (h == 1) {
		point--;
		printf("getpoints: = %d\n", point);
	}

	return point;
}

void Role::heartmove(int condition) { ///new


	switch (condition) {
	case 1:
		if (Posx == LEFT_EDGE + 80 || Posx < LEFT_EDGE + 80)
			direction = 1;
		if (Posx > RIGHT_EDGE - 60)
			direction = 2;

		if (direction == 1)
			setPosition(Posx + 3, Posy);
		if (direction == 2)
			setPosition(Posx - 3, Posy);
		break;

	case 2:
		if (Posy == 0 || Posy < 0)
			direction = 1;
		if (Posy > HEIGHT - 120)
			direction = 2;

		if (direction == 1)
			setPosition(Posx, Posy + 3);
		if (direction == 2)
			setPosition(Posx, Posy - 3);
		break;
	case 3:
		if (Posx == RIGHT_EDGE - 120 || Posx > RIGHT_EDGE - 120)
			direction = 1;
		if (Posx < LEFT_EDGE + 10)
			direction = 2;

		if (direction == 1)
			setPosition(Posx - 3, Posy);
		if (direction == 2)
			setPosition(Posx + 3, Posy);
		break;

	case 4:
		if (Posy == HEIGHT - 50 || Posy > HEIGHT - 50)
			direction = 1;
		if (Posy < 60)
			direction = 2;

		if (direction == 1)
			setPosition(Posx, Posy - 3);
		if (direction == 2)
			setPosition(Posx, Posy + 3);
		break;

	}
}

int  Role::heartrandom1() { //////new
	int i = rand() % 4 + 1;
	printf("i = %d\n", i);

	switch (i) {
	case 1:setPosition(LEFT_EDGE + 80, 0); break;
	case 2:setPosition(RIGHT_EDGE - 50, 0); break;
	case 3:setPosition(RIGHT_EDGE - 120, HEIGHT - 50); break;
	case 4:setPosition(LEFT_EDGE + 5, HEIGHT - 50); break;
	}

	return i;

}

int Role::heartrandom2(int i) { ///////new
	int j = rand() % 4 + 1;
	printf("j = %d\n", j);

	if (i == j) {
		printf("same\n");
		j++;
		if (j == 5)
			j = j - 3;
	}
	printf("j new  = %d\n", j);
	switch (j) {
	case 1:setPosition(LEFT_EDGE + 80, 0); break;
	case 2:setPosition(RIGHT_EDGE - 50, 0); break;
	case 3:setPosition(RIGHT_EDGE - 120, HEIGHT - 50); break;
	case 4:setPosition(LEFT_EDGE + 5, HEIGHT - 50); break;
	}

	return j;
}

