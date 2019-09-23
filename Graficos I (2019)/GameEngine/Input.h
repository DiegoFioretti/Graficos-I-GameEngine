#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>

#pragma once
class Input
{
private:

public:
	Input();
	~Input();
	float keyE(float rotate);
	float keyQ(float rotate);
};

#endif INPUT_H