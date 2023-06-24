#pragma once
#include "coordenada.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <fstream>
#include <string>
#include <iostream>
//#include <vector>

using ETSIDI::Sprite;

enum Tipo { REY, REINA, ALFIL, TORRE, CABALLO, PEON };
enum Color { NEGRO, BLANCO };

class PiezaGen
{
protected:

	Coordenada coord;
	Tipo tipo;
	Color color;
	bool first_move = true;

	int tipoAjedrez;

public:
	//Constructores
	PiezaGen(Color color, Coordenada coord, Tipo tipo);
	PiezaGen();
	~PiezaGen();


	virtual void dibuja() = 0;
	virtual bool movimientoLegal(int fila, int columna, PiezaGen*) = 0;
	//virtual void guardarHistorial() = 0;
	//Setters
	void setCoordenada(int fila, int columna);
	void setTipo(Tipo t);
	void setColor(Color c);

	//Getters

	int getPos_x();
	int getPos_y();
	Color getColor();
	bool getMovimiento();
	Coordenada getCoordenada();
	virtual Tipo getTipo() { return tipo; }
	virtual void setTipoAjedrez(int tipo);
	int getTipoAjedrez() { return tipoAjedrez; }
	//int getValor() { return valor; }                  ////////////          por si quiero hacer un contador de puntos
};

