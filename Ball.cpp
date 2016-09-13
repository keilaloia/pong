#include "GameState.h"
#include "Ball.h"
#include "time.h"

#include <cmath>

// drawball
void prettyball(const Ball &ball)
{
	sfw::drawCircle(ball.x + ball.speedx, ball.y, ball.radius, 12, ball.color);
}
//keeps ball between the barriers of the screen, ie:clamping
void ballClamp(Ball &ball)
{
	ball.x += ball.speedx;
	ball.y += ball.speedy;


	if (ball.y > 600 - ball.radius)
	{
		ball.speedy *= -1;


	}
	else if (ball.y < 0)
	{

		ball.speedy *= -1;

	}

}

void Ball::circle(float a_x, float a_y, float a_speedx, float a_speedy,
							float a_radius, unsigned int a_color)
{
	srand(time(0));
	//Ball ball;
	x = a_x;
	y = a_y;
	radius = a_radius;
	color = a_color;


	int angle = rand();

	speedx = cosf(angle) * 1.5 * 6;
	speedy = sinf(angle) * .75 * 6;
	//return ball;

}