#pragma once
#include "Coordenada.h"
#include "PiezaGen.h"

class Rey :public PiezaGen {

public:

	Rey(Color color, Coordenada coord);
	void dibuja() override;
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;

};

