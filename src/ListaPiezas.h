#pragma once
#include "PiezaGen.h"

#define MAX_PIEZAS 32

class ListaPiezas
{

private:
	PiezaGen* pieza[MAX_PIEZAS];
	int numero;

public:

	PiezaGen* final = NULL;
	PiezaGen* start = NULL;
	ListaPiezas();
	virtual ~ListaPiezas();
	bool agregar(PiezaGen* e);
	void dibuja();
	void mueve(int fila, int columna);
	void destino(int fila, int columna);
	PiezaGen* select_pieza(int fila, int columna);
};