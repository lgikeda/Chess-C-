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
	int tipoPromocion = 0;
	bool condicionPromocion = false;	//Esta variable hace que solo salte una vez el menu de promocion de piezas

	bool e_jaque = false; // estado de jaque
	bool turno = true; // true -> BLANCAS : false -> NEGRAS
	bool turno_destino = false;

public:

	//static int cambio;

	PiezaGen* final = NULL;
	PiezaGen* start = NULL;
	Coordenada CoordProm;
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
	void setTipoPromocion(int tipo);

	bool movHaciaRey(PiezaGen* rey) {
		for (int i = 0; i < numero; i++) {
			if ((pieza[i]->getTipo() != REY) and (pieza[i]->getColor() != rey->getColor())) {
				start = pieza[i];
				//Comprobacion de movimiento de cada pieza hacia el rey y comprobacion de obtaculo en su movimiento
				if (pieza[i]->movimientoLegal(rey->getCoordenada().fila, rey->getCoordenada().columna, rey) and comprobarPieza(rey->getCoordenada().fila, rey->getCoordenada().columna)) {
					std::cout << "Permiso al jaque." << std::endl;
					if (final != NULL) {
						//Comprobacion de igualdad entre la pieza que realiza el jaque y la pieza de la posicion final
						if (pieza[i] == final) return false;
						else return true;
					}
					else return true;
				}
			}
		}
	}

	bool permisoAlJaque(PiezaGen* s) {
		PiezaGen* rey = NULL;	//rey amigo
		PiezaGen* siguientePosicion = NULL;
		for (int i = 0; i < numero; i++) {
			if ((pieza[i]->getTipo() == REY) and (pieza[i]->getColor() == s->getColor())) {
				rey = pieza[i];
			}
		}
		//if (movHaciaRey(rey)) return true;
		for (int i = 0; i < numero; i++) {
			if ((pieza[i]->getTipo() != REY) and (pieza[i]->getColor() != rey->getColor())) {
				start = pieza[i];
				//Comprobacion de movimiento de cada pieza hacia el rey y comprobacion de obtaculo en su movimiento
				if (pieza[i]->movimientoLegal(rey->getCoordenada().fila, rey->getCoordenada().columna, rey) and comprobarPieza(rey->getCoordenada().fila, rey->getCoordenada().columna)) {
					std::cout << "Permiso al jaque." << std::endl;
					if (final != NULL) {
						//Comprobacion de 
						if (pieza[i] == final) return false;
						else return true;
					}else return true;
				}
			}
		}
		std::cout << "Movimiento no permitido por poner en jaque al rey." << std::endl;
		return false;
	}

	bool jaqueMate() {
		PiezaGen* aux = NULL;
		for (int i = 0; i < numero; i++) {
			if ((pieza[i]->getTipo() == REY) and (pieza[i]->getColor() != start->getColor())){
				aux = pieza[i];
			}
		}
		if ((not movRey(aux)) and (not proteccionRey(aux))) {
			return true;
		}
		else return false;
	}

	bool movRey(PiezaGen* p) {
		PiezaGen* aux = start;
		int cont = 0;
		int posibilidad = 0;
		int fila = p->getCoordenada().fila;
		int columna = p->getCoordenada().columna;
		for (int i = fila - 1; i <= fila + 1; i++) {
			for (int j = columna - 1; j <= columna + 1; j++) {
				//COMPROBACION DE PERMANECER DENTRO DEL TABLERO
				if ((j>0)and(j < 9) and (i < 0) and (i < 9)) {
					//iteracion de recorrido de cada pieza
					for (int k = 0; k < numero; k++) {
						if ((pieza[k]->getColor() != p->getColor()) and pieza[k]->getTipo() != REY) {
							start = pieza[k];
							if ((pieza[k]->movimientoLegal(i, j, select_pieza(i, j))) and comprobarPieza(i, j)) {
								cont = 0;
								break;
							}
							else cont++;

							start = aux;
						}
					}
					if (cont != 0) return true;
				}
			}
		}
		if (cont != 0) return true;
		else return false;
	}

	bool proteccionRey(PiezaGen* p) {
		PiezaGen* aux = NULL;
		PiezaGen* aux1 = NULL;
		for (auto& elemento : pieza) {
			aux = elemento;
			if ((p->getColor() != elemento->getColor()) and (p->getTipo() != elemento->getTipo())) {
				if (start->getCoordenada().fila <= p->getCoordenada().fila) {
					for (int i = start->getCoordenada().fila; i < p->getCoordenada().fila; i++) {
						if (start->getCoordenada().columna <= p->getCoordenada().columna) {
							for (int j = start->getCoordenada().columna; j < p->getCoordenada().columna; j++) {
								aux1 = start;
								start = elemento;
								if (elemento->movimientoLegal(i, j, select_pieza(i, j)) and comprobarPieza(i, j)) {
									elemento->setCoordenada(i, j);
									start = aux1;
									if (/*start->movimientoLegal(p->getCoordenada().fila, p->getCoordenada().columna, p) and */comprobarPieza(p->getCoordenada().fila, p->getCoordenada().columna)) {

									}
									else {
										//retorna true cuando hay una posible jugada para obstaculizar el jaque
										elemento = aux;
										return true;
									}
								}
								start = aux1;
							}
						}
						else {
							for (int j = start->getCoordenada().columna; j > p->getCoordenada().columna; j--) {
								aux1 = start;
								start = elemento;
								if (elemento->movimientoLegal(i, j, select_pieza(i, j)) and comprobarPieza(i, j)) {
									elemento->setCoordenada(i, j);
									start = aux1;
									if (/*start->movimientoLegal(p->getCoordenada().fila, p->getCoordenada().columna, p) and */ comprobarPieza(p->getCoordenada().fila, p->getCoordenada().columna)) {

									}
									else {
										elemento = aux;
										return true;
									}
								}
								start = aux1;
							}
						}
					}
				}
				else {
					for (int i = start->getCoordenada().fila; i > p->getCoordenada().fila; i--) {
						if (start->getCoordenada().columna < p->getCoordenada().columna) {
							for (int j = start->getCoordenada().columna; j < p->getCoordenada().columna; j++) {
								aux1 = start;
								start = elemento;
								if (elemento->movimientoLegal(i, j, select_pieza(i, j)) and comprobarPieza(i, j)) {
									elemento->setCoordenada(i, j);
									start = aux1;
									if (/*start->movimientoLegal(p->getCoordenada().fila, p->getCoordenada().columna, p) and */comprobarPieza(p->getCoordenada().fila, p->getCoordenada().columna)) {

									}
									else {
										elemento = aux;
										return true;
									}
								}
								start = aux1;
							}
						}
						else {
							for (int j = start->getCoordenada().columna; j > p->getCoordenada().columna; j--) {
								aux1 = start;
								start = elemento;
								if (elemento->movimientoLegal(i, j, select_pieza(i, j)) and comprobarPieza(i, j)) {
									elemento->setCoordenada(i, j);
									start = aux1;
									if (/*start->movimientoLegal(p->getCoordenada().fila, p->getCoordenada().columna, p) and */ comprobarPieza(p->getCoordenada().fila, p->getCoordenada().columna)) {

									}
									else {
										elemento = aux;
										return true;
									}
								}
								start = aux1;
							}
						}
					}
				}
			}
			elemento = aux;
		}
		return false;
	}
};