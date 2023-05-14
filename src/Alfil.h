#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Alfil :public PiezaGen {

public:
	//Constructores
	Alfil();
	Alfil(Color color, Coordenada coord);
	Sprite spriteN{ "imagenes/alfilNegro.png" };
	Sprite spriteB{ "imagenes/alfilBlanco.png" };
	void dibuja() override;
	//Color getColor(Color color);
	//bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};