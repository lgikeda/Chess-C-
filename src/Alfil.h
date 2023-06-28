#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Alfil :public PiezaGen {

public:

	Alfil(Color color, Coordenada coord);
	void dibuja() override;;
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;
};