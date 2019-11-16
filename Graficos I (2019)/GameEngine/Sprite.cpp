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