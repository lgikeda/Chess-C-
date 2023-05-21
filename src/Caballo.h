#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Caballo :public PiezaGen {

public:
	//Constructores
	Caballo();
	Caballo(Color color, Coordenada coord);
	Sprite spriteN{ "bin/imagenes/caballoNegro.png" };
	Sprite spriteB{ "bin/imagenes/caballoBlanco.png" };
	void dibuja() override;
	//Color getColor(Color color);
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};
