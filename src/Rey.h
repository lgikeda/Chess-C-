#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Rey :public PiezaGen {

public:
	//Constructores
	Rey();
	Rey(Color color, Coordenada coord);
	bool mov_Legal();

	//void guardarHistorial();
};