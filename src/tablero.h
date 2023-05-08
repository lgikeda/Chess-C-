#pragma once
#include "piezas_derivadas.h"
#include <vector>

class tablero {
	std::vector<Pieza*> total_piezas;
	Pieza* start = NULL;
	Pieza* final = NULL;
public: 
	tablero();
	void dibujartablero();
	Pieza* select_pieza(int x, int y);
	void mover(int x, int y);
	void destino(int x, int y);
};