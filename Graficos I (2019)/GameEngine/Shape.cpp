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

void Shape::test() {

	float coso[36]{
		0.314f,  0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 1.0f,   // top right
		0.314f, -0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   1.0f, 0.0f,   // bottom right
		-0.314f, -0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 0.0f,   // bottom left
		-0.314f,  0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   0.0f, 1.0f    // top left
	};
	for (int i = 0; i < 36; i++)
	{
		_sqVertex[i] =coso[i];
	}
	
}