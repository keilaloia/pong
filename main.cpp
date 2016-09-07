
#include "sfwdraw.h"
#include <random>
#include <time.h>
#include "paddleheader.h"


Player paddle(float x, float y, float width,float height, char up, char down, unsigned int color)
{
	Player p;
	p.x = x;
	p.y = y;
	p.width = width;
	p.height = height;
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
	//srand(time(0))
	ball.speedx = rand()% 10 + 1;
	ball.speedy = rand()% 10 + 1;
	return ball;

}


void pMovement2(Player &p)
{
	
	if (sfw::getKey(KEY_DOWN))
	{
		p.y -= (sfw::getDeltaTime() * 600);
	}
	else if (sfw::getKey(KEY_UP))
	{
		p.y += (sfw::getDeltaTime() * 600);
	}
}
void pMovement(Player &p)
{
	if (sfw::getKey('W'))
	{
		p.y += (sfw::getDeltaTime() * 600);

	}
	else if (sfw::getKey('S'))
	{
		p.y -= (sfw::getDeltaTime() * 600);
	}
	
}

void drawScore(unsigned font, int p1score, int p2score)
{

}
//collision code
void collision(Player &p, Ball &ball)
{
	bool yCollide = ball.y - ball.radius < p.y + p.height && ball.y + ball.radius > p.y;
	bool xCollide = ball.x - ball.radius < p.x + p.width && ball.x + ball.radius > p.x;
	if ( yCollide && xCollide )
	{
		ball.speedx *= -1;

		//ball.speedy = 16 - rand()%8; // speed y will be between -8 and 8
	}
}

//player cannot move past top or bottom of screen
void heightClamp(Player &p)
{
	if (p.y > 600 - p.height) p.y = 600 - p.height;
	if (p.y < 0) p.y = 0;
}
//draw box paddles
void Draw(const Player& p) {
	sfw::drawLine(p.x, p.y, p.x, p.y + p.height, p.color);
	sfw::drawLine(p.x + p.width, p.y, p.x + p.width, p.y + p.height, p.color);
	sfw::drawLine(p.x, p.y, p.x + p.width, p.y, p.color);
	sfw::drawLine(p.x, p.y + p.height, p.x + p.width, p.y + p.height, p.color);



}

// drawball
void prettyball(const Ball &ball)
{
	sfw::drawCircle(ball.x + ball.speedx, ball.y,ball.radius, 12, ball.color);
}
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
void main()
{
	srand(time(0));
	sfw::initContext(800, 600, "El Videojuegos");

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);

	bool playGame = false;
	sfw::setBackgroundColor(BLACK);
	Player p1, p2;
	Ball b1 ;
	
	while (sfw::stepContext())
	{
		if (playGame == false)
		{
		
			sfw::drawString(f, "To play a game press A", 300, 400, 20, 20, 6, ' ');
			if (sfw::getKey('A'))
			{
				playGame = true;
				
				b1.x = 400;
				p1 = paddle(100, 45, 20, 50, 'W', 'S', WHITE),
				p2 = paddle(700, 45, 20, 50, KEY_UP, KEY_DOWN, WHITE);
				b1 = circle(300, 350, 5, 5, 20, CYAN);

			}
		
		}

			if (playGame == true)
			{
				
				if (b1.x < p1.x - 10)
				{
					p1.score += 1;



					b1.x = 400;
					

					printf("player 1: %d player 2: %d\n", p1.score, p2.score);

				}
				else if (b1.x > p2.x + 10)
				{
					p2.score += 1;
					b1.x = 400;
					
					printf("player 1: %d player 2: %d\n", p1.score, p2.score);

				}
			
				if (p1.score == 3 || p2.score == 3)
				{
					playGame = false;
					
				}




				ballClamp(b1);

				prettyball(b1);
				heightClamp(p1);
				heightClamp(p2);
				pMovement(p1);
				pMovement2(p2);
				collision(p1, b1);
				collision(p2, b1);
				Draw(p1);
				Draw(p2);
			}
			
		
		//else
		//{

			/*sfw::drawString(f, "you lose, press f", 300, 400, 20, 20, 6, ' ');

			p1.score == 0;
			p2.score == 0;
			b1.x = 400;
			if (!sfw::getKey('F'));

			playGame == true;*/


		//}
	}
}
