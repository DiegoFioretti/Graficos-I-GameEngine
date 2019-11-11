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
		gameInput.keyCall(gameWindow.window());
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
	if (key==gameInput.key){
		return true;
	}
	return false;
}

float BaseGame::entityPos(bool willChange, char axis, int entity, float amount)
{
	return gameRender.entityPosMod(willChange, axis, entity, amount);
}
float BaseGame::entityScale(bool willChange, char axis, int entity, float amount)
{
	return gameRender.entityScaleMod(willChange, axis, entity, amount);
}
float BaseGame::entityRot(bool willChange, char axis, int entity, float amount)
{
	return gameRender.entityRotMod(willChange, axis, entity, amount);
}