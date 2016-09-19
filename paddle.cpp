#include "sfwdraw.h"
#include "paddle.h"
#include <cstdlib>



void Player::paddle(float b_x, float b_y, float b_width, float b_height,
	char b_up, char b_down, unsigned int b_color)
{
	
	x = b_x;
	y = b_y;
	width = b_width;
	height = b_height;
	up = b_up;
	down = b_down;
	color = b_color;

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



//player cannot move past top or bottom of screen
void heightClamp(Player &p)
{
	if (p.y > 600 - p.height) p.y = 600 - p.height;
	if (p.y < 0) p.y = 0;
}


//draw box paddles
void Draw(const Player &p)
{
	sfw::drawLine(p.x, p.y, p.x, p.y + p.height, p.color);
	sfw::drawLine(p.x + p.width, p.y, p.x + p.width, p.y + p.height, p.color);
	sfw::drawLine(p.x, p.y, p.x + p.width, p.y, p.color);
	sfw::drawLine(p.x, p.y + p.height, p.x + p.width, p.y + p.height, p.color);



}

