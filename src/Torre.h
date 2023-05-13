#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Torre :public PiezaGen {

public:
	//Constructores
	Torre();
	Torre(Color color, Coordenada coord);
	//bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};