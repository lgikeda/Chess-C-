#pragma once
#include "Tablero.h"
#include "Peon.h"
#include <string>
#include "coordenada.h"

class Entorno
{
public:
	Entorno() {}

	Coordenada coord;
	Tablero tablero;

	void inicial();
	void dibuja();
	void raton(int button, int state, int x, int y);
};
