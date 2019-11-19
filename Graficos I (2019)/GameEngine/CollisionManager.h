#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H
#include "Entity.h"

#pragma once
class CollisionManager
{
private:
	
public:
	CollisionManager();
	~CollisionManager();
	bool checkcollision(Entity &one, Entity &two);
};
#endif 
