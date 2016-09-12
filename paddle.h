#pragma once

struct Player
{
	float x = 0, y = 0, width = 0, height = 0;
	char up = 0, down = 0;
	unsigned int color = 0;
	int score = 0;

};

struct Ball
{
	float x = 0, y = 0, radius = 0, speedx, speedy;
	unsigned int color = 0;

};
Player paddle(float x, float y, float width, float height, char up, char down, unsigned int color);


// Function PRototype:
// Tells the compiler how the function can be used.
Ball circle(float x, float y, float speedx, float speedy, float radius, unsigned int color);

//paddle 2 movement up and down
void pMovement2(Player &p);
//paddle 1 movement up and down
void pMovement(Player &p);
//collision between ball and player
void collision(Player &p, Ball &ball);
//keeps player from getting off screen
void heightClamp(Player &p);
//drawing the box for the paddles
void Draw(const Player& p);
//makes a pretty ball :D
void prettyball(const Ball &ball);
//keeps ball between the barriers of the screen, ie:clamping
void ballClamp(Ball &ball);






// Header files are for
//		: STRUCTURE DEFINITIONS
//		: FUNCTION DECLARATIONS