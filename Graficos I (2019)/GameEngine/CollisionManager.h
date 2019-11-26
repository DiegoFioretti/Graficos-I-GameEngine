#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "Entity.h"

#pragma once
class CollisionManager
{
private:
	float cantidad;
public:
	CollisionManager();
	~CollisionManager();
	bool checkcollision(Entity &one, Entity &two);
	void cantMovida(float num);
	bool checkcollisionL(Entity& one, Entity& two);
	bool checkcollisionR(Entity& one, Entity& two);
	bool checkcollisionT(Entity& one, Entity& two);
	bool checkcollisionD(Entity& one, Entity& two);
};
#endif 
