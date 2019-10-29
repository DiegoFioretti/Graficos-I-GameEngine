#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SIZESQV 32
#define SIZESQE 6

class Shape
{
private:
	GLfloat _sqVertex[SIZESQV] = {
			// positions          // colors           // texture coords
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
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