#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Alfil :public PiezaGen {

public:
	//Constructores
	Alfil();
	Alfil(Color color, Coordenada coord);
	//bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};