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

void Shape::updateSprite() {
	
	for (int i = 0; i < 36; i++)
	{
		switch (i)
		{
		case 7:
			squareVertx[i] = txtVrtx[frame][0];
			break;
		case 8:
			squareVertx[i] = txtVrtx[frame][2];
			break;
		case 16:
			squareVertx[i] = txtVrtx[frame][0];
			break;
		case 17:
			squareVertx[i] = txtVrtx[frame][3];
			break;
		case 25:
			squareVertx[i] = txtVrtx[frame][1];
			break;
		case 26:
			squareVertx[i] = txtVrtx[frame][3];
			break;
		case 34:
			squareVertx[i] = txtVrtx[frame][1];
			break;
		case 35:
			squareVertx[i] = txtVrtx[frame][2];
			break;
		default:

			break;
		}
	}
	frame++;
	if (frame==4)
	{
		frame = 0;
	}

}