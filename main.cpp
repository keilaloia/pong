
#include "sfwdraw.h"
#include <random>
#include <time.h>
#include "paddle.h"
#include "GameState.h"
#include "Ball.h"
using namespace sfw;

void main()
{
	sfw::initContext();

	GameState gs;
	while (sfw::stepContext())
	{
		gs.init();
		gs.drawRound();
		gs.update();
		gs.Gscore();
	}

	sfw::termContext();
}
