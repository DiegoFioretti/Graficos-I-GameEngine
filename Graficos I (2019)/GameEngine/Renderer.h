#ifndef RENDERER_H
#define RENDERER_H
#pragma once

#include <GL/glew.h>
#include <vector>
#include "Window.h"
#include "Shape.h"
//#ifndef _glew_h_

class Renderer
{
public:
	Renderer();
	~Renderer();
	void AddShape(std::vector<Shape>& auxShapes);
	void WindowRefresh(GLFWwindow* window, std::vector<Shape>& auxShapes);
	//void Draw();
};
//#endif  _glew_h_
#endif RENDERER_H