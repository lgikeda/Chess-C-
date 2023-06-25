#pragma once

#include "Entorno.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <iostream>

class Interfaz
{
	friend class ListaPiezas;
public:

	int tipoPromocion;

	Interfaz();
	virtual ~Interfaz();

	void tecla(unsigned char key);
	//void mueve();																//debemos añadirla mas adelante
	void dibuja();
	void raton(int button, int state, int x, int y);
	static void cambiaEstado(std::string e) {
		if (e == "JAQUE AL REY NEGRO") j = 1;
		else if (e == "JAQUE AL REY BLANCO") j = 2;
		else if (e == "JAQUE MATE AL REY NEGRO") j = 3;
		else if (e == "JAQUE MATE AL REY BLANCO") j = 4;
		else if (e == "PROMOCION BLANCA") j = 5;
		else if (e == "PROMOCION NEGRA") j = 6;
		//else if (e == "JUEGO") j = 7;
		else j = 0;
	}
	void setEstado() {
		estado = JAQUE;
	}

protected:
	Entorno entorno;
	enum Estado { INICIO, SEL_EJERCITO, JUEGO, PROMOCION_B, PROMOCION_N,FIN, JAQUE };
	Estado estado;
	static int j;
};
