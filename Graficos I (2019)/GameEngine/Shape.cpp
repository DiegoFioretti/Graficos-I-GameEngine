#include "Shape.h"
#include <iostream>

using namespace std;
Shape::Shape()
{
}

Shape::~Shape()
{
}

GLfloat* Shape::getVertex() 
{
	GLfloat _vertex[] = {
		   -0.5f,  0.5f, 1.0f, // Top-left
			0.5f,  0.5f, 0.0f, // Top-right
			0.5f, -0.5f, 0.0f, // Bottom-right
		   -0.5f, -0.5f, 1.0f // Bottom-left
	};
	
	return _vertex;
}

GLuint* Shape::getElements() 
{
	GLuint _elements[] = {
		0, 1, 2,
		2, 3, 0
	};

	return _elements;
}