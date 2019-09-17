#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shape
{
public:
	Shape();
	~Shape();
	GLfloat* getVertex();
	GLuint* getElements();
};
#endif