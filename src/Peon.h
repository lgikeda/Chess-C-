#pragma once
#include "PiezaGen.h"

class Peon:public PiezaGen {
	bool first_move = true;
public:
	//Constructores
	Peon();
	Peon(Color color, Coordenada coord);
	void dibuja() override;
	//Color getColor(Color color);
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;
	//void guardarHistorial();
};