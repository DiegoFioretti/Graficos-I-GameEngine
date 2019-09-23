#include "BaseGame.h"
#include <iostream>


using namespace std;
BaseGame::BaseGame()
{
	//Esconde la consola
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

BaseGame::~BaseGame()
{
}


int BaseGame::ScreenInit() 
{
	
	//Loop que continua hasta no cerrar la ventana
	while (!glfwWindowShouldClose(gameWindow.window()))
	{	

		gameRender.WindowRefresh(gameWindow.window());

		KeyCallback(gameWindow.window());
	}
	
	//Esta funcion destruye todas las ventanas y libera los recursos utilizados y deja la libreria en un estado no inicializado 
	glfwTerminate();
	return 0;
	
}

void BaseGame::KeyCallback(GLFWwindow* window) {
	if (glfwGetKey(window,GLFW_KEY_E)== GLFW_PRESS)
	{
		gameRender.rotate = gameInput.keyE(gameRender.rotate);
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		gameRender.rotate = gameInput.keyQ(gameRender.rotate);
	}
}

