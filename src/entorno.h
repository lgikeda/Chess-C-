#pragma once
#include "tablero.h"
#include "piezas_derivadas.h"
#include <string>

class Entorno
{
	int actual_click = 0;
public:
	Entorno() {}

	tablero tablero;
	//Peon peon;
	//Rey rey;

	void inicial();
	void dibuja();
	void mover();
	void tecla(unsigned char);
	void raton(int button, int state, int x, int y);
};