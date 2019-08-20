#ifndef RENDERER_H
#define RENDERER_H
#pragma once

#include "Window.h"
#include <GLFW/glfw3.h>

class Renderer
{
public:
	Renderer();
	~Renderer();
	void WindowRefresh(GLFWwindow* window);
	void Draw();
};
#endif