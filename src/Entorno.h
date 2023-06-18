#pragma once
#include "ListaPiezas.h"
#include "Tablero.h"
#include "Peon.h"
#include "coordenada.h"
#include "freeglut.h"
#include <iostream>
#include <string>

class Entorno
{
	ListaPiezas piezas;
	int tipoPromo;
public:
	Entorno();
	virtual ~Entorno();
	Coordenada coord;
	Tablero tablero;

	void inicial();
	void dibuja();
	void raton(int button, int state, int x, int y);
	void getTipoPromocion(int tipo);
};
