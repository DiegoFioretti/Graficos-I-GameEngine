#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <array>

#define SIZESQV 36
#define SIZESQE 6

using namespace std;

class Shape
{
private:
	array <GLfloat, SIZESQV> _vertices;
	array <GLuint, SIZESQE> _elements;

	GLfloat _sqVertex[SIZESQV] = {
		// positions              // colors                 // texture coords
		0.314f,  0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   0.5f, 0.5f,   // top right
		0.314f, -0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   0.5f, 0.0f,   // bottom right
		-0.314f, -0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.314f,  0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.5f    // top left
	};;
	GLuint _sqElements[SIZESQE] = {
		0, 1, 2,
		2, 3, 0
	};;
public:
	Shape();
	~Shape();

	array <GLfloat,SIZESQV> getSquareVertices();
	array <GLuint,SIZESQE> getSquareElements();
};
#endif