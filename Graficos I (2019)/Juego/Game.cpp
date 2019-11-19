#include "Game.h"


Game::Game()
{
	done = false;
	addNewQuad("../Juego/pkm.png");

	coutSprite("../Juego/pkm.png", 14, 76, 34, 52, 4, 30, 1,0);
	addNewQuad("../Juego/pkm.png");

	coutSprite("../Juego/pkm.png", 14, 76, 34, 52, 4, 30, 1, 1);
}

Game::~Game()
{
}

void Game::update() 
{

	if (checkCollision(0, 1))
	{
		printf("Colisionando");
	}
	coutSprite("../Juego/pkm.png", 14, 76, 34, 52, 4, 30, 1, 0);
	test(0);
	coutSprite("../Juego/pkm.png", 14, 76, 34, 52, 4, 30, 1, 1);
	test(1);
	//keyPress(letra,0 constante y 1 una vez)
	if (keyPress('q',1))
	{
	}
	if (keyPress('w', 1))
	{
		coutSprite("../Juego/pkm.png", 14, 200, 34, 52, 4, 30, 1,0);
		test(0);
		entityPos(true, 'y', 0, 0.1f);
	}
	if (keyPress('a', 1))
	{
		coutSprite("../Juego/pkm.png", 14, 76, 34, 52, 4, 30, 1,0);
		test(0);
		entityPos(true, 'x', 0, -0.1f);
	}
	if (keyPress('s', 1))
	{
		coutSprite("../Juego/pkm.png", 14, 10, 34, 52, 4, 30, 1,0);
		test(0);
		entityPos(true, 'y', 0, -0.1f);
	}
	if (keyPress('d', 1))
	{
		coutSprite("../Juego/pkm.png", 14, 138, 34, 52, 4, 30, 1,0);
		test(0);
		entityPos(true, 'x', 0, 0.1f);
	}

	if (keyPress('i', 1))
	{
		coutSprite("../Juego/pkm.png", 14, 138, 34, 52, 4, 30, 1, 1);
		test(1);
		entityPos(true, 'x', 1, 0.1f);
	}if (keyPress('o', 1))
	{
		coutSprite("../Juego/pkm.png", 14, 138, 34, 52, 4, 30, 1, 1);
		test(1);
		entityPos(true, 'y', 1, 0.1f);
	}

	
	/*if (keyPressOnce('e'))
	{
		entityPos(true, 'z', 0, 0.001f);
		cout << entityPos(false, 'z', 0, 0.0f);
	}*/
	
}

//coutSprite("../Juego/pkm.png", 14, 10, 34, 52, 4, 30, 1);

/*

Timer

#include <chrono>

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

*/