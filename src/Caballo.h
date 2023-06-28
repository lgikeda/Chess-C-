#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Caballo :public PiezaGen {

public:

	Caballo(Color color, Coordenada coord);
	void dibuja() override;
	bool movimientoLegal(int fila, int columna, PiezaGen*) override;
};
