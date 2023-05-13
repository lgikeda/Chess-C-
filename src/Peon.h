#pragma once
#include "PiezaGen.h"

class Peon:public PiezaGen {

public:
	//Constructores
	Peon();
	Peon(Color color, Coordenada coord);
	Sprite spriteN{ "imagenes/peonNegro.png" };
	Sprite spriteB{ "imagenes/peonBlanco.png" };
	void dibuja() override;
	//Color getColor(Color color);
	//bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};