#pragma once
#include "Coordenada.h"
#include <fstream>
#include "PiezaGen.h"

<<<<<<<< HEAD:src/Alfil.h
class Alfil :public PiezaGen {

public:
	//Constructores
	Alfil();
	Alfil(Color color, Coordenada coord);
	//bool movimientoLegal(int fila, int columna, PiezaGen*) override;

	//void guardarHistorial();
};
========
using ETSIDI::Sprite;


class Peon : public Pieza
{
public:
	Peon();
	Peon(int _f, int _c, int _color);
	virtual ~Peon() {}
	void dibuja();
	int getTipoPieza();

};
>>>>>>>> 337cc8dc5176af55ad4ed193da5af98be3aabbd5:src/Peon.h
