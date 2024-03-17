#include"game.h"
#include"mouse.h"
#include"System.h"
#include"Image.h"
#include"Role.h"
#include<string.h>
#include "player.h"
#include"pausemenu.h"

void game()
{
	char path1[100];
	char path2[100];

	switch (P1)
	{
	case 0:
		strcpy_s(path1, "../image/player/waffle-1.png");
		break;
	case 1:
		strcpy_s(path1, "../image/player/bronnie.png");
		break;
	case 2:
		strcpy_s(path1, "../image/player/cake.png");
		break;
	case 3:
		strcpy_s(path1, "../image/player/cupcake.png");
		break;
	case 4:
		strcpy_s(path1, "../image/player/icecream.png");
		break;
	case 5:
		strcpy_s(path1, "../image/player/macaron.png");
		break;
	}
	switch (P2)
	{
	case 0:
		strcpy_s(path2, "../image/player/waffle-1.png");
		break;
	case 1:
		strcpy_s(path2, "../image/player/bronnie.png");
		break;
	case 2:
		strcpy_s(path2, "../image/player/cake.png");
		break;
	case 3:
		strcpy_s(path2, "../image/player/cupcake.png");
		break;
	case 4:
		strcpy_s(path2, "../image/player/icecream.png");
		break;
	case 5:
		strcpy_s(path2, "../image/player/macaron.png");
		break;
	}

	char deco0[100] = "../image/background/house.png";
	char deco1[100] = "../image/background/grass.png";
	Role lolid("../image/background/loli.png", 10, 2, 5, renderer);
	ImageData w0 = loadImgTexture(deco0, 1, 1, 1, true, 1, 0xFF, 0xFF);
	ImageData w1 = loadImgTexture(deco1, 1, 1, 1, true, 1, 0xFF, 0xFF);

	Player p1(path1, 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Player p2(path2, 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Bomb bomb1("../image/attack/bomb.png", 8, 2, 4, renderer, 0xFF, 0xFF, 0xFF);
	Bomb bomb2("../image/attack/bomb.png", 8, 2, 4, renderer, 0xFF, 0xFF, 0xFF);
	Role house("../image/background/house.png", renderer);
	Wall stone1("../image/background/wall4-1.jpg", renderer);
	Grass grass("../image/background/grass.png", renderer);
	Role rob("../image/background/back.jpg", 1, 1, 1, renderer);
	Role loli("../image/background/loli.png", 10, 2, 5, renderer);
	loli.startTimer(300);

	Bullet bullet1("../image/attack/bullet 2.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Bullet bullet2("../image/attack/bullet 2.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);


	Role heart1("../image/background/candy.png", 1, 1, 1, renderer);/////
	Role heart2("../image/background/candy.png", 1, 1, 1, renderer);/////


	Role rblood1("../image/blood/1.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role rblood2("../image/blood/2.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role rblood3("../image/blood/3.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role rblood4("../image/blood/4.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role rblood5("../image/blood/5.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role rblood6("../image/blood/6.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role rblood7("../image/blood/7.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role rblood8("../image/blood/8.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role rblood9("../image/blood/9.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role rblood10("../image/blood/10.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);

	Role gblood1("../image/blood/1.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role gblood2("../image/blood/2.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role gblood3("../image/blood/3.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role gblood4("../image/blood/4.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role gblood5("../image/blood/5.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role gblood6("../image/blood/6.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role gblood7("../image/blood/7.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role gblood8("../image/blood/8.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role gblood9("../image/blood/9.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);
	Role gblood10("../image/blood/10.png", 1, 1, 1, renderer, 0xFF, 0xFF, 0xFF);


	p1.setPosition(950, 550);///
	p2.setPosition(212, 3);///
	rob.setPosition(-2, 0);///
	bullet1.setPosition(950, 550);///
	bullet2.setPosition(212, 3);///
	house.setPosition(490, 200);
	loli.setPosition(580, 40);///


	rblood1.setPosition(1000, 100);///
	rblood2.setPosition(1000, 100);///
	rblood3.setPosition(1000, 100);///
	rblood4.setPosition(1000, 100);///
	rblood5.setPosition(1000, 100);///
	rblood6.setPosition(1000, 100);///
	rblood7.setPosition(1000, 100);///
	rblood8.setPosition(1000, 100);///
	rblood9.setPosition(1000, 100);///
	rblood10.setPosition(1000, 100);///

	gblood1.setPosition(0, 100);///
	gblood2.setPosition(0, 100);///
	gblood3.setPosition(0, 100);///
	gblood4.setPosition(0, 100);///
	gblood5.setPosition(0, 100);///
	gblood6.setPosition(0, 100);///
	gblood7.setPosition(0, 100);///
	gblood8.setPosition(0, 100);///
	gblood9.setPosition(0, 100);///
	gblood10.setPosition(0, 100);///

	p1.setPoint(10);
	p2.setPoint(10);
	bullet1.setCount(0);
	bullet2.setCount(0);

	stone1.random();//virtual!!
	grass.random();//virtual!!
	int heartCondition1 = heart1.heartrandom1(); ////////new
	int heartCondition2 = heart2.heartrandom2(heartCondition1); ////////new



	PauseMenu pausemenu;
	pausemenu.PauseMenuInit(WIDTH / 2, HEIGHT / 2, 300, 300);
	bool quit = false;
	SDL_Event e;
	int space1 = 0, space2 = 0;
	int point1 = 10, point2 = 10;
	int r = 0, g = 0, b1 = 0, b2 = 0, b1hit = 0, b2hit = 0,s1=0,s2=0;
	while (!quit)
	{
		MouseRefreshState();
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
				exitgame = true;
			}
			handleEvent1(e, p1);
			handleEvent2(e, p2);
			s1 = handleEvent1b(e, p1, p2, bomb1, bullet1, grass, b1, b1hit);
			s2 = handleEvent2b(e, p1, p2, bomb2, bullet2, grass, b2, b2hit);
			
			if (pause)
				mouseKeyEvent(&e);
		}

		if (!pause) {
			heart1.heartmove(heartCondition1);/////
			heart2.heartmove(heartCondition2);/////
			r = p1.move(1);
			g = p2.move(1);
			b1 = bullet1.move(2);
			b2 = bullet2.move(2);


			if (bullet2.getCount() == 0 && s2 == 2) {
				b2hit = bullet2.hit(bullet2, p1);
				p1 = p1 - b2hit;//operator overloading!
			}

			if (bullet1.getCount() == 0 && s1 == 2) {
				b1hit = bullet1.hit(bullet1, p2);
				p2 = p2 - b1hit;//operator overloading!
			}

			if (((heart1.Posx + 20) / 50 == (p1.Posx + M_WIDTH / 2) / 50 && (heart1.Posy + 20) / 50 == (p1.Posy + M_HEIGHT / 2) / 50) || ((heart2.Posx + 20) / 50 == (p1.Posx + M_WIDTH / 2) / 50 && (heart2.Posy + 20) / 50 == (p1.Posy + M_HEIGHT / 2) / 50)) {
				p1 += 1;//operator overloading!
			}///////new
			if (((heart1.Posx + 20) / 50 == (p2.Posx + M_WIDTH / 2) / 50 && (heart1.Posy + 20) / 50 == (p2.Posy + M_HEIGHT / 2) / 50) || ((heart2.Posx + 20) / 50 == (p2.Posx + M_WIDTH / 2) / 50 && (heart2.Posy + 20) / 50 == (p2.Posy + M_HEIGHT / 2) / 50)) {
				p2 = p2 + 1;//operator overloading!
			}///////new

			point1 = p1.getPoint(0);
			point2 = p2.getPoint(0);

			if (point1 > 10)point1 = 10;
			if (point2 > 10)point2 = 10;


			rob.draw();
			switch (point1) {
			case 1:rblood1.draw(); break;
			case 2:rblood2.draw(); break;
			case 3:rblood3.draw(); break;
			case 4:rblood4.draw(); break;
			case 5:rblood5.draw(); break;
			case 6:rblood6.draw(); break;
			case 7:rblood7.draw(); break;
			case 8:rblood8.draw(); break;
			case 9:rblood9.draw(); break;
			case 10:rblood10.draw(); break;
			}
			switch (point2) {
			case 1:gblood1.draw(); break;
			case 2:gblood2.draw(); break;
			case 3:gblood3.draw(); break;
			case 4:gblood4.draw(); break;
			case 5:gblood5.draw(); break;
			case 6:gblood6.draw(); break;
			case 7:gblood7.draw(); break;
			case 8:gblood8.draw(); break;
			case 9:gblood9.draw(); break;
			case 10:gblood10.draw(); break;
			}
			stone1.draw(renderer);///new
			grass.draw(renderer);///new
			house.draw();
			loli.draw();
			p1.draw();
			p2.draw();

			heart1.draw();/////
			heart2.draw();/////
			if (s1 == 2 && b1 == 0 && b1hit == 0)
				bullet1.draw();

			if (s2 == 2 && b2 == 0 && b2hit == 0)
				bullet2.draw();
			if (b1hit == 1)b1hit = 0;
			if (s1 == 1 && s2 != 1) {
				bomb1.startTimer(200);
				bomb1.draw();
				SDL_Delay(200);
				bomb1.startTimer(200);
			}

			if (s2 == 1 && s1 != 1) {
				bomb2.startTimer(200);
				bomb2.draw();
				SDL_Delay(200);
				bomb2.startTimer(200);
			}

			if (s1 == 1 && s2 == 1) {
				bomb1.startTimer(200);
				bomb2.startTimer(200);
				bomb1.draw();
				bomb2.draw();
				SDL_Delay(200);
				bomb1.startTimer(0);
				bomb2.startTimer(0);
			}
			SDL_RenderPresent(renderer);//update screen
		}
		else {
		pausemenu.PauseMenuOn(quit);
			SDL_SetRenderDrawColor(renderer, 230, 195, 195, 255);
			SDL_RenderClear(renderer);
			pausemenu.PauseMenuDraw();

			imgRender(renderer, w0, 260, 100, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
			imgRender(renderer, w1, 775, 470, 0, NULL, NULL, 0, SDL_FLIP_NONE, 255);
			lolid.setPosition(350, -60);
			lolid.draw();
			MouseDraw();
			SDL_RenderPresent(renderer);
		}


		if (point1 == 0 || point2 == 0)//¦³¤H¦º±¼
		{
			rblood1.close();
			rblood2.close();
			rblood3.close();
			rblood4.close();
			rblood5.close();
			rblood6.close();
			rblood7.close();
			rblood8.close();
			rblood9.close();
			rblood10.close();

			gblood1.close();
			gblood2.close();
			gblood3.close();
			gblood4.close();
			gblood5.close();
			gblood6.close();
			gblood7.close();
			gblood8.close();
			gblood9.close();
			gblood10.close();
			//Free resources and close SDL
			stone1.close();
			bullet1.close();
			bullet2.close();
			grass.close();
			rob.close();
			house.close();
			p1.close();
			p2.close();
			bomb1.close();
			bomb2.close();
			loli.close();
			heart1.close(); ///////new
			heart2.close(); ////////new

			screen = Game2;
			quit = true;
		}

	}


	SDL_DestroyTexture(w0.texture);
	SDL_DestroyTexture(w1.texture);
	PlayerFree(p1);
	PlayerFree(p2);
}