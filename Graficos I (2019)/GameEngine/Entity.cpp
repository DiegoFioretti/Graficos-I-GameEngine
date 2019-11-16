#include "Entity.h"
#include <iostream>

using namespace std;
Entity::Entity() 
{
	_positionX = 0.0f;
	_positionY = 0.0f;
	_positionZ = 0.0f;
	_scaleX = 0.5f;
	_scaleY = 0.5f;
	_scaleZ = 0.5f;
	_rotationX = 0.0f;
	_rotationY = 0.0f;
	_rotationZ = 0.0f;
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

void Entity::SetPositionX(float& x) { _positionX += x; }
float Entity::GetPositionX() { return _positionX; }
void Entity::SetPositionY(float& y) { _positionY += y; }
float Entity::GetPositionY() { return _positionY; }
void Entity::SetPositionZ(float& z) { _positionZ += z; }
float Entity::GetPositionZ() { return _positionZ; }

void Entity::SetScaleX(float& x) { _scaleX += x; }
float Entity::GetScaleX() { return _scaleX; }
void Entity::SetScaleY(float& y) { _scaleY += y; }
float Entity::GetScaleY() { return _scaleY; }
void Entity::SetScaleZ(float& z) { _scaleZ += z; }
float Entity::GetScaleZ() { return _scaleZ; }

void Entity::SetRotationX(float& x) { _rotationX += x; }
float Entity::GetRotationX() { return _rotationX; }
void Entity::SetRotationY(float& y) { _rotationY += y; }
float Entity::GetRotationY() { return _rotationY; }
void Entity::SetRotationZ(float& z) { _rotationZ += z; }
float Entity::GetRotationZ() { return _rotationZ; }

float *Entity::updateSprite() {
	shaper.updateSprite();
	return shaper.squareVertx;
}
int *Entity::squareSize() {
	return shaper.squareSize;
}

void Entity::spriteParameters(float u, float v, float width, float high, float cant, float space, float time, float totalWidth, float totalHeight) {
	spriter.spriteParameters( u,  v,  width,  high,  cant,  space,  time,  totalWidth,  totalHeight);
	for (int i = 0; i < cant; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shaper.txtVrtx[j][i] = spriter.txtVrtx[j][i];
		}
	}
}

