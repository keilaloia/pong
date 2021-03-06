#include "GameState.h"
#include "paddle.h"
#include "Ball.h"
#include "Enums.h"
#include "Splash.h"
#include "Option.h"
#include "Victory.h"
#include "sfwdraw.h"
#include <random>
#include <time.h>
#include "Instructions.h"

using namespace sfw;

void main()
{
	sfw::initContext(800, 600, "NSFW Draw");
	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg"); 
	unsigned d = sfw::loadTextureMap("./res/doggy.png");
	Player score;
	GameState gs;
	Splash splash;
	Option option;
	Victory victory;
	Instructions instructions;
	splash.init(font);
	option.init(font);
	victory.init(font);
	instructions.init(font);

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
		case ENTER_INSTRUCTIONS:
			instructions.play();
		case INSTRUCTIONS:
			sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0, GREEN);

			instructions.draw();

			instructions.step();
			state = instructions.next();
			break;
		case ENTER_GAME:
			gs.init();

		case GAME:
			sfw::drawTexture(d, 0, 600, 800, 600, 0, false, 0);

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
		case ENTER_VICTORY:
			victory.play(gs.p1.score, gs.p2.score);
			
		case VICTORY:
			sfw::drawTexture(d, 0, 600, 800, 600, 0, false, 0);

			gs.drawRound();
			gs.update();

			victory.draw();
			victory.step();
			state = victory.next();
			break;

		case TERMINATE: quit = true;
		}
	}

	sfw::termContext();
}
