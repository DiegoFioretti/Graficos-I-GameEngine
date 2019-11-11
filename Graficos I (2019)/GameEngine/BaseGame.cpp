#include "BaseGame.h"
#include <iostream>


using namespace std;
BaseGame::BaseGame(){
	//Esconde la consola
	//::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

BaseGame::~BaseGame(){
}


int BaseGame::ScreenInit() {
	//Loop que continua hasta no cerrar la ventana
	while (!glfwWindowShouldClose(gameWindow.window()))
	{	
		update();
		//hace refresh de la ventana
		gameRender.WindowRefresh(gameWindow.window());
		//Si estas en la ventana toma los imputs
		
	}
	//Esta funcion destruye todas las ventanas y libera los recursos utilizados y deja la libreria en un estado no inicializado 
	glfwTerminate();
	return 0;
}


void BaseGame::addNewQuad()
{
	gameRender.addEntity();
}

bool BaseGame::keyPress(char key) {
	if (key== gameInput.keyCall(gameWindow.window())){
		return true;
	}
	return false;
}

bool BaseGame::keyPressOnce(char key) {
	//cout << gameInput.KeyCallOnce(gameWindow.window());
	//cout << key;
	if (key == gameInput.KeyCallOnce(gameWindow.window())) {
		return true;
	}
	return false;
}