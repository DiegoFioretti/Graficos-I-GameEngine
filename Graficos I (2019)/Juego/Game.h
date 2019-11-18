#ifndef GAME_H
#define GAME_H
#pragma once
#include <BaseGame.h>
class BASEGAMELIB Game : public BaseGame
{
private:
	bool doop = true;
	bool done;
public:
	Game();
	~Game();
	void update();
};
#endif