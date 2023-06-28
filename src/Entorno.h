#pragma once
#include "ListaPiezas.h"
#include "Tablero.h"
#include "Peon.h"
#include "coordenada.h"
#include "freeglut.h"
#include <iostream>
#include <string>

class Entorno
{
private:

	ListaPiezas piezas;
	int tipoPromo;				// Variable intermedia para poder transportar el tipo de promocion desde el Interfaz.h a PiezaGen.h

public:
	Entorno();
	virtual ~Entorno();
	Coordenada coord;
	Tablero tablero;

	void inicial();											// Inicializacion de las piezas
	void dibuja();											// Funcion para dibujar tanto el tablero como las piezas
	void raton(int button, int state, int x, int y);		// Interaccion con el raton

	// Setters // 

	void setSeleccionAjedrez(int seleccion);				// Setter de selesscion de ajedrez

	// Getters //
	void getTipoPromocion(int tipo);						// Getter de tipoPromo
};
