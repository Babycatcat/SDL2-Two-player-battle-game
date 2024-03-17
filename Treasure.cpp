#include "treasure.h"
#include"Role.h"
const int STAR = 7;
const int SHIELD = 7;
Uint32 starAction(Uint32 interval, void* param)
{
	int* par = (int*)param;
	*par = (*par + 1) % STAR;

	return interval;
}
Uint32 shieldAction(Uint32 interval, void* param)
{
	int* par = (int*)param;
	*par = (*par + 1) % SHIELD;

	return interval;
}
Uint32 appearAct(Uint32 interval, void* param)
{
	int* par = (int*)param;
	if (*par == 0) (*par) = 1;

	return interval;
}
Uint32 heartAct(Uint32 interval, void* param)
{
	int* par = (int*)param;
	if (*par >= 0) (*par)++;
	if (*par == 25) *par = 0;
	return interval;
}
void TreasureInit(Treasure& treasure, Player& player, tType type, int x, int y)
{
	char Tpath[100];
	if (type == hpplus) {
		strcpy_s(Tpath, "../images/heart.png");
		treasure.img = loadImgTexture(Tpath, 1, 1, 1, true, 0xFF, 0xFF, 0xFF);
		player.tr_num = 1;
	}
	else if (type == mpplus) {
		strcpy_s(Tpath, "../images/star.png");
		treasure.img = loadImgTexture(Tpath, STAR, 1, 7, true, 226, 226, 226);
		player.tr_num = 2;
	}
	else if (type == shield) {
		strcpy_s(Tpath, "../images/shield.png");
		treasure.img = loadImgTexture(Tpath, SHIELD, 1, 5, true, 249, 249, 249);
		player.tr_num = 3;
	}
	treasure.type = type;
	treasure.x = x;
	treasure.y = y;
	treasure.exist = 1;
	treasure.tt = SDL_AddTimer(100, starAction, &treasure.starPar);
	treasure.shield_ID = SDL_AddTimer(250, shieldAction, &treasure.shieldPar);
	treasure.appear = SDL_AddTimer(10000, appearAct, &treasure.exist);
	treasure.heart = SDL_AddTimer(60, heartAct, &treasure.heartPar);
}
void TreasureEvent(Player& player, Treasure& treasure, tType type)
{
	bool changepos = false;
	int i, j;
	if (treasure.exist == 1) {
		if (type == hpplus) {
			if (abs(player.Posx + player.getWidth() / 2 - treasure.x) <= 33 && abs(player.Posy + player.getHeight() / 2 - treasure.y) <= 33) {
				treasure.exist = 0;
				if (player.HP <= 90)
					player.HP += 10;
				player.tr_num = 1;
				player.tr_par = 1;
				changepos = true;
				for (int i = 0; i < 14; i++)
					player.anipar[i] = (rand() % 50) * (pow(-1, rand() % 2));
			}
		}
		/*else if (type == mpplus) {
			if (abs(player.ro.Posx + player.tank.w / 2 - treasure.x) <= 33 && abs(player.tank.y + player.tank.h / 2 - treasure.y) <= 33) {
				treasure.exist = 0;
				if (player.MP <= 90)
					player.MP += 10;
				player.tr_num = 2;
				player.tr_par = 1;
				changepos = true;
				for (int i = 0; i < 14; i++)
					player.tank.anipar[i] = (rand() % 50) * (pow(-1, rand() % 2));
			}
		}*/
		else if (type == shield) {
			if (abs(player.Posx + player.getWidth() / 2 - treasure.x) <= 33 && abs(player.Posy + player.getHeight() / 2 - treasure.y) <= 33) {
				treasure.exist = 0;
				player.shield = 1;
				player.tr_num = 3;
				player.tr_par = 1;
				player.tr_hold = 1;
				changepos = true;

			}
		}
	}
}



void TreasureDraw(Treasure& treasure, tType type)
{
	if (type == hpplus) {
		//imgRender(renderer, treasure.img, treasure.x, treasure.y, 0, NULL, NULL, NULL, SDL_FLIP_NONE, 255);
		imgRender(renderer, treasure.img, treasure.x, treasure.y - 3 * sin(treasure.heartPar), 0, NULL, NULL, NULL, SDL_FLIP_NONE, 255);
	}
	else if (type == mpplus)
		imgRender(renderer, treasure.img, treasure.x - treasure.img.width / treasure.img.wn / 2, treasure.y - treasure.img.height / treasure.img.hn / 2, treasure.starPar, NULL, NULL, 0, SDL_FLIP_NONE, 255);

	else if (type == shield)
		imgRender(renderer, treasure.img, treasure.x - treasure.img.width / treasure.img.wn / 2, treasure.y - treasure.img.height / treasure.img.hn / 2, treasure.shieldPar, NULL, NULL, 0, SDL_FLIP_NONE, 255);

}
void TreasureFree(Treasure& treasure)
{
	SDL_RemoveTimer(treasure.tt);
	SDL_RemoveTimer(treasure.appear);
	SDL_RemoveTimer(treasure.shield_ID);
	SDL_RemoveTimer(treasure.heart);
	SDL_DestroyTexture(treasure.img.texture);
}