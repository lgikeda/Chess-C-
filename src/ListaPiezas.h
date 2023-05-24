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
	void eliminar(PiezaGen* eliminada);
	bool posicionIgual(PiezaGen* pstart, PiezaGen* pfinal) { return pstart->getCoordenada() == pfinal->getCoordenada(); }
	bool enroque(int fila, int columna);
	bool comprobarPeon(int fila, int columna);
	bool comprobarAlfil(int fila, int columna);
	bool comprobarTorre(int fila, int columna);
	bool comprobarReina(int fila, int columna);
	bool comprobarRey(int fila, int columna);
	bool mirarCasilla(int fila, int columna);
	bool comprobarPieza(int fila, int columna);
	PiezaGen* select_pieza(int fila, int columna);
	bool getTurno(int fila, int columna, bool turno);
	bool jaque(PiezaGen* rey);
	bool comprobarAlfilJaque(PiezaGen* alfil, int fila, int columna);
	bool comprobarTorreJaque(PiezaGen* torre, int fila, int columna);
};