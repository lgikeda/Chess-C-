#pragma once
#include "coordenada.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <fstream>
#include <string>
#include <iostream>

using ETSIDI::Sprite;

enum Tipo { REY, DAMA, ALFIL, TORRE, CABALLO, PEON };
enum Color { NEGRO, BLANCO };

class PiezaGen
{
protected:

	Coordenada coord;
	Tipo tipo;						// Tipo de pieza
	Color color;					// Color de pieza
	bool first_move = true;			// Variable que indica si es el primer movimiento de la pieza (se usa para el enroque)

	int tipoAjedrez = 0;				// Esta variable se usa para ver si hay que usar el aspecto tipico de lajedrez o el de La Tierra Media

public:
	
	PiezaGen();
	PiezaGen(Color color, Coordenada coord, Tipo tipo);
	
	~PiezaGen();


	virtual void dibuja() = 0;													// Funcion que se va a usar para dibujar cada pieza
	virtual bool movimientoLegal(int fila, int columna, PiezaGen*) = 0;			// Comprobacion de si el movimiento de la pieza es legal

	// Setters // 

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
};

