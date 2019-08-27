#ifndef WINDOW_H
#define WINDOW_H
#pragma once

#define WIDTH 640
#define HEIGHT 480

#include <GLFW/glfw3.h>

class Window
{
private:
	GLFWwindow* _window;
public:
	Window();
	int CustomWindow(int width, int height);
	~Window();
	GLFWwindow* window();
	void SetScreenWidth(int width);
	void SetScreenHeight(int height);
};
#endif  
