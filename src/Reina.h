#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Reina :public PiezaGen {

public:
	//Constructores
	Reina();
	Reina(Color color, Coordenada coord);
	bool mov_Legal();

	//void guardarHistorial();
};
