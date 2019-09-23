#include "Input.h"
#include <iostream>
using namespace std;

Input::Input()
{
	
}


Input::~Input()
{
}

float Input::keyE(float rotate) {

	rotate--;
	return rotate;
}
float Input::keyQ(float rotate) {

	rotate++;
	return rotate;
}

// 256	scape		salir
// 87	w			movimiento
// 65	a			"
// 83	s			"
// 68	d			"
// 81	q			rotacion
// 69	e			"
// 67	c			color
