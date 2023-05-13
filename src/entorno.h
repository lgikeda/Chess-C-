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
	//ListaPiezas lista;
	Tablero tablero;

	void inicial();
	void dibuja();
	/*void mover();
	void tecla(unsigned char);*/
	void raton(int button, int state, int x, int y);
};
