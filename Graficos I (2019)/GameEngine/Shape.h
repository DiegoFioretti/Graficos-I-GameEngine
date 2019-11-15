#ifndef SHAPE_H
#define SHAPE_H
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <array>

#define SIZESQV 36
#define SIZESQE 6

using namespace std;

class Shape
{
private:
	array <GLfloat, SIZESQV> _vertices;
	array <GLuint, SIZESQE> _elements;
	float num=1.0f;
	GLfloat _sqVertex[SIZESQV] = {
		// positions              // colors                 // texture coords
		0.314f,  0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   48.0f / 255.0f, 245.0f / 255.0f,   // top right
		0.314f, -0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   48.0f / 255.0f, 193.0f / 255.0f,   // bottom right
		-0.314f, -0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   14.0f / 255.0f, 193.0f / 255.0f,   // bottom left
		-0.314f,  0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   14.0f / 255.0f, 245.0f / 255.0f    // top left
	};;
	GLuint _sqElements[SIZESQE] = {
		0, 1, 2,
		2, 3, 0
	};;

public:
	Shape();
	~Shape();
	
	array <GLfloat,SIZESQV> getSquareVertices();
	array <GLuint,SIZESQE> getSquareElements();

	void test();

	float squareVertx[36]{
		// positions              // colors                 // texture coords
		0.314f,  0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   48.0f / 255.0f, 245.0f / 255.0f,   // top right
		0.314f, -0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   48.0f / 255.0f, 193.0f / 255.0f,   // bottom right
		-0.314f, -0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   14.0f / 255.0f, 193.0f / 255.0f,   // bottom left
		-0.314f,  0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   14.0f / 255.0f, 245.0f / 255.0f    // top left
	};
	int squareElem[6]{
		0, 1, 2,
		2, 3, 0
	};
};
#endif

/*
48.0f / 255.0f, 245.0f / 255.0f,   // top right
48.0f / 255.0f, 193.0f / 255.0f,   // bottom right
14.0f / 255.0f, 193.0f / 255.0f,   // bottom left
14.0f / 255.0f, 245.0f / 255.0f	   // top left

		0.314f,  0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   48.0f / 255.0f, 245.0f / 255.0f,   // top right
		0.314f, -0.314f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,   48.0f / 255.0f, 193.0f / 255.0f,   // bottom right
		-0.314f, -0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   14.0f / 255.0f, 193.0f / 255.0f,   // bottom left
		-0.314f,  0.314f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,   14.0f / 255.0f, 245.0f / 255.0f    // top left
*/