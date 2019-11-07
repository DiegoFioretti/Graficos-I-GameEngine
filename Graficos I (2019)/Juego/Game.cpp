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
	if (keyPress('w'))
	{
		printf("Holas,");
	}
}