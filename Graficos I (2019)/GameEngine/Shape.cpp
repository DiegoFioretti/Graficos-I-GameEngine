#include "Shape.h"
#include <iostream>

using namespace std;
Shape::Shape(){
}

Shape::~Shape()
{
}

void Shape::setSquareVertex(GLfloat (&vertex)[SIZESQV])
{
	for (int i = 0; i < SIZESQV; i++)
	{
		vertex[i] = _sqVertex[i];
	}
}

void Shape::setSquareElements(GLuint (&elements)[SIZESQE])
{
	for (int i = 0; i < SIZESQE; i++)
	{
		elements[i] = _sqElements[i];
	}
}