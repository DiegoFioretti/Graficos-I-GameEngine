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
	void setTextureLocation(string& location);
	unsigned int getTexture();
};
#endif