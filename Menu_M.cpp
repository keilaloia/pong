#include "Enums.h"
#include "Splash.h"
#include "sfwdraw.h"
#include "Option.h"

void s_Main()
{
	unsigned font = sfw::loadTextureMap(",/res/fontmap.png", 16, 16);
	Splash splash;
	Option option;

	splash.init(font);
	option.init(font);

	bool quit = false;

	APP_STATE state = ENTER_OPTIONS;

	while (sfw::stepContext() && !quit)
	{
		switch (state)
		{
		case ENTER_OPTIONS:
			option.play();
		case OPTION:
			option.step();
			option.draw();
			state = option.next();
			break;

		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			break;

		case TERMINATE: quit = true;
		}
	}
}