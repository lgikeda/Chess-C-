#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Rey :public PiezaGen {
	bool first_move = true;
public:
	//Constructores
	Rey();
	Rey(Color color, Coordenada coord);
	Sprite spriteN{ "bin/imagenes/reyNegro.png" };
	Sprite spriteB{ "bin/imagenes/reyBlanco.png" };
	void dibuja() override;
	//bool getMovimiento();
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};