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
	
	if (keyPress('q'))
	{
		printf("chau,");
	}
	if (keyPressOnce('w'))
	{
		printf("atun,");
	}
	if (keyPressOnce('e'))
	{
		entityPos(true, 'z', 0, 0.001f);
		cout << entityPos(false, 'z', 0, 0.0f);
	}
	
}