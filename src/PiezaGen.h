#pragma once
#include "coordenada.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <fstream>
#include <string>

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

	Coordenada getCoordenada();
	//Metodos virtuales
	Color getColor();
	void dibuja();
	//virtual bool movimientoLegal(Coordenada destino) = 0;
	//virtual void mueve(Peon pieza);                                /////////// Movimiento de las piezas
	//virtual void guardarHistorial() = 0;
	//Setters
	void setCoordenada(Coordenada coord);
	void setTipo(Tipo t);
	void setColor(Color c);
	//Getters
	virtual Tipo getTipo() { return tipo; }
	//int getValor() { return valor; }                  ////////////          por si quiero hacer un contador de puntos
};