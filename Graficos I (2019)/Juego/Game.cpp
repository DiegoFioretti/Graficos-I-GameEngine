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
		printf("Holas,");
	}
	
}