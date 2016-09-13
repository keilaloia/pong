#include "sfwdraw.h"
#include "paddle.h"
#include "GameState.h"
#include"Ball.h"
#include <time.h>
#include <random>
#include <iostream>

void GameState::init()
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
			b1.circle(300, 350, 5, 5, 20, CYAN);

		}

	}
}

void GameState::update()
{
	
	pMovement(p1);
	pMovement2(p2);
	collision(p1, b1);
	collision(p2, b1);
	ballClamp(b1);
	heightClamp(p1);
	heightClamp(p2);

		


/*
			ballClamp(gs.b1);

			prettyball(gs.b1);
			heightClamp(gs.p1);
			heightClamp(gs.p2);
			pMovement(gs.p1);
			pMovement2(gs.p2);
			collision(gs.p1, gs.b1);
			collision(gs.p2, gs.b1);*/
			
	
}

void GameState::drawRound()
{
	Draw(p1);
	Draw(p2);
	prettyball(b1);
}

void GameState::Gscore()
{
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

		if ((p1.score == 3) || (p2.score == 3))
		{
			playGame = false;

		}
	}

}

void collision(Player &p, Ball &b1)
{
	bool yCollide = b1.y - b1.radius < p.y + p.height && b1.y + b1.radius > p.y;
	bool xCollide = b1.x - b1.radius < p.x + p.width && b1.x + b1.radius > p.x;
	if (yCollide && xCollide)
	{
		b1.speedx *= -1;

		//ball.speedy = 16 - rand()%8; // speed y will be between -8 and 8
	}
}
