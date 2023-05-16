#pragma once
#include "coordenada.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <fstream>
#include <string>
#include <iostream>

using ETSIDI::Sprite;

enum Tipo { REY, REINA, ALFIL, TORRE, CABALLO, PEON };
enum Color { NEGRO, BLANCO };

class PiezaGen
{
protected:

	Coordenada coord;
	Tipo tipo;
	//int valor;
	Color color;

public:
	//Constructores
	PiezaGen(Color color, Coordenada coord, Tipo tipo);
	PiezaGen();
	~PiezaGen();

	int getPos_x();
	int getPos_y();
	Color getColor();
	virtual void dibuja() = 0;
	virtual bool movimientoLegal(int fila, int columna, PiezaGen*) = 0;
	//virtual void mueve(Peon pieza);                                /////////// Movimiento de las piezas
	//virtual void guardarHistorial() = 0;
	//Setters
	void setCoordenada(int fila, int columna);
	void setTipo(Tipo t);
	void setColor(Color c);

	std::pair<int,int> getCoordenada() {
		return {0,0};
	};
	//Getters
	virtual Tipo getTipo() { return tipo; }
	//int getValor() { return valor; }                  ////////////          por si quiero hacer un contador de puntos
};

