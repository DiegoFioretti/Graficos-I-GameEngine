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
	static void key_callback_static(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif INPUT_H