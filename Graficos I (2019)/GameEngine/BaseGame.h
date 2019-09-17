#ifndef BASEGAME_H
#define BASEGAME_H
#pragma once

#include "Renderer.h"
#include "Window.h"
#include <Windows.h>
#include <iostream>
#include <vector>
#define BASEGAMELIB __declspec(dllexport)

class BASEGAMELIB BaseGame
{
private: 
	Window gameWindow;
	Renderer gameRender;
	std::vector<Shape> shapes;
	std::vector<Shape>::iterator shapeIterator;
public:
	BaseGame();
	int ScreenInit();
	~BaseGame();
};
#endif