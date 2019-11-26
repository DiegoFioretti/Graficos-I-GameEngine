#ifndef BASEGAME_H
#define BASEGAME_H
#pragma once

#include "Renderer.h"
#include "Window.h"
#include "Input.h"
#include <Windows.h>
#include <iostream>
#include "CollisionManager.h"

#define BASEGAMELIB __declspec(dllexport)

class BASEGAMELIB BaseGame
{
private: 
	Input gameInput;
	Window gameWindow;
	Renderer gameRender;
	CollisionManager gameCollider;
	float cant;
	int entidad;
	char eje;
protected:
	virtual void update() = 0;
public:
	BaseGame();
	~BaseGame();
	int ScreenInit();
	void addNewQuad(float x, float y);
	bool keyPress(char key,int num);
	bool checkCollision(int entA, int entB,int cualCol);
	float entityPos(bool willChange,char axis, int entity, float amount);
	float entityScale(bool willChange, char axis, int entity, float amount);
	float entityRot(bool willChange, char axis, int entity, float amount);
	void coutSprite(const char* image, float u, float v, float width, float high, float cant, float space, float time, int entity);
	void test(int entity);
	void hitCol();
};
#endif