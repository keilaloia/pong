#include "Victory.h"
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


	for (int i = 0; i < 10; ++i)
			balls[0].circle(300, 300, 5, 5, 20, RED);
	ballCount = 1;

	p1.score = 0;
	p2.score = 0;
	player.score = (p1.score, p2.score);
	gameover = false;


}


void GameState::drawRound()
{
	// draws balls in the beginning of the round
	for (int i = 0; i < ballCount && i < 10; ++i)
		if (balls[i].Aball)
	{
		prettyball(balls[i]);
	
	}

	Draw(p1);
	Draw(p2);


	
}

void GameState::update()
{
	//timer
	timer -= sfw::getDeltaTime();

	sprintf_s(buffer, "Craziness");
	sfw::drawString(d, buffer, 325, 575, 17, 17);
	sprintf_s(buffer, "%f", timer);
	sfw::drawString(d, buffer, 325, 550, 17, 17);
	// draws balls every 10 seconds 
	if (timer < 0)
	{
		timer = 10.f;

		ballCount++;
		if(ballCount < 10)
		balls[ballCount - 1].circle(400, balls[ballCount].y, rand() % 7 + 4, 5, rand() % 50 + 1, RED);

		p1.paddle(p1.x, p1.y, rand() % 60 + 1, rand() % 200 + 10, KEY_UP, KEY_DOWN, MAGENTA);
		p2.paddle(p2.x, p2.y, rand() % 60 + 1, rand() % 200 + 10, KEY_UP, KEY_DOWN, MAGENTA);
	}

	// collision code for draw balls 
	for (int i = 0; i < ballCount && i < 10; ++i)
		if(balls[i].Aball)
		{
			collision(p1, balls[i]);
			collision(p2, balls[i]);
			ballClamp(balls[i]);
		}


	if (!gameover)
	{	
	pMovement(p1);
	pMovement2(p2);
	}
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
		if(balls[i].Aball)
		{
			if (balls[i].x < p1.x - 50)
			{
				p1.score ++;
				if(i > 0)
					balls[i].Aball = false;
				if(i==0)
				balls[i].x = 400;

			
			}
		

			else if (balls[i].x > p2.x + 50)
			{
				p2.score ++;
				if (i > 0)
					balls[i].Aball = false;

				if(i==0)
				balls[i].x = 400;

			}
		}
	

	if ((p1.score == 20) || (p2.score == 20))
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