#include "sfwdraw.h"
#include "paddle.h"
#include <cstdlib>



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



//player cannot move past top or bottom of screen
void heightClamp(Player &p)
{
	if (p.y > 600 - p.height) p.y = 600 - p.height;
	if (p.y < 0) p.y = 0;
}


//draw box paddles
void Draw(const Player& p)
{
	sfw::drawLine(p.x, p.y, p.x, p.y + p.height, p.color);
	sfw::drawLine(p.x + p.width, p.y, p.x + p.width, p.y + p.height, p.color);
	sfw::drawLine(p.x, p.y, p.x + p.width, p.y, p.color);
	sfw::drawLine(p.x, p.y + p.height, p.x + p.width, p.y + p.height, p.color);



}
