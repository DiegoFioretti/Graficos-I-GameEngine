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
	void keyCall(GLFWwindow* window);
	char key;

};

#endif INPUT_H