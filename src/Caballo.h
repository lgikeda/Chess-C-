#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Caballo :public PiezaGen {

public:
	//Constructores
	Caballo();
	Caballo(Color color, Coordenada coord);
	//bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};
