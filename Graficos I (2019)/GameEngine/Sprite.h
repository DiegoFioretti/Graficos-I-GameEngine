#ifndef SPRITE_H
#define SPRITE_H
#pragma once

#include <string>
#include <GL/glew.h>

//#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
using namespace std;

class Sprite
{
private:
	unsigned int _texture;
public:
	Sprite();
	~Sprite();
	void spriteParameters(float u, float v, float width, float high, float cant, float space, float time, float totalWidth, float totalHeight);
	float txtVrtx[4][4];
	void setTextureLocation(string& location);
	unsigned int getTexture();
};
#endif