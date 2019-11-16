#ifndef SPRITE_H
#define SPRITE_H
#pragma once
class Sprite
{
public:
	Sprite();
	~Sprite();
	void spriteParameters(float u, float v, float width, float high, float cant, float space, float time, float totalWidth, float totalHeight);
	float txtVrtx[4][4];
};
#endif