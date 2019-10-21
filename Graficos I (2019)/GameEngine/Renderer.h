#ifndef RENDERER_H
#define RENDERER_H
#pragma once


#include <GL/glew.h>
#include "Window.h"
#include "Shape.h"
#include <iostream>


using namespace std;

class Renderer
{
private:
	bool chronoAct = true;
	GLint uniTrans;
	GLint uniProj;
	GLint uniView;
public:
	float rotateX = 0.0f;
	float rotateY = 0.0f;
	float rotateZ = 0.0f;
	float posicionX = 0.0f;
	float posicionY = 0.0f;
	float posicionZ = 0.0f;
	float sizeX = 0.5f;
	float sizeY = 0.5f;
	float sizeZ = 0.5f;
	Renderer();
	~Renderer();
	void newShape();
	void WindowRefresh(GLFWwindow* window);
};

#endif RENDERER_H