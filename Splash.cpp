#include "Splash.h"
#include "sfwdraw.h"
#include <iostream>

void Splash::init(int a_font) { font = a_font;}

void Splash::play() {timer = 5.f;}

void Splash::draw()
{
	char buffer[64];
	//sprintf_s(buffer, "Press Enter to start the game! \n %f", timer);
	sfw::drawString(font,buffer, 100, 100, 20, 20);
	sfw::drawLine(100, 80, 100 + 500 * (timer / 5.f), 80);
}

void Splash::step() {timer -= sfw::getDeltaTime();}

APP_STATE Splash::next()
{
	if (timer < 0 || (sfw::getKey(KEY_ENTER)))
		return TERMINATE;
		return SPLASH;
}
