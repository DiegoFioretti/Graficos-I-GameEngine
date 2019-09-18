#include "Input.h"
#include <iostream>
using namespace std;

Input::Input()
{
	
}


Input::~Input()
{
}

void Input::key_callback_static(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//cout << key << endl;
	switch (key)
	{

	case 256:
		glfwDestroyWindow(window);
		break;
	default:
		break;
	}
}
// 256	scape		salir
// 87	w			movimiento
// 65	a			"
// 83	s			"
// 68	d			"
// 81	q			rotacion
// 69	e			"
// 67	c			color
