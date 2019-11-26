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
	Entity entityGame;
	unsigned int texture;
	const char* actImage;
	float arrShape[36];
	GLuint shaderProgram;
	Window* win;
public:
	int totalWidth, totalHeight, nrChannels;
	Renderer();
	~Renderer();
	void addEntity(float x, float y);
	array<Entity, MAXENTITIES> getGameEntities();
	void WindowRefresh(GLFWwindow* window);

	float entityPosMod(bool& willChange, char& axis, int& entity, float& amount);
	float entityScaleMod(bool& willChange, char& axis, int& entity, float& amount);
	float entityRotMod(bool& willChange, char& axis, int& entity, float& amount);

	//const char* image= "../Juego/pkm.png";

	void newSrpiteSheet(const char* image);
	void cutSrpiteSheet(int entity);
	void spriteParamts(float u, float v, float width, float high, float cant, float space, float time, int entity);
	
};

#endif RENDERER_H