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
	int nEntity;
	array <Entity, MAXENTITIES> _gameEntities;
public:
	Renderer();
	~Renderer();
	void addEntity();
	array<Entity, MAXENTITIES> getGameEntities();
	void changeScale(float amount);
	void WindowRefresh(GLFWwindow* window);

	float entityPosMod(bool& willChange, char& axis, int& entity, float& amount);
	float entityScaleMod(bool& willChange, char& axis, int& entity, float& amount);
	float entityRotMod(bool& willChange, char& axis, int& entity, float& amount);
};

#endif RENDERER_H