#pragma once
#include "ListaPiezas.h"
#include "Tablero.h"
#include "Peon.h"
#include <string>
#include "coordenada.h"

class Entorno
{
	ListaPiezas piezas;
public:
	Entorno() {}

	Coordenada coord;
	Tablero tablero;

	void inicial();
	void dibuja();
	void promocionar(tipo_pieza tipo);
	void raton(int button, int state, int x, int y);
};
