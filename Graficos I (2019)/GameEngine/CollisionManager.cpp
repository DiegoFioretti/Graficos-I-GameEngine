#include "CollisionManager.h"

CollisionManager::CollisionManager() {}
CollisionManager::~CollisionManager() {}
bool CollisionManager::checkcollision(Entity& one, Entity& two) {
	/*bool colX = one.topLx + (one.bttmRx - one.topLx) >= two.topLx &&
				two.topLx + (two.bttmRx - two.topLx) >= one.topLx;
	bool colY = one.topLy - (one.topLy - one.bttmRy) >= two.topLy &&
				two.topLy - (two.topLy - two.bttmRy ) >= one.topLy;
			*/

	bool colX = one.bttmRx >= two.topLx &&
		two.bttmRx  >= one.topLx;	
	bool colY = one.bttmRy  <= two.topLy &&
		two.bttmRy <= one.topLy;


	return colX && colY;
}