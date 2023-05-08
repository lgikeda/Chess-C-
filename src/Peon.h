#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

class Peon:public PiezaGen {

public:
	//Constructores
	Peon();
	Peon(Color color, Coordenada coord);
	bool mov_Legal(Vector2D FilFin, Vector2D ColFin);

	//void guardarHistorial();
};