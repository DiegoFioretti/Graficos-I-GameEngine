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
	char keyCall(GLFWwindow* window);
	char KeyCallOnce(GLFWwindow* window);
	char key;
	bool keyReleased [30];
	bool a = true;
};

#endif INPUT_H