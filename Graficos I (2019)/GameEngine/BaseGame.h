#ifndef BASEGAME_H
#define BASEGAME_H
#pragma once

#include <iostream>
#define BASEGAMELIB __declspec(dllexport)

class BASEGAMELIB BaseGame
{
public:
	BaseGame();
	int ScreenInit();
	~BaseGame();
};
#endif