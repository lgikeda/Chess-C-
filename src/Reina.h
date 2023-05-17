#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Reina :public PiezaGen {

public:
	//Constructores
	Reina();
	Reina(Color color, Coordenada coord);
	Sprite spriteN{ "bin/imagenes/reinaNegra.png" };
	Sprite spriteB{ "bin/imagenes/reinaBlanca.png" };
	void dibuja() override;
	//Color getColor(Color color);
//	bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};
