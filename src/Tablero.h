#pragma once
#include "ListaPiezas.h"
#include "Peon.h"
#include "Caballo.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Coordenada.h"

#include "freeglut.h"
#include <vector>

class Tablero {
private :
	ListaPiezas piezas;
public: 
	
	Tablero();
	void dibujarTablero();
	void dibuja();
	void mueve();
	void inicializa();
};

