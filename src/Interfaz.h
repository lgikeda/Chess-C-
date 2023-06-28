#pragma once

#include "Entorno.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include <iostream>

class Interfaz
{
private:

	friend class ListaPiezas;
	int seleccionMusica = 0;		//Valor numerico de seleccion de musica
	bool musicaSonando1 = false;
	bool musicaSonando2 = false;	
	bool aspectoAjedrez = false;	// Esta variable indica el aspecto del ajedres que se va a jugar (pudiendo cambiarla cuando se desee)
	bool inicioDePrograma = true;	// Unicamente es true cuando se inicia una partida
	int tipoPromocion;				// Valor numerico de la seleccion de la pieza de promocion
	int seleccionAjedrez;		// Valor numerico que se usa para cambiar de un aspecto a otro

protected:

	Entorno entorno;
	enum Estado { INICIO, MENUPRINCIPAL, SEL_EJERCITO, JUEGO, PROMOCION_B, PROMOCION_N, AJUSTES, FIN, JAQUE };
	Estado estado;	// Estado del programa
	static int j;	// esta variable se usa para cambiar a los estados de jaque y promociones

public:

	Interfaz();
	virtual ~Interfaz();
	void tecla(unsigned char key);						// Interaccion de las teclas
	void dibujaInterfaz();										
	void raton(int button, int state, int x, int y);	// Interaccion con el raton
	static void cambiaEstado(std::string e);			// Funcion de cambio de estado a jaque o promociones

	// Setters //

	void setEstadoJaque();								// Setter de estado = jaque
	void setSeleccionAjedrez(int selec);				// Setter de la variable seleccionAjedrez
};
