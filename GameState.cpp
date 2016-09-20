
#include "paddle.h"
#include "GameState.h"
#include "Ball.h"
#include "sfwdraw.h"
#include "Enums.h"
#include "Option.h"
#include <time.h>
#include <random>
#include <iostream>
char buffer[64] = { 0 };


void GameState::init()
{

	timer = 10.f;
	b1.x = 400;
	p1.paddle(100, 45, 20, 50, 'W', 'S', MAGENTA),
		p2.paddle(700, 45, 20, 50, KEY_UP, KEY_DOWN, MAGENTA);

	//b1.circle(300, 350, 5, 5, 20, RED);
	//b2.circle(300, 350, 5, 5, 20, RED);
	//b3.circle(300, 300, 5, 5, 20, RED);

	for (int i = 0; i < 10; ++i)
		balls[i].circle(300, 300, 5, 5, 20, RED);
	ballCount = 1;

	p1.score = 0;
	p2.score = 0;
	ballsPlus = false;

	gameover = false;


}


void GameState::drawRound()
{
	for (int i = 0; i < ballCount && i < 10; ++i)
	{
		prettyball(balls[i]);
	}

	Draw(p1);
	Draw(p2);

	//prettyball(b1);

	//if (ballsPlus == true)
	//{
	//	//prettyball(b1);
	//	prettyball(b2);
	//	prettyball(b3);
	//}
	
}

void GameState::update()
{
	//timer
	timer -= sfw::getDeltaTime();

	sprintf_s(buffer, "Ability In");
	sfw::drawString(d, buffer, 325, 575, 17, 17);
	sprintf_s(buffer, "%f", timer);
	sfw::drawString(d, buffer, 325, 550, 17, 17);

	if (timer < 0)
	{
		timer = 10.f;
		//ballsPlus = true;
		ballCount++;
		// flip stuff here!
	}

	for (int i = 0; i < ballCount && i < 10; ++i)
	{
		collision(p1, balls[i]);
		collision(p2, balls[i]);
		ballClamp(balls[i]);
	}

	//if (ballsPlus == true)
	//{
	//	collision(p1, b2);
	//	collision(p2, b2);
	//	ballClamp(b2);

	//	collision(p1, b3);
	//	collision(p2, b3);
	//	ballClamp(b3);
	//}

	
	pMovement(p1);
	pMovement2(p2);
	//collision(p1, b1);
	//collision(p2, b1);

	//ballClamp(b1);
	heightClamp(p1);
	heightClamp(p2);

}

void GameState::Gscore()
{
	
	
	
	sprintf_s(buffer, "player 1: %d", p1.score);
	sfw::drawString(d, buffer, 75, 600, 17, 17);

	sprintf_s(buffer, "player 2: %d", p2.score);
	sfw::drawString(d, buffer, 525, 600, 17, 17);

	for (int i = 0; i < ballCount && i < 10; ++i)
		if (balls[i].x < p1.x - 50)
		{
			p1.score ++;
			balls[i].x = 400;
		}
		else if (balls[i].x > p2.x + 50)
		{
			p2.score ++;
			balls[i].x = 400;
		}

	if ((p1.score == 5) || (p2.score == 5))
	{
		
		gameover = true;
	}

}

void collision(Player &p, Ball &b1)
{
	bool yCollide = b1.y - b1.radius < p.y + p.height && b1.y + b1.radius > p.y;
	bool xCollide = b1.x - b1.radius < p.x + p.width && b1.x + b1.radius > p.x;
	if (yCollide && xCollide)
	{
		b1.speedx *= -1;

		
	}
}



APP_STATE GameState::next()
{
	if (gameover)
		return ENTER_VICTORY;
	else
		return GAME;
}