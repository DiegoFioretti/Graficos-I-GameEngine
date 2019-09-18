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
	gameRender.AddShape();
	//Loop que continua hasta no cerrar la ventana
	while (!glfwWindowShouldClose(gameWindow.window()))
	{	
		glfwSetKeyCallback(gameWindow.window(), gameInput.key_callback_static);
		gameRender.WindowRefresh(gameWindow.window());
	}
	//Esta funcion destruye todas las ventanas y libera los recursos utilizados y deja la libreria en un estado no inicializado 
	glfwTerminate();
	return 0;
}

