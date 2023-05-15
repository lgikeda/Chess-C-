#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Alfil :public PiezaGen {

public:
	//Constructores
	Alfil();
	Alfil(Color color, Coordenada coord);
	Sprite spriteN{ "bin/imagenes/alfilNegro.png" };
	Sprite spriteB{ "bin/imagenes/alfilBlanco.png" };
	void dibuja() override;
	//Color getColor(Color color);
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};