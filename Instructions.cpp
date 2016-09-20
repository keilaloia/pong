#include "Instructions.h"
#include "sfwdraw.h"
#include <iostream>
#include "Enums.h"

void Instructions::init(int a_font)
{
	font = a_font;
}

void Instructions::play()
{
	timer = 7.f;
}

void Instructions::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Player 1:\n Move up: W \n Move down: S", 80);
	sfw::drawString(font, buffer, 100, 525, 17, 17);

	sprintf_s(buffer, "Player 2:\n Move up: Up Arrow \n Move down: Down Arrow", 80);
	sfw::drawString(font, buffer, 425, 525, 17, 17);

	//sfw::drawString(font, "would you like to play again?", 100, 120, 16, 16, 0, 0, MAGENTA : WHITE);
	//sfw::drawString(font, "Nah im Gucci", 100, 100, 16, 16, 0, 0, MAGENTA : WHITE);
		
	sprintf_s(buffer, "Press Space to begin", 80);
	sfw::drawString(font, buffer, 250, 325, 17, 17);

	sfw::drawString(font, " game is starting in ", 100, 120, 16, 16, 0, 0, CYAN);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 7.f), 80);
}

void Instructions::step()
{
	timer -= sfw::getDeltaTime();
	

}

APP_STATE Instructions::next()
{
	if ((timer < 0 )|| sfw::getKey(' '))
	{
		return ENTER_GAME;
	}
	return INSTRUCTIONS;
}
