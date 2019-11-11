#include "Input.h"
#include <iostream>
using namespace std;

Input::Input(){
	for (int i = 0; i < sizeof(keyReleased); i++)
	{
		keyReleased[i] = true;
	}
}

Input::~Input(){
}
//cout << glfwGetKey(window, GLFW_KEY_Q);
char Input::keyCall(GLFWwindow* window) {
	//al liberar la tecla que tocas para
	if (glfwGetKey(window, GLFW_KEY_UNKNOWN) == GLFW_RELEASE)
	{
		key = '\0';
	}
	//-------------LETRAS---------------------------
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		return 'q';
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS )
	{
		return 'w';
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		return 'e';
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		return 'r';
	}
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
	{
		return 't';
	}
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
	{
		return 'y';
	}
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
	{
		return 'u';
	}
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
	{
		return 'i';
	}
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
	{
		return 'o';
	}
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
	{
		return 'p';
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		return 'a';
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		return 's';
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		return 'd';
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		return 'f';
	}
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
	{
		return 'g';
	}
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
	{
		return 'h';
	}
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
	{
		return 'j';
	}
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
	{
		return 'k';
	}
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
	{
		return 'l';
	}
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
	{
		return 'z';
	}
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
	{
		return 'x';
	}
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
	{
		return 'c';
	}
	if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
	{
		return 'v';
	}
	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	{
		return 'b';
	}
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
	{
		return 'n';
	}
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
	{
		return 'm';
	}
}

char Input::KeyCallOnce(GLFWwindow* window) {
	int a = 0;
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'q';

	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_RELEASE)
	{
		keyReleased[0] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'w';
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'e';
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'r';
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 't';
	}
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'y';
	}
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'u';
	}
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'i';
	}
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_RELEASE)
	{
		keyReleased[7] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'o';
	}
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'p';
	}
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'a';
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 's';
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'd';
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'f';
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'g';
	}
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'h';
	}
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'j';
	}
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'k';
	}
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'l';
	}
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && keyReleased[a])
	{
		keyReleased[a] = false;
		return 'z';
	}
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS && keyReleased[a])
	{
		return 'x';
		keyReleased[a] = false;
	}
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS && keyReleased[a])
	{
		return 'c';
		keyReleased[a] = false;
	}
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS && keyReleased[a])
	{
		return 'v';
		keyReleased[a] = false;
	}
	if (glfwGetKey(window, GLFW_KEY_V) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS && keyReleased[a])
	{
		return 'b';
		keyReleased[a] = false;
	}
	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS && keyReleased[a])
	{
		return 'n';
		keyReleased[a] = false;
	}
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS && keyReleased[a])
	{
		return 'm';
		keyReleased[a] = false;
	}
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_RELEASE)
	{
		keyReleased[a] = true;
	}
	a++;
	return '\0';
}