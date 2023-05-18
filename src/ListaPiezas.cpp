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
				coord.columna = 5;
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
				coord.columna = 4;
				PiezaGen* aux = new Rey(NEGRO, coord);
				agregar(aux); // agregar a la lista
			}
		}
	}
}

void ListaPiezas::destino(int fila, int columna) {
	std::cout << "casilla destino: " << fila << ";" << columna << std::endl;
	std::cout << turno_destino << std::endl;
	if (turno_destino) {
		if (destino(fila, columna, turno))
			turno = true;
		else
			turno = false;
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

bool ListaPiezas::destino(int fila, int columna, bool turno) {
	final = select_pieza(fila, columna);
	if ((start->movimientoLegal(fila, columna, final))) {
		if ((start->getTipo() == PEON) and (noAtraviesa(start, fila, columna) == true)) {
			start->setCoordenada(fila, columna);
		}
		if ((start->getTipo() != PEON)) {
			start->setCoordenada(fila, columna);
		}
		turno = not turno;	//Toogle para turno
	}
	return turno;
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

bool ListaPiezas::comprobarPeon(PiezaGen* pieza, int fila, int columna)
{
	Coordenada destino;
	destino.fila = fila;
	destino.columna = columna;
	bool flag = false;

	//Primero comprobamos el color del peon
	if (pieza->getColor() == BLANCO)
	{
		//Comprobacion para la captura en la diagonal derecha
		if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == 1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == 1)) {
			if (mirarCasilla(fila, columna)) return true;
			else return false;
		}
		//Comprobacion para la captura en la diagonal izquierda
		if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == -1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == 1)) {
			if (mirarCasilla(fila, columna)) return true;
			else return false;
		}

		//Colision en el movimiento hacia delante
		if (mirarCasilla(pieza->getCoordenada().getFila() + 1, pieza->getCoordenada().getColumna())) return false;

		//Movimiento de dos casillas hacia delante si el peon no se ha movido
		if ((pieza->getCoordenada().getFila()) == (2))
		{
			//Comprobamos si hay colisiones
			if (mirarCasilla(pieza->getCoordenada().getFila() + 2, pieza->getCoordenada().getColumna())) flag = true;
			if (mirarCasilla(pieza->getCoordenada().getFila() + 1, pieza->getCoordenada().getColumna())) return false;

			if (destino.getFila() == 3) return true;
			else if (flag) return false;
		}
		return true;
	}
	else {
		//El negro tiene el mismo esquema que el del peon blanco pero cambiando las comprobaciones para ajustarse a su naturaleza simétrica

		if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == -1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == -1)) {
			if (mirarCasilla(fila, columna)) return true;
			else return false;
		}
		if (((destino.getColumna() - pieza->getCoordenada().getColumna()) == 1) && ((destino.getFila() - pieza->getCoordenada().getFila()) == -1)) {
			if (mirarCasilla(fila, columna)) return true;
			else return false;
		}

		if (mirarCasilla(pieza->getCoordenada().getFila() - 1, pieza->getCoordenada().getColumna())) return false;

		if ((pieza->getCoordenada().getFila()) == (7))
		{
			if (mirarCasilla(pieza->getCoordenada().getFila() - 2, pieza->getCoordenada().getColumna())) flag = true;
			if (mirarCasilla(pieza->getCoordenada().getFila() - 1, pieza->getCoordenada().getColumna())) return false;

			if (destino.getFila() == 6) return true;

			else if (flag) return false;
		}
		flag = false;
		return true;
	}
}

bool ListaPiezas::mirarCasilla(int fila, int columna)
{
	//Devuelve true si hay una pieza en la casilla o false si no

	Coordenada casilla;
	casilla.fila = fila;
	casilla.columna = columna;

	for (int i = 0; i < numero; i++) {

		if (casilla == pieza[i]->getCoordenada()) {
			return true;
		}
	}
	return false;
}

bool ListaPiezas::comprobarPieza(PiezaGen* aux, int fila, int columna)
{
	//Para comprobar las colisiones, segun el tipo de pieza se invoca su funcion correspondiente
	//if (aux->getTipo() == ALFIL) return comprobarAlfil(aux, fila, columna);
	//else if (aux->getTipo() == TORRE) return comprobarTorre(aux, fila, columna);
	//else if (aux->getTipo() == REINA) return comprobarReina(aux, fila, columna);
	if (aux->getTipo() == PEON) return comprobarPeon(aux, fila, columna);
	//else if (aux->getTipo() == REY) return comprobarRey(aux, fila, columna);

}

bool ListaPiezas::noAtraviesa(PiezaGen* pieza1, int fila, int columna)
{
	Coordenada coordDestino;
	coordDestino.fila = fila;
	coordDestino.columna = columna;
	PiezaGen* piezaDestino;
	piezaDestino = select_pieza(fila, columna);

	//Buscamos la pieza en el array
	int index = -1;
	for (int i = 1; i <= numero; i++) {
		if (pieza[i] == pieza1) {
			index = i;
		}
	}
	if (index != -1) {
		//Comprobamos las posibles colisiones
		if (comprobarPeon(pieza[index], fila, columna)) {
			//Comprobamos si el movimiento provoca jaque
					
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void ListaPiezas::dibuja() {
	for (int i = 0; i < numero; i++)
		pieza[i]->dibuja();
}

bool ListaPiezas::getTurno(int fila, int columna, bool turno) {
	if (select_pieza(fila, columna) != NULL) {
		if((select_pieza(fila, columna)->getColor() == BLANCO and turno) or (select_pieza(fila, columna)->getColor() == NEGRO and not turno)) {
			std::cout << "Turno correcto!" << std::endl;
			return true;
		}
	}
	std::cout << "Turno incorrecto!" << std::endl;
	return false;
}

ListaPiezas::~ListaPiezas() {

}