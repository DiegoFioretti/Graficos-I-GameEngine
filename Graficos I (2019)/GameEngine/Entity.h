#ifndef ENTITY_H
#define ENTITY_H
#pragma once

#include "Shape.h"
#include "Sprite.h"

#include <GL/glew.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Entity
{
private:
	Shape shaper;
	Sprite spriter;
	GLuint _vertexArrayO;
	GLuint _vertexBufferO;
	GLuint _elementBufferO;
	GLuint _vertexShader;
	GLuint _fragmentShader;
	GLuint _shaderProgram;
	GLint _posAttrib;
	GLint _colAttrib;
	GLint _texAttrib;
	GLint _uniTrans;
	float _positionX;
	float _positionY;
	float _positionZ;
	float _scaleX;
	float _scaleY;
	float _scaleZ;
	float _rotationX;
	float _rotationY;
	float _rotationZ;
	glm::mat4 _trans = glm::mat4(1.0f);
public:
	Entity();
	~Entity();

	void Initialize(string& textloc);

	array<GLfloat, SIZESQV> getVertices();
	array<GLuint, SIZESQE> getElements();
	GLuint& getVertexArray();
	GLuint& getVertexBuffer();
	GLuint& getElementBuffer();
	GLuint& getVertexShader();
	GLuint& getFragmentShader();
	GLuint& getShaderProgram();
	GLint& getPosAttrib();
	GLint& getColAttrib();
	GLint& getTexAttrib();
	GLint& getUniTrans();
	glm::mat4& getTrans();

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
};
#endif