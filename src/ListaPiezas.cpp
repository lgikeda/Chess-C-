#include "ListaPiezas.h"
#include<iostream>

ListaPiezas::ListaPiezas() {
	numero = 0;
	for (int i = 0; i < MAX_PIEZAS; i++)
		pieza[i] = 0;
}

bool ListaPiezas::agregar(PiezaGen* p) {
	if (numero < MAX_PIEZAS)
		pieza[numero++] = p; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaPiezas::inicializa() {

	int i;
	Coordenada coord;
	for (i = 1; i < 17; i++) {
		if (i >= 1 and i < 9)
		{
			coord.fila = 2;
			coord.columna = i;
			PiezaGen* aux = new Peon(BLANCO, coord);
			agregar(aux); // agregar a la lista
		}
		if (i >= 9 and i < 17)
		{
			coord.fila = 7;
			coord.columna = i - 8;
			PiezaGen* aux = new Peon(NEGRO, coord);
			agregar(aux); // agregar a la lista
		}
	}
	for (i = 17; i < 21; i++) {
		if (i >= 17 and i < 19) {
			coord.fila = 1;
			if (i == 17)
				coord.columna = 2;
			if (i == 18)
				coord.columna = 7;
			PiezaGen* aux = new Caballo(BLANCO, coord);
			agregar(aux); // agregar a la lista
		}
		if (i >= 19 and i < 21)
		{
			coord.fila = 8;
			if (i == 19)
				coord.columna = 2;
			if (i == 20)
				coord.columna = 7;
			PiezaGen* aux = new Caballo(NEGRO, coord);
			agregar(aux); // agregar a la lista
		}
	}
	for (i = 21; i < 25; i++) {
		if (i >= 21 and i < 23) {
			coord.fila = 1;
			if (i == 21)
				coord.columna = 1;
			if (i == 22)
				coord.columna = 8;
			PiezaGen* aux = new Torre(BLANCO, coord);
			agregar(aux); // agregar a la lista
		}
		if (i >= 23 and i < 25) {

			coord.fila = 8;
			if (i == 23)
				coord.columna = 1;
			if (i == 24)
				coord.columna = 8;
			PiezaGen* aux = new Torre(NEGRO, coord);
			agregar(aux); // agregar a la lista
		}
	}
	for (i = 25; i < 29; i++) {
		if (i >= 25 and i < 27) {

			coord.fila = 1;
			if (i == 25)
				coord.columna = 3;
			if (i == 26)
				coord.columna = 6;
			PiezaGen* aux = new Alfil(BLANCO, coord);
			agregar(aux); // agregar a la lista
		}
		if (i >= 27 and i < 29) {

			coord.fila = 8;
			if (i == 27)
				coord.columna = 3;
			if (i == 28)
				coord.columna = 6;
			PiezaGen* aux = new Alfil(NEGRO, coord);
			agregar(aux); // agregar a la lista
		}
	}
	for (i = 29; i < 33; i++) {

		if (i >= 29 and i < 31) {
			if (i == 29)
			{
				coord.fila = 1;
				coord.columna = 5;
				PiezaGen* aux = new Reina(BLANCO, coord);
				agregar(aux); // agregar a la lista
			}
			if (i == 30)
			{
				coord.fila = 8;
				coord.columna = 4;
				PiezaGen* aux = new Reina(NEGRO, coord);
				agregar(aux); // agregar a la lista
			}
		}
		if (i >= 31 and i < 33)
		{
			if (i == 31)
			{
				coord.fila = 1;
				coord.columna = 4;
				PiezaGen* aux = new Rey(BLANCO, coord);
				agregar(aux); // agregar a la lista
			}
			if (i == 32)
			{
				coord.fila = 8;
				coord.columna = 5;
				PiezaGen* aux = new Rey(NEGRO, coord);
				agregar(aux); // agregar a la lista
			}
		}
	}
}

void ListaPiezas::destino(int fila, int columna) {

	PiezaGen* aux1 = start;
	
	std::cout << "casilla destino: " << fila << ";" << columna << std::endl;
	std::cout << turno_destino << std::endl;
	final = select_pieza(fila, columna);
	if (turno_destino and (start != NULL)) {
		Coordenada ultimaPosicion = start->getCoordenada();
		//if (/*(e_jaque == false) and*/ (final != NULL)) {
		//	if (enroque(fila, columna)) {
		//		turno = not turno;
		//	}
		//}
		//else if ((start->movimientoLegal(fila, columna, final)) and (comprobarPieza(fila, columna))) {

		//		start->setCoordenada(fila, columna);
		//		if (jaque(start, final)) {
		//		std::cout << "////////////////////////////////////            JAQUE!            /////////////////////////////////" << std::endl;
		//		e_jaque = true;
		//		}
		//		else
		//			e_jaque = false;
		//		if ((final != NULL) and (posicionIgual(start, final))) {
		//			eliminar(final);
		//		}
		//		turno = not turno;
		//}
		if ((e_jaque == false) and (final != NULL) and (start->getColor() == final->getColor())) {
			if (enroque(fila, columna)) {
				turno = not turno;
			}
		}
		else if ((start->movimientoLegal(fila, columna, final)) and (comprobarPieza(fila, columna)) and ((final == NULL) or (start->getColor() != final->getColor()))) {

			start->setCoordenada(fila, columna);
			if (permisoAlJaque(start)) {
				start = aux1;
				start->setCoordenada(ultimaPosicion.fila, ultimaPosicion.columna);
				turno = not turno;
			}
			else {
				start = aux1;
				//start->setCoordenada(fila, columna);
			}
			if (jaque(start, final)) {
				std::cout << "////////////////////////////////////            JAQUE!            /////////////////////////////////" << std::endl;
				e_jaque = true;
			}
			else
				e_jaque = false;
			if ((final != NULL) and (posicionIgual(start, final))) {
				eliminar(final);
			}
			turno = not turno;
		}
	}
	turno_destino = false;
}

PiezaGen* ListaPiezas::select_pieza(int fil, int col) {
	for (int i = 0; i < numero; i++)
	{
		if (pieza[i]->getPos_x() == fil and pieza[i]->getPos_y() == col) {
			return pieza[i];
		}
	}
	std::cout << "no se encontro objeto en : " << fil << ";" << col << std::endl;
	return NULL;
}

void ListaPiezas::mueve(int fila, int columna) {

	if (getTurno(fila, columna, turno)) {
		if (select_pieza(fila, columna) != NULL) {
			start = select_pieza(fila, columna);
			std::cout << "//////////Objeto seleccionado///////////" << std::endl;
			turno_destino = true;
		}
	}
	else turno_destino = false;
}

void ListaPiezas::eliminar(PiezaGen* eliminada) {
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

bool ListaPiezas::enroque(int fila, int columna)
{
	bool enr = false;

	int contador = 0;

	if (start->getColor() == final->getColor()) {
		if (((start->getTipo() == REY) and (final->getTipo() == TORRE))/* or ((start->getTipo() == TORRE) and (final->getTipo() == REY))*/) {
			if ((start->getMovimiento()) and (final->getMovimiento())) {
				if (start->getCoordenada().columna < final->getCoordenada().columna) {
					if (start->getColor() == BLANCO) {
						if ((mirarCasilla(start, fila, columna))) {
							start->setCoordenada(1, 6);
							final->setCoordenada(1, 5);
							enr = true;
						}
					}
					if (start->getColor() == NEGRO) {
						if ((mirarCasilla(start, fila, columna))) {
							start->setCoordenada(8, 7);
							final->setCoordenada(8, 6);
							enr = true;
						}
					}	
				}
				else if (start->getCoordenada().columna > final->getCoordenada().columna) {
					if (start->getColor() == BLANCO) {
						if ((mirarCasilla(start, fila, columna))) {
							start->setCoordenada(1, 2);
							final->setCoordenada(1, 3);
							enr = true;
						}
					}
					if (start->getColor() == NEGRO) {
						if ((mirarCasilla(start, fila, columna))) {
							start->setCoordenada(8, 3);
							final->setCoordenada(8, 4);
							enr = true;
						}
					}
				}
			}
		}
		else if (((start->getTipo() == TORRE) and (final->getTipo() == REY))/* or ((start->getTipo() == TORRE) and (final->getTipo() == REY))*/) {
			if ((start->getMovimiento()) and (final->getMovimiento())) {
				if (start->getCoordenada().columna < final->getCoordenada().columna) {
					if (start->getColor() == BLANCO) {
						if ((mirarCasilla(start, fila, columna))) {
							start->setCoordenada(1, 3);
							final->setCoordenada(1, 2);
							enr = true;
						}
					}
					if (start->getColor() == NEGRO) {
						if ((mirarCasilla(start, fila, columna))) {
							start->setCoordenada(8, 4);
							final->setCoordenada(8, 3);
							enr = true;
						}
					}
				}
				else if (start->getCoordenada().columna > final->getCoordenada().columna) {
					if (start->getColor() == BLANCO) {
						if ((mirarCasilla(start, fila, columna))) {
							start->setCoordenada(1, 5);
							final->setCoordenada(1, 6);
							enr = true;
						}
					}
					if (start->getColor() == NEGRO) {
						if ((mirarCasilla(start, fila, columna))) {
							start->setCoordenada(8, 6);
							final->setCoordenada(8, 7);
							enr = true;
						}
					}
				}
			}
		}
	}
	return enr;
}

bool ListaPiezas::comprobarRey(int fila, int columna)
{
	Coordenada destino;
	destino.fila = fila;
	destino.columna = columna;
	Coordenada inicio;
	inicio.fila = start->getCoordenada().getFila();
	inicio.columna = start->getCoordenada().getColumna();
	int index = -1;

	//Buscamos al rey enemigo
	for (int i = 0; i < numero; i++) {
		if ((pieza[i]->getTipo() == REY) && (pieza[i]->getColor() != start->getColor())) {
			index = i;
		}
	}
	//Guardamos su coordenada
	Coordenada reyEnemigo = pieza[index]->getCoordenada();

	//Comprobamos si hay una colision
	if (mirarCasilla(start, fila, columna) and (start->getColor() == final->getColor())) {
		//Si hay una pieza pero es de distinto color permitimos el movimiento
		//if (buscarPieza(fila, columna)->getColor() != pieza->getColor()) return true;
		return false;
	}
	else {
		//Miramos las casillas del rey enemigo una a una
		for (int i = reyEnemigo.getFila() + 1; i >= reyEnemigo.getFila() - 1; i--) {
			for (int j = reyEnemigo.getColumna() - 1; j <= reyEnemigo.getColumna() + 1; j++) {
				Coordenada aux;
				aux.fila = i;
				aux.columna = j;
				//Si alguna casilla del movimiento del rey enemigo coincide con una del rey que llama a la funcion se ilegaliza el movimiento
				if (destino == aux) return false;
			}
		}
	}
}

bool ListaPiezas::comprobarReina(int fila, int columna)
{
	Coordenada destino;
	destino.fila = fila;
	destino.columna = columna;
	Coordenada resta = destino - start->getCoordenada();

	//Para comprobar la reina comprobamos utilizamos el comprobar alfil y comprobar torre segun que movimiento sea
	//Diagonal
	if (abs(destino.getColumna() - start->getCoordenada().getColumna()) == abs(destino.getFila() - start->getCoordenada().getFila())) {
		return comprobarAlfil(fila, columna);
	}

	//Mismma fila
	if (start->getCoordenada().getFila() == destino.getFila()) {
		return comprobarTorre(fila, columna);
	}

	//Misma columna
	if (start->getCoordenada().getColumna() == destino.getColumna()) {
		return comprobarTorre(fila, columna);
	}

	return true;

}

bool ListaPiezas::comprobarAlfil(int fila, int columna)
{
	Coordenada destino;
	destino.fila = fila;
	destino.columna = columna;
	Coordenada restaDrcha = destino - start->getCoordenada();
	Coordenada restaIzq = start->getCoordenada() - destino;

	int j = 0;
	int i = 0;
	int s = 0;
	int l = 0;
	// Comprobamos las colisiones en la diagonal arriba derecha
	if (((restaDrcha.getColumna() >= 0) && (restaDrcha.getFila()) > 0)) {
		for (i = start->getCoordenada().getFila() + 1, j = start->getCoordenada().getColumna() + 1; (i < destino.getFila()), (j < destino.getColumna()); i++, j++) {
			if (mirarCasilla(start, i, j)) {
				return false;
			}
		}
	}
	// Comprobamos las colisiones en la diagonal abajo izquierda
	if (((restaIzq.getColumna() >= 0) && (restaIzq.getFila()) > 0)) {
		for (s = start->getCoordenada().getFila() - 1, l = start->getCoordenada().getColumna() - 1; (s > destino.getFila()), (l > destino.getColumna()); s--, l--) {
			if (mirarCasilla(start, s, l)) {
				return false;
			}
		}
	}
	// Comprobamos las colisiones en la diagonal arriba izq
	if (((restaIzq.getColumna() >= 0) && (restaDrcha.getFila()) > 0)) {
		for (i = start->getCoordenada().getFila() + 1, j = start->getCoordenada().getColumna() - 1; (i < destino.getFila()), (j > destino.getColumna()); i++, j--) {
			if (mirarCasilla(start, i, j)) {
				return false;
			}
		}
	}
	// Comprobamos las colisiones en la diagonal abajo derecha
	if (((restaDrcha.getColumna() >= 0) && (restaIzq.getFila()) > 0)) {
		for (s = start->getCoordenada().getFila() - 1, l = start->getCoordenada().getColumna() + 1; (s > destino.getFila()), (l < destino.getColumna()); s--, l++) {
			if (mirarCasilla(start, s, l)) {
				return false;
			}
		}
	}
	return true;
}

bool ListaPiezas::comprobarTorre(int fila, int columna)
{
	int ib = 0;
	int pd = 0;
	int fd = 0;
	int px = 0;

	Coordenada coordInicio = start->getCoordenada();
	Coordenada destino;
	destino.fila = fila;
	destino.columna = columna;
	//Comprobamos las colisiones hacia arriba en la misma columna
	if (destino.getFila() - coordInicio.getFila() >= 0) {
		for (ib = coordInicio.getFila() + 1; ib < destino.getFila(); ib++) {
			if (mirarCasilla(start, ib, coordInicio.getColumna())) {
				return false;
			}
		}
	}
	//Comprobamos las colisiones hacia la derecha en la misma fila
	if (destino.getColumna() - coordInicio.getColumna() >= 0) {
		for (pd = coordInicio.getColumna() + 1; pd < destino.getColumna(); pd++) {
			if (mirarCasilla(start, coordInicio.getFila(), pd)) {
				return false;
			}
		}
	}
	//Comprobamos las colisiones hacia la izquierda en la misma fila
	if (coordInicio.getColumna() - destino.getColumna() >= 0) {
		for (fd = coordInicio.getColumna() - 1; fd > destino.getColumna(); fd--) {
			if (mirarCasilla(start, coordInicio.getFila(), fd)) {
				return false;
			}
		}
	}
	//Comprobamos las colisiones hacia abajo en la misma columna
	if (coordInicio.getFila() - destino.getFila() >= 0) {
		for (px = coordInicio.getFila() - 1; px > destino.getFila(); px--) {
			if (mirarCasilla(start, px, coordInicio.getColumna())) {
				return false;
			}
		}
	}

	return true;
}

bool ListaPiezas::comprobarPeon(int fila, int columna)
{

	bool flag = false;

	//Miramos de qué color es el peon
	if (start->getColor() == BLANCO)
	{
		
		//Colision en el movimiento hacia delante
		if (mirarCasilla(start, start->getCoordenada().fila + 1, start->getCoordenada().columna)) return false;

		//Movimiento de dos casillas hacia delante si el peon no se ha movido
		if ((start->getCoordenada().fila) == (2))
		{
			//Comprobamos si hay colisiones
			if (mirarCasilla(start, start->getCoordenada().fila + 2, start->getCoordenada().columna)) flag = true;
			if (mirarCasilla(start, start->getCoordenada().fila + 1, start->getCoordenada().columna)) return false;
			if (fila == 3) return true;
			else if (flag) return false;
		}
		return true;
	}
	else {
		//El negro tiene el mismo esquema que el del peon blanco pero cambiando las comprobaciones para ajustarse a su naturaleza simétrica

		if (mirarCasilla(start, start->getCoordenada().fila - 1, start->getCoordenada().columna)) return false;

		if ((start->getCoordenada().fila) == (7))
		{
			if (mirarCasilla(start, start->getCoordenada().fila - 2, start->getCoordenada().columna)) flag = true;
			if (mirarCasilla(start, start->getCoordenada().fila - 1, start->getCoordenada().columna)) return false;

			if (fila == 6) return true;

			else if (flag) return false;
		}
		flag = false;
		return true;
	}
}

bool ListaPiezas::mirarCasilla(PiezaGen* start, int fila, int columna)
{
	//Devuelve true si hay una pieza en la casilla o false si no
	Coordenada casilla;
	casilla.fila = fila;
	casilla.columna = columna;
	//En este caso, la variable "true" indica que no puede moverse la pieza a la casilla asignada
	for (int i = 0; i < numero; i++) {

		if ((casilla == pieza[i]->getCoordenada()) and (start->getColor() == pieza[i]->getColor())) {
			return true;
		}
		if ((casilla == pieza[i]->getCoordenada()) and (start->getColor() != pieza[i]->getColor()) and (start->movimientoLegal(fila, columna, start))) {
			return true;
		}
	}
	return false;
}

bool ListaPiezas::comprobarPieza(int fila, int columna)
{
	//Para comprobar las colisiones, segun el tipo de pieza se invoca su funcion correspondiente
	if (start->getTipo() == REY) return comprobarRey(fila, columna);
	else if (start->getTipo() == REINA) return comprobarReina(fila, columna);
	else if (start->getTipo() == ALFIL) return comprobarAlfil(fila, columna);
	else if (start->getTipo() == TORRE) return comprobarTorre(fila, columna);
	else if (start->getTipo() == CABALLO) return true;
	else if (start->getTipo() == PEON) return comprobarPeon(fila, columna);
	return false;
}

void ListaPiezas::dibuja() {
	for (int i = 0; i < numero; i++)
		pieza[i]->dibuja();
}

bool ListaPiezas::getTurno(int fila, int columna, bool turno) {
	if (select_pieza(fila, columna) != NULL) {
		if ((select_pieza(fila, columna)->getColor() == BLANCO and turno) or (select_pieza(fila, columna)->getColor() == NEGRO and not turno)) {
			std::cout << "Turno correcto!" << std::endl;
			return true;
		}
	}
	std::cout << "Turno incorrecto!" << std::endl;
	return false;
}

//bool ListaPiezas::jaque(PiezaGen* rey) {
//
//	//for (int i = 1; i <= numero; i++) {
//	//	if (pieza[i]->getTipo() != REY) {
//	//		if (pieza[i]->getColor() != rey->getColor()) {
//
//	//			/*if (pieza[i]->getTipo() == CABALLO) {
//	//				if ((pieza[i]->getCoordenada().fila == rey->getCoordenada().fila + 2) and (pieza[i]->getCoordenada().columna == rey->getCoordenada().columna + 1)) {
//	//					return true;
//	//				}
//	//				if ((pieza[i]->getCoordenada().fila == rey->getCoordenada().fila + 2) and (pieza[i]->getCoordenada().columna == rey->getCoordenada().columna - 1)) {
//	//					return true;
//	//				}
//	//				if ((pieza[i]->getCoordenada().fila == rey->getCoordenada().fila - 2) and (pieza[i]->getCoordenada().columna == rey->getCoordenada().columna + 1)) {
//	//					return true;
//	//				}
//	//				if ((pieza[i]->getCoordenada().fila == rey->getCoordenada().fila - 2) and (pieza[i]->getCoordenada().columna == rey->getCoordenada().columna - 1)) {
//	//					return true;
//	//				}
//	//				if ((pieza[i]->getCoordenada().fila == rey->getCoordenada().fila + 1) and (pieza[i]->getCoordenada().columna == rey->getCoordenada().columna + 2)) {
//	//					return true;
//	//				}
//	//				if ((pieza[i]->getCoordenada().fila == rey->getCoordenada().fila + 1) and (pieza[i]->getCoordenada().columna == rey->getCoordenada().columna - 2)) {
//	//					return true;
//	//				}
//	//				if ((pieza[i]->getCoordenada().fila == rey->getCoordenada().fila - 1) and (pieza[i]->getCoordenada().columna == rey->getCoordenada().columna + 2)) {
//	//					return true;
//	//				}
//	//				if ((pieza[i]->getCoordenada().fila == rey->getCoordenada().fila - 1) and (pieza[i]->getCoordenada().columna == rey->getCoordenada().columna - 2)) {
//	//					return true;
//	//				}
//	//return false;
//}

bool ListaPiezas::jaque(PiezaGen* s, PiezaGen* f) {	//
	PiezaGen* aux[2] = {};
	int k = 0;
	for (int i = 0; i < numero; i++) {
		if (pieza[i]->getTipo() == REY) {
			aux[k] = pieza[i];
			k++;
		}
	}
	for (int i = 0; i < 2; i++) {
		if (s->movimientoLegal(aux[i]->getCoordenada().fila, aux[i]->getCoordenada().columna, aux[i])) {
			if (/*(aux[i]->getTipo() == REY) and*/ (s->getColor() != aux[i]->getColor())) {
				if (trayecto(s, aux[i])) return true;
			}
		}
	}
	return false;
}

bool ListaPiezas::trayecto(PiezaGen* s, PiezaGen* f) {
	if (s->getCoordenada().fila <= f->getCoordenada().fila) {
		for (int i = s->getCoordenada().fila; i <= f->getCoordenada().fila; i++) {
			if (s->getCoordenada().columna >= f->getCoordenada().columna) {
				for (int j = s->getCoordenada().columna; j >= f->getCoordenada().columna; j--) {
					if (s->movimientoLegal(i, j, f) and comprobarPieza( f->getCoordenada().fila, f->getCoordenada().columna)) {
						return true;
					}
					else {
						std::cout << "no se entro en el if" << std::endl;
					}
				}
			}
			else if (s->getCoordenada().columna < f->getCoordenada().columna) {
				for (int j = s->getCoordenada().columna; j <= f->getCoordenada().columna; j++) {
					if (s->movimientoLegal(i, j, f) and comprobarPieza( f->getCoordenada().fila, f->getCoordenada().columna)) {
						return true;
					}
					else {
						std::cout << "no se entro en el if" << std::endl;
					}
				}
			}
		}
	}
	else if (s->getCoordenada().fila >= f->getCoordenada().fila) {
		for (int i = s->getCoordenada().fila; i >= f->getCoordenada().fila; i--) {
			if (s->getCoordenada().columna >= f->getCoordenada().columna) {
				for (int j = s->getCoordenada().columna; j >= f->getCoordenada().columna; j--) {
					if (s->movimientoLegal(i, j, f) and comprobarPieza( f->getCoordenada().fila, f->getCoordenada().columna)) {
						return true;
					}
					else {
						std::cout << "no se entro en el if" << std::endl;
					}
				}
			}
			else if (s->getCoordenada().columna < f->getCoordenada().columna) {
				for (int j = s->getCoordenada().columna; j <= f->getCoordenada().columna; j++) {
					if (s->movimientoLegal(i, j, f) and comprobarPieza( f->getCoordenada().fila, f->getCoordenada().columna)) {
						return true;
					}
					else {
						std::cout << "no se entro en el if" << std::endl;
					}
				}
			}
		}
	}
	return false;
}

ListaPiezas::~ListaPiezas() {

}