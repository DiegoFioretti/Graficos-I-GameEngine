#include "Game.h"

int main(){
	Game realgame;
	realgame.addNewQuad();
	realgame.ScreenInit();
	/*while (!realgame.isWindowClosed())
	{
		realgame.refreshWindow();
	}*/
	return 0;
}

/*
To do:
pasar la clase input
animaciones
funciones virtuales en base game

*/