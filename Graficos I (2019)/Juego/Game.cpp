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
		entityPos(true, 'z', 0, 0.001f);
		cout << entityPos(false, 'z', 0, 0.0f);
	}
}