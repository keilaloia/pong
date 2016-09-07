#include <iostream>
#include "paddleheader.h"
#include "sfwdraw.h"
Player paddle(float x, float y, float width, float height, char up, char down, unsigned int color)
{
	Player p;
	p.x = x;
	p.y = y;
	p.width = width;
	p.height = height;
	p.up = up;
	p.down = down;
	p.color = color;

	return p;
}

Ball circle(float x, float y, float speedx, float speedy, float radius, unsigned int color)
{
	Ball ball;
	ball.x = x;
	ball.y = y;
	ball.radius = radius;
	ball.color = color;
	//srand(time(0))
	ball.speedx = rand() % 10 + 1;
	ball.speedy = rand() % 10 + 1;
	return ball;

}


void pMovement2(Player &p)
{

	if (sfw::getKey(KEY_DOWN))
	{
		p.y -= (sfw::getDeltaTime() * 600);
	}
	else if (sfw::getKey(KEY_UP))
	{
		p.y += (sfw::getDeltaTime() * 600);
	}
}
void pMovement(Player &p)
{
	if (sfw::getKey('W'))
	{
		p.y += (sfw::getDeltaTime() * 600);

	}
	else if (sfw::getKey('S'))
	{
		p.y -= (sfw::getDeltaTime() * 600);
	}

}

void drawScore(unsigned font, int p1score, int p2score)
{

}
//collision code
void collision(Player &p, Ball &ball)
{
	bool yCollide = ball.y - ball.radius < p.y + p.height && ball.y + ball.radius > p.y;
	bool xCollide = ball.x - ball.radius < p.x + p.width && ball.x + ball.radius > p.x;
	if (yCollide && xCollide)
	{
		ball.speedx *= -1;

		//ball.speedy = 16 - rand()%8; // speed y will be between -8 and 8
	}
}

//player cannot move past top or bottom of screen
void heightClamp(Player &p)
{
	if (p.y > 600 - p.height) p.y = 600 - p.height;
	if (p.y < 0) p.y = 0;
}
//draw box paddles
void Draw(const Player& p) {
	sfw::drawLine(p.x, p.y, p.x, p.y + p.height, p.color);
	sfw::drawLine(p.x + p.width, p.y, p.x + p.width, p.y + p.height, p.color);
	sfw::drawLine(p.x, p.y, p.x + p.width, p.y, p.color);
	sfw::drawLine(p.x, p.y + p.height, p.x + p.width, p.y + p.height, p.color);



}

// drawball
void prettyball(const Ball &ball)
{
	sfw::drawCircle(ball.x + ball.speedx, ball.y, ball.radius, 12, ball.color);
}
void ballClamp(Ball &ball)
{
	ball.x += ball.speedx;
	ball.y += ball.speedy;


	if (ball.y > 600 - ball.radius)
	{
		ball.speedy *= -1;


	}
	else if (ball.y < 0)
	{

		ball.speedy *= -1;

	}

}