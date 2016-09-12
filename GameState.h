#pragma once
#include "paddle.h"
#include <iostream>
#include "sfwdraw.h"
#include <time.h>
#include <random>

struct GameState
{
	Player p1, p2;
	Ball ball;

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	bool playGame = false;
	
};


void updateGS(GameState &gs)
{
	while (sfw::stepContext())
	{
		if (playGame == false)
		{

			sfw::drawString(f, "To play a game press A", 300, 400, 20, 20, 6, ' ');
			if (sfw::getKey('A'))
			{
				playGame = true;

				b1.x = 400;
				p1 = paddle(100, 45, 20, 50, 'W', 'S', WHITE),
					p2 = paddle(700, 45, 20, 50, KEY_UP, KEY_DOWN, WHITE);
				b1 = circle(300, 350, 5, 5, 20, CYAN);

			}

		}

		if (playGame == true)
		{

			if (b1.x < p1.x - 10)
			{
				p1.score += 1;



				b1.x = 400;


				printf("player 1: %d player 2: %d\n", p1.score, p2.score);

			}
			else if (b1.x > p2.x + 10)
			{
				p2.score += 1;
				b1.x = 400;

				printf("player 1: %d player 2: %d\n", p1.score, p2.score);

			}

			if (p1.score == 3 || p2.score == 3)
			{
				playGame = false;

			}




			ballClamp(b1);

			prettyball(b1);
			heightClamp(p1);
			heightClamp(p2);
			pMovement(p1);
			pMovement2(p2);
			collision(p1, b1);
			collision(p2, b1);
			Draw(p1);
			Draw(p2);
		}
	}
}