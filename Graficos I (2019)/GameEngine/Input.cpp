#include "Input.h"
#include <iostream>
using namespace std;

Input::Input(){
}

Input::~Input(){
}
//cout << glfwGetKey(window, GLFW_KEY_Q);
void Input::keyCall(GLFWwindow* window) {
	//al liberar la tecla que tocas para
	if (glfwGetKey(window, GLFW_KEY_UNKNOWN) == GLFW_RELEASE)
	{
		key = '\0';
	}
	//-------------TECLAS ESPECIALES--------------
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwDestroyWindow(window);
	}
	//-------------LETRAS---------------------------
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		key = 'q';
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS )
	{
		key = 'w';
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		key = 'e';
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		key = 'r';
	}
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
	{
		key = 't';
	}
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
	{
		key = 'y';
	}
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
	{
		key = 'u';
	}
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
	{
		key = 'i';
	}
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
	{
		key = 'o';
	}
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
	{
		key = 'p';
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		key = 'a';
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		key = 's';
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		key = 'd';
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		key = 'f';
	}
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
	{
		key = 'g';
	}
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
	{
		key = 'h';
	}
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
	{
		key = 'j';
	}
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
	{
		key = 'k';
	}
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
	{
		key = 'l';
	}
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
	{
		key = 'z';
	}
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
	{
		key = 'x';
	}
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
	{
		key = 'c';
	}
	if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
	{
		key = 'v';
	}
	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	{
		key = 'b';
	}
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
	{
		key = 'n';
	}
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
	{
		key = 'm';
	}
}