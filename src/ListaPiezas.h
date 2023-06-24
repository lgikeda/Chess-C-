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
	int piezaEliminada = 0;
	bool condicionPromocion = false;	//Esta variable hace que solo salte una vez el menu de promocion de piezas

	int tipoAjedrez;

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
	void setTipoAjedrez(int tipo);

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
		Coordenada rey;
		PiezaGen* ini = NULL;
		int r = 0;
		ini = start;
		for (int i = 0; i < numero; i++) {
			if ((pieza[i]->getTipo() == REY) and (pieza[i]->getColor() != start->getColor())) {
				aux = pieza[i];
				r = i;
			}
		}
		rey.fila=aux->getCoordenada().fila;
		rey.columna=aux->getCoordenada().columna;

		if ((not movRey(aux)) /* and (not proteccionRey(aux))*/) {
			pieza[r]->setCoordenada(rey.fila,rey.columna);
			start = ini;
			return true;
		}
		else {
			pieza[r]->setCoordenada(rey.fila, rey.columna);
			start = ini;
			return false;
		}
	}

	bool movRey(PiezaGen* pr) {
		PiezaGen* p = pr;
		int cont = 0;
		int fila = p->getCoordenada().fila;
		int columna = p->getCoordenada().columna;
		for (int i = fila - 1; i <= fila + 1; i++) {
			for (int j = columna - 1; j <= columna + 1; j++) {
				//COMPROBACION DE PERMANECER DENTRO DEL TABLERO Y CASILLA VACIA
				if ((j > 0) and (j < 9) and (i > 0) and (i < 9) and (select_pieza(i, j) == NULL)) {
					p->setCoordenada(i,j);
					//ITERACION DE RECORRIDO PARA CADA PIEZA HACIA LA NUEVA POSICION DEL REY
					for (int k = 0; k < numero; k++) {
						if ((pieza[k]->getColor() != p->getColor()) and pieza[k]->getTipo() != REY) {
							start = pieza[k];
							if ((pieza[k]->movimientoLegal(i, j, p)) and comprobarPieza(i, j)) {
								cont = 0;
								break;
							}
							else cont++;
						}
					}
					if (cont != 0) return true;
				}
			}
		}
		return false;
	}

	//bool proteccionRey(PiezaGen* p) {
	//
	//	for (auto& elemento : pieza) {
	//	
	//		
	//	}
	//}


	bool proteccionRey1(PiezaGen* p) {
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
										std::cout << "POSIBLE PROTECCION!" << std::endl;
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
										std::cout << "POSIBLE PROTECCION!" << std::endl;
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
										std::cout << "POSIBLE PROTECCION!" << std::endl;
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
										std::cout << "POSIBLE PROTECCION!" << std::endl;
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