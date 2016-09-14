#pragma once


class Player
{
public:
	float x = 0, y = 0, width = 0, height = 0;
	char up = 0, down = 0;
	unsigned int color = 0;
	int score = 0;
	void paddle(float x, float y, float width, float height, char up, char down, unsigned int color);

};





//paddle 2 movement up and down
void pMovement2(Player &p);
//paddle 1 movement up and down
void pMovement(Player &p);
//keeps player from getting off screen
void heightClamp(Player &p);
//drawing the box for the paddles
void Draw(const Player& p);






// Header files are for
//		: STRUCTURE DEFINITIONS
//		: FUNCTION DECLARATIONS