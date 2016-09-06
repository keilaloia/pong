
#include "sfwdraw.h"
#include <random>


struct Player
{
	float x = 0, y = 0, size = 0;
	char up = 0, down = 0;
	unsigned int color = 0;
	int score = 0;

};

struct Ball
{
	float x = 0, y = 0, radius = 0, speedx, speedy;
	unsigned int color = 0;

};

Player paddle(float x, float y, float size, char up, char down, unsigned int color)
{
	Player p;
	p.x = x;
	p.y = y;
	p.size = size;
	p.up = up;
	p.down = down;
	p.color = color;

	return p;
}

Ball circle(float x, float y, float speedx, float speedy, float radius, unsigned int color)
{
	Ball ball;
	ball.x = x;
	ball.y = y;
	ball.radius = radius;
	ball.color = color;
	ball.speedx = rand() % 10;
	ball.speedy = rand() % 10;
	return ball;

}
void drawScore(unsigned font, int p1score, int p2score)
{

}

void Pbase(Player &p)
{
	if (p.y > 600 - p.size) p.y = 600 - p.size;
	if (p.y < 0) p.y = 0;
}
void prettyline(const Player &p)
{
	sfw::drawLine(p.x, p.y +p.size, p.x, p.y, p.color);
}
// drawball
void prettyball(const Ball &ball)
{
	sfw::drawCircle(ball.x + ball.speedx, ball.y,ball.radius, 12, ball.color);
}
void Bbase(Ball &ball /*Player &p*/)
{
	ball.x += ball.speedx;
	ball.y += ball.speedy;
	
	
	if (ball.y > 600 - ball.radius)
	{
		ball.speedy *= -1;
		/*ball.x += sfw::getDeltaTime() * ball.speedx;*/

	}
	else if (ball.y < 0) 
	{
		/*ball.x = 600 - ball.radius;*/
		ball.speedy *= -1;
		/*ball.x -= (sfw::getDeltaTime()*ball.speedx);*/
	}
	
}
void main()
{
	sfw::initContext(800, 600, "El Videojuegos");

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);


	sfw::setBackgroundColor(BLACK);

	Player p1 = paddle(100, 45, 50, 'W', 'S', WHITE),
		p2 = paddle(700, 45, 50, KEY_UP, KEY_DOWN, WHITE);
	Ball b1 = circle(220, 100, 100, 100, 20, CYAN);
	
	while (sfw::stepContext())
	{
		if (b1.x < p1.x-10/* || b1.x > p2.x+10*/)
		{
			p1.score += 1;

			/*sfw::drawString(f, "you lose, press f", 300, 400, 20, 20, 6, ' ');
			if (!sfw::getKey('F')) continue;*/

			b1.x = 400;
			printf("player 1: %d player 2: %d\n", p1.score, p2.score);
			//sfw::drawString(d, "player 1: %d player 2: %d\n", p1.score, p2.score, 300, 400, 20, 20, 6);
		}
		else if (b1.x > p2.x + 10)
		{
			p2.score += 1;
			b1.x = 400;
			printf("player 1: %d player 2: %d\n", p1.score, p2.score);

		}


		if (sfw::getKey('W'))
		{
			p1.y += (sfw::getDeltaTime()*600);
			
		}
		else if (sfw::getKey('S'))
		{
			p1.y -= (sfw::getDeltaTime() * 600);
		}
		else if (sfw::getKey(KEY_DOWN))
		{
			p2.y -= (sfw::getDeltaTime() * 600);
		}
		else if (sfw::getKey(KEY_UP))
		{
			p2.y += (sfw::getDeltaTime() * 600);
		}

		if (b1.x < p1.x && b1.y > p1.y && b1.y < p1.y + p1.size)
		{
			b1.speedx *= -1;
			b1.x = p1.x;
		}
		if (b1.x > p2.x && b1.y > p2.y && b1.y < p2.y + p2.size)
		{
			b1.speedx *= -1;
			b1.x = p2.x;
		}


		Bbase(b1);

		prettyball(b1);
		Pbase(p1);
		Pbase(p2);
		prettyline(p1);
		prettyline(p2);
	}
}
