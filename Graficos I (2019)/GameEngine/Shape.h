#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SIZESQV 28
#define SIZESQE 6

class Shape
{
private:
	GLfloat _sqVertex[SIZESQV] = {
		//  Position            Color             Texcoords
			-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
			 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Bottom-right
			-0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f  // Bottom-left
	};;
	GLuint _sqElements[SIZESQE] = {
		0, 1, 2,
		2, 3, 0
	};;
public:
	Shape();
	~Shape();
	void setSquareVertex(GLfloat (&vertex)[SIZESQV]);
	void setSquareElements(GLuint (&elements)[SIZESQE]);
};
#endif