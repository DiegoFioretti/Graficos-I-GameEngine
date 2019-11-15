#include "Game.h"

Game::Game()
{
	done = false;
}

Game::~Game()
{
}

void Game::update() 
{
	coutSprite("../Juego/pkm.png", 14, 10, 34, 52, 30, 1);

	//keyPress(letra,0 constante y 1 una vez)
	if (keyPress('q',1))
	{
		//coutSprite("../Juego/pkm.png", 14, 10, 34, 52, 30, 1);
	}
	if (keyPress('w', 1))
	{
		test();
	}
	
	/*if (keyPressOnce('e'))
	{
		entityPos(true, 'z', 0, 0.001f);
		cout << entityPos(false, 'z', 0, 0.0f);
	}*/
	
}