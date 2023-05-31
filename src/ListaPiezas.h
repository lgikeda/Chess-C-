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

	bool e_jaque = false; // estado de jaque
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
	void eliminar(PiezaGen* eliminada);
	bool posicionIgual(PiezaGen* pstart, PiezaGen* pfinal) { return pstart->getCoordenada() == pfinal->getCoordenada(); }
	bool enroque(int fila, int columna);
	bool comprobarPeon(int fila, int columna);
	bool comprobarAlfil(int fila, int columna);
	bool comprobarTorre(int fila, int columna);
	bool comprobarReina(int fila, int columna);
	bool comprobarRey(int fila, int columna);
	bool mirarCasilla(PiezaGen* start,int fila, int columna);
	bool comprobarPieza(int fila, int columna);
	PiezaGen* select_pieza(int fila, int columna);
	bool getTurno(int fila, int columna, bool turno);
	bool jaque(PiezaGen* s, PiezaGen* f);
	bool trayecto(PiezaGen* s, PiezaGen* f);

	bool permisoAlJaque(PiezaGen* s) {
		PiezaGen* rey = NULL;	//rey amigo
		PiezaGen* siguientePosicion = NULL;
		for (int i = 0; i < numero; i++) {
			if ((pieza[i]->getTipo() == REY) and (pieza[i]->getColor() == s->getColor())) {
				rey = pieza[i];
			}
		}
		for (int i = 0; i < numero; i++) {
			if ((pieza[i]->getTipo() != REY) and (pieza[i]->getColor() != rey->getColor())) {
				start = pieza[i];
				if (pieza[i]->movimientoLegal(rey->getCoordenada().fila, rey->getCoordenada().columna, rey) and comprobarPieza(rey->getCoordenada().fila, rey->getCoordenada().columna)) {
					std::cout << "Permiso al jaque 1." << std::endl;
					if (final != NULL) {
						if (pieza[i] == final) return false;
					}else return true;
				}
			}
		}
		std::cout << "Movimiento no permitido por poner en jaque al rey." << std::endl;
		return false;
	}
};