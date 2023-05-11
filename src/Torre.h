#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Torre :public PiezaGen {

public:
	//Constructores
	Torre();
	Torre(Color color, Coordenada coord);
	bool mov_Legal();

	//void guardarHistorial();
};