#include "Shape.h"
#include <iostream>

Shape::Shape()
{
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