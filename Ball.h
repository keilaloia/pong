#pragma once
//#include "sfwdraw.h"
//#include "paddle.h"
//#include "GameState.h"
//#include <cstdlib>
class Ball
{
public:
	float x = 0, y = 0, radius = 0, speedx, speedy;
	unsigned int color = 0;
	/*void circle();*/
void circle(float x, float y, float speedx, float speedy, float radius, unsigned int color);
};


//draws a prettyball
void prettyball(const Ball &ball);
//void prettyball(Ball &ball);
//keeps ball between the barriers of the screen, ie:clamping
void ballClamp(Ball &ball);