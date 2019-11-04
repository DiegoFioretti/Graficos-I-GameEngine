#include "Shape.h"
#include <iostream>

Shape::Shape()
{
	GLfloat _sqVertex[SIZESQV] = {
		//  Position            Color             Texcoords
			-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Top-left
			 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // Bottom-right
			-0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f  // Bottom-left
	};
	GLuint _sqElements[SIZESQE] = {
		0, 1, 2,
		2, 3, 0
	};
	for (int i = 0; i < SIZESQV; i++)
	{
		_vertices[i] = _sqVertex[i];
	}
	
	for (int i = 0; i < SIZESQE; i++)
	{
		_elements[i] = _sqElements[i];
	}
}

Shape::~Shape()
{
}

array<GLfloat, SIZESQV> Shape::getSquareVertices()
{
	return _vertices;
}

array<GLuint, SIZESQE> Shape::getSquareElements() 
{
	return _elements;
}