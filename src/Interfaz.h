#pragma once

#include "Entorno.h"
#include "freeglut.h"
#include "ETSIDI.h"


class Interfaz
{
public:
	Interfaz();
	virtual ~Interfaz();

	void tecla(unsigned char key);
	//void mueve();																//debemos añadirla mas adelante
	void dibuja();
	void raton(int button, int state, int x, int y);

protected:
	Entorno entorno;
	enum Estado { INICIO, SEL_EJERCITO, JUEGO, FIN };
	Estado estado;
};
