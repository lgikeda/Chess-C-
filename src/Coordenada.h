
#pragma once

#include <iostream>
#include "Vector2D.h"
#include "ETSIDI.h"

enum {};
using namespace std;


class Coordenada{
	Vector2D fila;
	Vector2D columna;
public:
	//Constructor
	Coordenada();
	Coordenada(int fil, int col);
	
	//Getters
	int getColumna();
	int getFila();
	Vector2D toVector();
	int getColorcasilla();
	string getLetra();

	//Setters
	void setFila();
	void setColumna();
	
	//Convertidores y Operadores
	bool operator == (Coordenada corrd);
	Coordenada operator - (Coordenada coord);

};
