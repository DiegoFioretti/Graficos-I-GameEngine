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
		//hace refresh de la ventana
		gameRender.WindowRefresh(gameWindow.window());
		//Si estas en la ventana toma los imputs
		KeyCallback(gameWindow.window());
	}
	
	//Esta funcion destruye todas las ventanas y libera los recursos utilizados y deja la libreria en un estado no inicializado 
	glfwTerminate();
	return 0;
	
}

void BaseGame::KeyCallback(GLFWwindow* window) {
	//======================================== MOVIMIENTO ========================================
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		gameRender.posicionY = gameInput.keyW(gameRender.posicionY);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		gameRender.posicionY = gameInput.keyS(gameRender.posicionY);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		gameRender.posicionX = gameInput.keyA(gameRender.posicionX);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		gameRender.posicionX = gameInput.keyD(gameRender.posicionX);
	}
	//======================================== TAMANO ========================================

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		gameRender.sizeY = gameInput.keyRIGHT(gameRender.sizeY);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		gameRender.sizeY = gameInput.keyLEFT(gameRender.sizeY);
		
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		gameRender.sizeX = gameInput.keyDOWN(gameRender.sizeX);
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		gameRender.sizeX = gameInput.keyUP(gameRender.sizeX);
	}
	//======================================== ROTACIONES ========================================
	//x
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
	{
		gameRender.rotateX = gameInput.keyU(gameRender.rotateX);
	}
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
	{
		gameRender.rotateX = gameInput.keyY(gameRender.rotateX);
	}
	//y
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
	{
		gameRender.rotateY = gameInput.keyH(gameRender.rotateY);
	}
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
	{
		gameRender.rotateY = gameInput.keyJ(gameRender.rotateY);
	}
	//z
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
	{
		gameRender.rotateZ = gameInput.keyN(gameRender.rotateZ);
	}
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
	{
		gameRender.rotateZ = gameInput.keyM(gameRender.rotateZ);
	}
	//========================================CERRAR VENTANA========================================
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		gameInput.keyEsc(window);

	}
}

/*Para tocar 1 sola vez
if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
	{
		if (onPress3) {
			gameRender.rotateZ = gameInput.key1(gameRender.rotateZ);
			onPress3 = false;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_RELEASE)
	{
		onPress3 = true;
	}
	*/