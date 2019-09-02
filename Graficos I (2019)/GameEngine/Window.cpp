#include "Window.h"

Window::Window()
{
	glfwInit();

	_window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);
	if (!_window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(_window);
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

void Window::SetScreenWidth(int width)
{

}

void Window::SetScreenHeight(int height) 
{

}
