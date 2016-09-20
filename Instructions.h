#pragma once
#include "Enums.h"
#include <iostream>
#include "sfwdraw.h"

class Instructions
{
	float timer;
	int font;
public:
	void init(int a_font);
	void play();
	void draw();
	void step();
	APP_STATE next();
};