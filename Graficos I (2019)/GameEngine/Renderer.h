#ifndef RENDERER_H
#define RENDERER_H
#pragma once

#include <GL/glew.h>
#include "Window.h"
//#ifndef _glew_h_

class Renderer
{
public:
	Renderer();
	~Renderer();
	void WindowRefresh(GLFWwindow* window);
	//void Draw();
};
//#endif  _glew_h_
#endif RENDERER_H