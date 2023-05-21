#pragma once
#include "PiezaGen.h"
#include "Peon.h"
#include "Caballo.h"
#include "Torre.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Coordenada.h"

#define MAX_PIEZAS 32

class ListaPiezas
{

private:
	PiezaGen* pieza[MAX_PIEZAS];
	int numero;

	bool turno = true; // true -> BLANCAS : false -> NEGRAS
	bool turno_destino = false;

public:

	PiezaGen* final = NULL;
	PiezaGen* start = NULL;
	ListaPiezas();
	virtual ~ListaPiezas();
	bool agregar(PiezaGen* e);
	void inicializa();
	void destino(int fila, int columna);
	void dibuja();
	void mueve(int fila, int columna);
	bool comprobarPeon(PiezaGen* pieza, int fila, int columna);
	bool mirarCasilla(int fila, int columna);
	bool comprobarPieza(PiezaGen* aux, int fila, int columna);
	bool noAtraviesa(PiezaGen* pieza1, int fila, int columna);
	PiezaGen* select_pieza(int fila, int columna);
	bool getTurno(int fila, int columna, bool turno);

	void eliminar(PiezaGen* eliminada) {
		PiezaGen** aux = new PiezaGen * [numero];
		int j = 0;

		for (int i = 0; i < numero; i++) {
			if (pieza[i] != eliminada) {
				aux[j] = pieza[i];
				j++;
			}
			else {
				delete pieza[i];
			}
		}

		for (int i = 0; i < j; i++) {
			pieza[i] = aux[i];
		}
		numero = j;

		delete[] aux;
	}

	bool PosicionIgual(PiezaGen* s, PiezaGen* f) {
		//if (start->getCoordenada() == final->getCoordenada() ? return true : return false);
		return (start->getCoordenada() == final->getCoordenada());
	}
};