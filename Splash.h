#pragma once
#include "Enums.h"

class Splash
{
	int font;
	float timer;
public:
	//called on startup
	void init(int a_font);
	//call play function
	void play();

	// called on update
	void draw();
	//works like update
	void step();

	APP_STATE next();
};