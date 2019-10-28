#include "Entity.h"

Entity::Entity() 
{

}

Entity::~Entity() 
{

}

array<GLfloat, SIZESQV> Entity::getVertices()
{
	return shaper.getSquareVertices();
}

array<GLuint, SIZESQE> Entity::getElements()
{
	return shaper.getSquareElements();
}