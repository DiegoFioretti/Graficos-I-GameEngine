#ifndef BASEGAME_H
#define BASEGAME_H
#pragma once

#include "Renderer.h"
#include "Window.h"
#include "Input.h"
#include <Windows.h>
#include <iostream>

#define BASEGAMELIB __declspec(dllexport)

class BASEGAMELIB BaseGame
{
private: 
	Input gameInput;
	Window gameWindow;
	Renderer gameRender;
protected:
	virtual void update() = 0;
public:
	BaseGame();
	int ScreenInit();
	~BaseGame();
	void KeyCallback(GLFWwindow* window);
	void addNewQuad();
};
#endif