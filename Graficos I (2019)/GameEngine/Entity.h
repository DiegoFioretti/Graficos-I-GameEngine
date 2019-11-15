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
	float _positionX;
	float _positionY;
	float _positionZ;
	float _scaleX;
	float _scaleY;
	float _scaleZ;
	float _rotationX;
	float _rotationY;
	float _rotationZ;
public:
	Entity();
	~Entity();
	array<GLfloat,SIZESQV> getVertices();
	array<GLuint,SIZESQE> getElements();

	void SetPositionX(float& x);
	float GetPositionX();
	void SetPositionY(float& y);
	float GetPositionY();
	void SetPositionZ(float& z);
	float GetPositionZ();

	void SetScaleX(float& x);
	float GetScaleX();
	void SetScaleY(float& y);
	float GetScaleY();
	void SetScaleZ(float& z);
	float GetScaleZ();

	void SetRotationX(float& x);
	float GetRotationX();
	void SetRotationY(float& y);
	float GetRotationY();
	void SetRotationZ(float& z);
	float GetRotationZ();

	void test();
};
#endif