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
	void movimimientosPosibles(Coordenada coordIni, Coordenada coordFin);    // función que imprime por pantalla los movimientos posibles de la pieza
	void mueve(int fila, int columna);
	void inicializa();
	void destino(int fila, int columna);
};

