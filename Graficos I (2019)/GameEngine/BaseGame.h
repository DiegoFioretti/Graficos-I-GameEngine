#ifndef BASEGAME_H
#define BASEGAME_H
#pragma once

#include "Renderer.h"
#include "Window.h"
#include <Windows.h>
#include <iostream>
#define BASEGAMELIB __declspec(dllexport)

class BASEGAMELIB BaseGame
{
private: 
	Window gameWindow;
	Renderer gameRender;
public:
	BaseGame();
	int ScreenInit();
	~BaseGame();
};
#endif