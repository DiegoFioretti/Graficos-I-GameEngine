#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <array>

#define SIZESQV 28
#define SIZESQE 6

using namespace std;

class Shape
{
private:
	array <GLfloat, SIZESQV> _vertices;
	array <GLuint, SIZESQE> _elements;
public:
	Shape();
	~Shape();

	array <GLfloat,SIZESQV> getSquareVertices();
	array <GLuint,SIZESQE> getSquareElements();
};
#endif