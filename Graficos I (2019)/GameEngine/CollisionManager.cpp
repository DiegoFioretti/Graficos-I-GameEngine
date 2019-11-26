#include "CollisionManager.h"
#include <iostream>
using namespace std;

CollisionManager::CollisionManager() {}
CollisionManager::~CollisionManager() {}
bool CollisionManager::checkcollision(Entity& one, Entity& two) {
	/*bool colX = one.topLx + (one.bttmRx - one.topLx) >= two.topLx &&
				two.topLx + (two.bttmRx - two.topLx) >= one.topLx;
	bool colY = one.topLy - (one.topLy - one.bttmRy) >= two.topLy &&
				two.topLy - (two.topLy - two.bttmRy ) >= one.topLy;
			*/


	bool colX = one.bttmRx >= two.topLx - 0.166f &&
		two.bttmRx + 0.166f >= one.topLx;

	bool colY = one.bttmRy  <= two.topLy + 0.086f &&
		two.bttmRy - 0.086f <= one.topLy;

	

	return colX && colY;
}

void CollisionManager::cantMovida(float num) {
	cantidad = num;
}
bool checkcollisionL(Entity& one, Entity& two) {
	return one.bttmRx >= two.topLx - 0.166f;
}

bool checkcollisionR(Entity& one, Entity& two) {
	return one.topLx <= two.bttmRx + 0.166f;
}

bool checkcollisionT(Entity& one, Entity& two) {
	return one.bttmRy <= two.topLy + 0.086f;
}

bool checkcollisionD(Entity& one, Entity& two) {
	return one.topLy >= two.bttmRy - 0.086f;
}