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

void Entity::Initialize(string& textloc) 
{
	// Create Vertex Array Object
	//glGenVertexArrays(1, &_vertexArrayO);
	//binds the vertex array object
	//glBindVertexArray(_vertexArrayO);

	// Create a Vertex Buffer Object and copy the vertex data to it
	//glGenBuffers(1, &_vertexBufferO);
	//Specifies the target to which the buffer object is bound
	//glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferO);

	// Create an element array
	//glGenBuffers(1, &_elementBufferO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _elementBufferO);
	
	//glBufferData(GL_ARRAY_BUFFER, sizeof(shaper.getSquareVertices()), &shaper.getSquareVertices(), GL_STATIC_DRAW);

	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(shaper.getSquareElements()), &shaper.getSquareElements(), GL_STATIC_DRAW);

	spriter.setTextureLocation(textloc);
}

array<GLfloat, SIZESQV> Entity::getVertices()
{
	return shaper.getSquareVertices();
}

array<GLuint, SIZESQE> Entity::getElements()
{
	return shaper.getSquareElements();
}

GLuint& Entity::getVertexArray()
{
	return _vertexArrayO;
}
GLuint& Entity::getVertexBuffer()
{
	return _vertexBufferO;
}
GLuint& Entity::getElementBuffer() 
{
	return _elementBufferO;
}

GLuint& Entity::getVertexShader() { return _vertexShader; }
GLuint& Entity::getFragmentShader() { return _fragmentShader; }
GLuint& Entity::getShaderProgram() { return _shaderProgram; }
GLint& Entity::getPosAttrib() { return _posAttrib; }
GLint& Entity::getColAttrib() { return _colAttrib; }
GLint& Entity::getTexAttrib() { return _texAttrib; }
GLint& Entity::getUniTrans() { return _uniTrans; }
glm::mat4& Entity::getTrans() { return _trans; }

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

