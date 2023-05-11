
#pragma once

#include <iostream>
#include "ETSIDI.h"

enum {};
using namespace std;


class Coordenada{
	
public:
	int fila;
	int columna;
	//Constructor
	Coordenada();
	
	//Getters
	int getColumna();
	int getFila();

	int getColorcasilla();
	string getLetra();

	//Setters
	void setFila();
	void setColumna();
	
	//Convertidores y Operadores
	bool operator == (Coordenada corrd);
	Coordenada operator + (Coordenada);
	Coordenada operator - (Coordenada coord);

};
