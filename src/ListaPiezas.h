#pragma once
#include "PiezaGen.h"

#define MAX_PIEZAS 32

class ListaPiezas
{

private:
	PiezaGen* pieza[MAX_PIEZAS];
	int numero;

public:

	ListaPiezas();
	virtual ~ListaPiezas();
	bool agregar(PiezaGen* e);
	void dibuja();
	void movimiento();
};