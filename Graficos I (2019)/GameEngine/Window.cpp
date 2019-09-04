#include "Window.h"

Window::Window()
{
	//??
	glfwInit();
	//Creacion de la ventana (ancho, alto, nombre , el monitor a usar en full screen o null en ventana, para compartir recursos de la ventana o null )
	_window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);
	//Si la ventana no esta abierta cierra todo
	if (!_window)
	{
		glfwTerminate();
	}
	//Hace que haya un thread ocupado en la mantencion de la ventana
	glfwMakeContextCurrent(_window);
}

int Window::CustomWindow(int width, int height) 
{
	return 0;
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
