#include "Victory.h"
#include "paddle.h"
#include "GameState.h"
#include <iostream>
#include"sfwdraw.h"
void Victory::init(int a_font, Player ps)
{
	font = a_font; 
	betterplayer = ps;
}

void Victory::play() 
{ 


}

void Victory::draw()
{
	char buffer[64];
	
	sprintf_s(buffer, "winning player is: %d", betterplayer.score);
	sfw::drawString(font, buffer, 325, 575, 17, 17);

}

void Victory::step()
{
}

APP_STATE Victory::next()
{
	return VICTORY;
}
