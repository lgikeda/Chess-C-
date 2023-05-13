#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Rey :public PiezaGen {

public:
	//Constructores
	Rey();
	Rey(Color color, Coordenada coord);
	//bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};