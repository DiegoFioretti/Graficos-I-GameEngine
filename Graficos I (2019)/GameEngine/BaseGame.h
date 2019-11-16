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
	~BaseGame();
	int ScreenInit();
	void addNewQuad(string textureLocation);
	bool keyPress(char key,int num);
	float entityPos(bool willChange,char axis, int entity, float amount);
	float entityScale(bool willChange, char axis, int entity, float amount);
	float entityRot(bool willChange, char axis, int entity, float amount);
	void coutSprite(const char* image,int u, int v, int width, int high,int space,int time);
};
#endif