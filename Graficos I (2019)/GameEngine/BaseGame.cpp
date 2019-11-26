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


void BaseGame::addNewQuad(float x, float y)
{
	gameRender.addEntity(x,y);
}

bool BaseGame::keyPress(char key, int num) {
	return gameInput.keyCall(gameWindow.window(), key, num);
}

bool BaseGame::checkCollision(int entA, int entB,int cualCol) {
	switch (cualCol)
	{
	case 0:
		return gameCollider.checkcollision(gameRender.getGameEntities()[entA], gameRender.getGameEntities()[entB]);
		break;

	default:
		return 0;
		break;
	}

	
}
void BaseGame::hitCol() {
	entityPos(true, eje, entidad, cant);
}

float BaseGame::entityPos(bool willChange, char axis, int entity, float amount)
{

	eje = axis;
	entidad = entity;
	cant = amount;
	gameRender.entityPosMod(willChange, axis, entity, amount);

	if (checkCollision(0, 1, 0)){
		float num = amount * -2.0f;
		gameRender.entityPosMod(willChange, axis, entity, num);
		return 0.0f;
	}
	///
	return 0.0f;
}
float BaseGame::entityScale(bool willChange, char axis, int entity, float amount)
{
	return gameRender.entityScaleMod(willChange, axis, entity, amount);
}
float BaseGame::entityRot(bool willChange, char axis, int entity, float amount)
{
	return gameRender.entityRotMod(willChange, axis, entity, amount);
}

void BaseGame::coutSprite(const char* image, float u, float v, float width, float high, float cant, float space, float time, int entity) {
	gameRender.newSrpiteSheet(image);
	gameRender.spriteParamts( u, v, width, high,cant, space, time, entity);
}
void BaseGame::test(int entity) {
	gameRender.cutSrpiteSheet(entity);
}





/*
int arr[5]{0,1,2,3,4};
test(arr,5);

void BaseGame::test(int a[], int length) {
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << ", ";
	}

}*/