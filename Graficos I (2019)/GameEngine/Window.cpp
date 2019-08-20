#include "Window.h"

Window::Window()
{
}

int Window::CustomWindow(int width, int height) 
{
	if (!glfwInit())
		return -1;

	_window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!_window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(_window);
}

Window::~Window()
{
}

GLFWwindow* Window::window()
{
	return _window;
}
