#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Torre :public PiezaGen {

public:
	//Constructores
	Torre();
	Torre(Color color, Coordenada coord);
	Sprite spriteN{ "bin/imagenes/torreNegra.png" };
	Sprite spriteB{ "bin/imagenes/torreBlanca.png" };
	void dibuja() override;
	//Color getColor(Color color);
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};