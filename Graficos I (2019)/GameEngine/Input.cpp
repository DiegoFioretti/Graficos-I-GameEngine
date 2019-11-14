#include "Input.h"
#include <iostream>
#include <chrono>
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
bool Input::keyCall(GLFWwindow* window,int key,int num) {
	//-------------LETRAS---------------------------
	int a = 0;

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
		if (key == 'q'){
			switch (num){
			case 0:
					return true;
				break;
			case 1:
				if (keyReleased[a]){
					keyReleased[a] = false;
					return true;
				}
				break;

			default:
				break;
			}
		}		
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_RELEASE) {
		keyReleased[a] = true;
	}
	a++;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		if (key == 'w') {
			switch (num) {
			case 0:
				return true;
				break;
			case 1:
				if (keyReleased[a]) {
					keyReleased[a] = false;
					return true;
				}
				break;

			default:
				break;
			}
		}
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE) {
		keyReleased[a] = true;
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

bool Input::keyPress() {
	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
		timer += elapsed_seconds.count();
		if (timer*10000>0.5f)
		{
			timer = 0;
			return true;
		}
		return false;
}