#include "GameState.h"
#include "paddle.h"
#include "Ball.h"
#include "Enums.h"
#include "Splash.h"
#include "Option.h"
#include "sfwdraw.h"
#include <random>
#include <time.h>

using namespace sfw;

void main()
{
	sfw::initContext(800,600, "NSFW Draw");
	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	GameState gs;
	Splash splash;
	Option option;


	splash.init(font);
	option.init(font);

	//ol quit = false;

	APP_STATE state = ENTER_OPTIONS;

	bool quit = false;

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

		case ENTER_GAME:
			gs.init();

		case GAME:
			gs.drawRound();
			gs.update();
			
			gs.Gscore();
			state = gs.next();
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
		//getchar();
	}

	sfw::termContext();
}
