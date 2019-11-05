#ifndef RENDERER_H
#define RENDERER_H
#pragma once

#define MAXENTITIES 10

#include <GL/glew.h>
#include "Window.h"
#include "Entity.h"
#include <iostream>

using namespace std;

class Renderer
{
private:
	GLuint vao;
	GLuint vbo;
	GLuint ebo;
	bool chronoAct = true;
	GLint uniTrans;
	GLint uniProj;
	GLint uniView;
	Entity gameEntities[MAXENTITIES];
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
	void addEntity();
	void WindowRefresh(GLFWwindow* window);
};

#endif RENDERER_H