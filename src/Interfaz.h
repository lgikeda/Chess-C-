#pragma once

#include "Entorno.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <iostream>

class Interfaz
{
	friend class ListaPiezas;
public:
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
		else j = 0;
	}
	void setEstado() {
		estado = JAQUE;
	}

protected:
	Entorno entorno;
	enum Estado { INICIO, SEL_EJERCITO, JUEGO, FIN, JAQUE };
	Estado estado;
	static int j;
};
