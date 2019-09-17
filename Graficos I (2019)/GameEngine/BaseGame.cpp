#include "BaseGame.h"

BaseGame::BaseGame()
{
	//Esconde la consola
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

BaseGame::~BaseGame()
{
}

int BaseGame::ScreenInit() 
{
	gameRender.AddShape(shapes);
	//Loop que continua hasta no cerrar la ventana
	while (!glfwWindowShouldClose(gameWindow.window()))
	{	
		gameRender.WindowRefresh(gameWindow.window(), shapes);
	}
	//Esta funcion destruye todas las ventanas y libera los recursos utilizados y deja la libreria en un estado no inicializado 
	glfwTerminate();
	return 0;
}