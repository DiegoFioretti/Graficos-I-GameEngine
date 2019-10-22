#ifndef ENTITY_H
#define ENTITY_H
#pragma once

#include "Shape.h"
#include "Sprite.h"

class Entity
{
private:
	Shape shaper;
	Sprite spriter;
public:
	Entity();
	~Entity();
	array<GLfloat,SIZESQV> getVertices();
	array<GLuint,SIZESQE> getElements();
};
#endif