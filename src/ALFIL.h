#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Alfil :public PiezaGen {

public:
	//Constructores
	Alfil();
	Alfil(Color color, Coordenada coord);
	bool mov_Legal();

	//void guardarHistorial();
};