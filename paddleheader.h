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
