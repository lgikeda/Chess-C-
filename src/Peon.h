#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Peon:public PiezaGen {

public:
	//Constructores
	Peon();
	Peon(Color color, Coordenada coord);
	bool mov_Legal();

	//void guardarHistorial();
};