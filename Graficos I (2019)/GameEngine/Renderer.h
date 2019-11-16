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
	//GLuint vao;
	//GLuint vbo;
	//GLuint ebo;
	bool chronoAct = true;
	GLint uniTrans;
	GLint uniProj;
	GLint uniView;
	int nEntity;
	array <Entity, MAXENTITIES> _gameEntities;
public:
	Renderer();
	~Renderer();
	void addEntity(string& textloc);
	array<Entity, MAXENTITIES> getGameEntities();
	void WindowRefresh(GLFWwindow* window);

	float entityPosMod(bool& willChange, char& axis, int& entity, float& amount);
	float entityScaleMod(bool& willChange, char& axis, int& entity, float& amount);
	float entityRotMod(bool& willChange, char& axis, int& entity, float& amount);

	const char* image= "../Juego/pkm.png";
};

#endif RENDERER_H