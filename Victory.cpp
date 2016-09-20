#include "Victory.h"
#include "paddle.h"
#include "GameState.h"
#include <iostream>
#include"sfwdraw.h"
void Victory::init(int a_font)
{
	font = a_font; 

	select = 0;
}

void Victory::play(int a_P1score, int a_P2score)
{ 
	select = 0;
	P1score = a_P1score;
	P2score = a_P2score;
}

void Victory::draw()
{
	char buffer[64];
	if (P1score > P2score)
	{
		sprintf_s(buffer, "player 1 won with : %d points", P1score);
		sfw::drawString(font, "would you like to play again?", 100, 120, 16, 16, 0, 0, select == 0 ? MAGENTA : WHITE);
		sfw::drawString(font, "Nah im Gucci", 100, 100, 16, 16, 0, 0, select == 1 ? MAGENTA : WHITE);

		
	}
	else
	{
		sprintf_s(buffer, "player 2 won with : %d points", P2score);
		sfw::drawString(font, "would you like to play again?", 100, 120, 16, 16, 0, 0, select == 0 ? MAGENTA : WHITE);
		sfw::drawString(font, "Nah im Gucci", 100, 100, 16, 16, 0, 0, select == 1 ? MAGENTA : WHITE);
	

	}
	sfw::drawString(font, buffer, 200, 300, 17, 17);
	
}

void Victory::step()
{
	if (sfw::getKey('w')|| sfw::getKey(KEY_UP))
	{
		select = 0;
	}
	if (sfw::getKey('s')|| sfw::getKey(KEY_DOWN))
	{
		select = 1;
	}
}

APP_STATE Victory::next()
{
	

	if (sfw::getKey(KEY_ENTER))
	{
		if(select == 0)
			return ENTER_GAME;
		if (select == 1)
			return ENTER_SPLASH;
	}
	return VICTORY;

}
