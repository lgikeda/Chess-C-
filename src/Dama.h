#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Dama :public PiezaGen {

public:

	Dama(Color color, Coordenada coord);
	void dibuja() override;
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;
};
