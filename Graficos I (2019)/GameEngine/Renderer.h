#ifndef RENDERER_H
#define RENDERER_H
#pragma once

#include <GL/glew.h>
#include "Window.h"
#include "Shape.h"
#include <iostream>
using namespace std;
//#ifndef _glew_h_

class Renderer
{
public:
	Renderer();
	~Renderer();
	void AddShape();
	void WindowRefresh(GLFWwindow* window);
};
//#endif  _glew_h_
#endif RENDERER_H