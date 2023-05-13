#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Peon:public PiezaGen {
	bool first_move = true;
public:
	//Constructores
	Peon();
	Peon(Color color, Coordenada coord);
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;
	
	void dibuja() override;

	//void guardarHistorial();
};