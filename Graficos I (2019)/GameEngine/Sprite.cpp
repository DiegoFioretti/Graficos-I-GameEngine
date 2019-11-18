#include "Sprite.h"
#include <iostream>

using namespace std;
Sprite::Sprite() 
{

}

Sprite::~Sprite() 
{

}

void Sprite::spriteParameters(float u, float v, float width, float high, float cant, float space, float time, float totalWidth, float totalHeight) {
{
	int spaceSprites = 0;
	for (int i = 0; i < cant; i++)
	{
		int j = 0;
		//x
		txtVrtx[i][j] = (u + width + spaceSprites + width * i) / totalWidth;
		j++;
		txtVrtx[i][j] = (spaceSprites + u + width*i) / totalWidth;
		j++;
		txtVrtx[i][j] = (totalHeight - v) / totalHeight;
		j++;
		txtVrtx[i][j] = (totalHeight - v - high) / totalHeight;
		spaceSprites += space;
	}
}
void Sprite::setTextureLocation(string& location)
{
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);

	unsigned char* data = stbi_load(location.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		printf("Error: No usable image data");
	}
	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, _texture);
}

unsigned int Sprite::getTexture() 
{
	return _texture;
}