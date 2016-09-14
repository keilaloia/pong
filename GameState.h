#pragma once
#include "sfwdraw.h"
#include "paddle.h"
#include "Ball.h"
#include "sfwdraw.h"
#include "Enums.h"
#include <time.h>
#include <iostream>
#include <random>

class GameState
{
public:
	Player p1, p2;
	Ball b1;

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	bool gameover = false;

	void init();
	void update();
	void Gscore();
	void drawRound();
	APP_STATE next();

	
};


//collision code
void collision(Player &p, Ball &b1);