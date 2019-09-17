#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shape
{
private:
	GLuint _vertexArrayObject;
	GLuint _vertexBufferObject;
	GLuint _elementBuferObject;
	GLuint _vertexShader;
	GLuint _fragmentShader;
	GLint _posAttrib;
	GLint _colAttrib;
	GLuint _shaderProgram;
public:
	Shape();
	~Shape();
	void DrawSelf();
	GLuint getShaderProgram();
};
#endif