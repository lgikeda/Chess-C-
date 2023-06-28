#include "ListaPiezas.h"
#include "Interfaz.h"
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

void ListaPiezas::setTipoPromocion(int tipo) {
	this->tipoPromocion = tipo;
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
				coord.columna = 4;
				PiezaGen* aux = new Dama(BLANCO, coord);
				agregar(aux); // agregar a la lista
			}
			if (i == 30)
			{
				coord.fila = 8;
				coord.columna = 4;
				PiezaGen* aux = new Dama(NEGRO, coord);
				agregar(aux); // agregar a la lista
			}
		}
		if (i >= 31 and i < 33)
		{
			if (i == 31)
			{
				coord.fila = 1;
				coord.columna = 5;
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

	bool PeonBlancoEnFila8 = false;
	bool PeonNegroEnFila1 = false;

	Color colorPiezaEliminada;

	//setTipoAjedrez(tipoAjedrez);
	
	std::cout << "casilla destino: " << fila << ";" << columna << std::endl;
	std::cout << turno_destino << std::endl;
	final = select_pieza(fila, columna);
	
	if (turno_destino and (start != NULL)) {
		Coordenada ultimaPosicion = start->getCoordenada();
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
			}
			if (jaque(start, final)) {
				if (start->getColor() == BLANCO) {
					std::cout << "////////////////////////////////////            JAQUE AL REY NEGRO!            /////////////////////////////////" << std::endl;
					if (jaqueMate()) {
						Interfaz::cambiaEstado("JAQUE MATE AL REY NEGRO");
					}else 
						Interfaz::cambiaEstado("JAQUE AL REY NEGRO");
				}
				else {
					std::cout << "////////////////////////////////////            JAQUE AL REY BLANCO!            /////////////////////////////////" << std::endl;
					if (jaqueMate()) {
						Interfaz::cambiaEstado("JAQUE MATE AL REY BLANCO");
					}else
						Interfaz::cambiaEstado("JAQUE AL REY BLANCO");
				}
				e_jaque = true;
			}
			
			else
				e_jaque = false;

			if ((final != NULL) and (posicionIgual(start, final))) {
				eliminar(final);
				if (start->getTipoAjedrez() == 1)
					ETSIDI::play("sonidos/espadazo.wav");
			}
			turno = not turno;
		}
	}

	for (int i = 0; i < numero; i++) {
		if ((pieza[i]->getTipo() == PEON) and (pieza[i]->getColor() == BLANCO) and (pieza[i]->getCoordenada().fila == 8) and (tipoPromocion == 0)) {
			
			Interfaz::cambiaEstado("PROMOCION BLANCA");

			CoordProm.fila = pieza[i]->getCoordenada().fila;
			CoordProm.columna = pieza[i]->getCoordenada().columna;

			piezaEliminada = i;

			break;
		}
		else if ((pieza[i]->getTipo() == PEON) and (pieza[i]->getColor() == NEGRO) and (pieza[i]->getCoordenada().fila == 1) and (tipoPromocion == 0)) {
			Interfaz::cambiaEstado("PROMOCION NEGRA");

			CoordProm.fila = pieza[i]->getCoordenada().fila;
			CoordProm.columna = pieza[i]->getCoordenada().columna;

			piezaEliminada = i;
			
			break;
		}
	}
	if (tipoPromocion != 0) {

		bool permiso = true;		//Comprueba si han comido a la pieza que se esta promocionando

		for (int i = 0; i < numero; i++) {
			if ((pieza[i]->getTipo() != PEON) and (pieza[i]->getCoordenada().fila == CoordProm.fila) and (pieza[i]->getCoordenada().columna == CoordProm.columna)) {
				permiso = false;
			}
		}
		if (permiso == true) {

			colorPiezaEliminada = pieza[piezaEliminada]->getColor();

			eliminar(pieza[piezaEliminada]);		//Elimina la pieza que ha llegado a la fila de promocion para poder generar otra del tipo seleccionado

			if (colorPiezaEliminada == BLANCO) {

				if (tipoPromocion == 1) {
					pieza[numero] = new Alfil(BLANCO, CoordProm);
				}
				else if (tipoPromocion == 2) {
					pieza[numero] = new Caballo(BLANCO, CoordProm);
				}
				else if (tipoPromocion == 3) {
					pieza[numero] = new Dama(BLANCO, CoordProm);
				}
				else if (tipoPromocion == 4) {
					pieza[numero] = new Torre(BLANCO, CoordProm);
				}
			}

			else if (colorPiezaEliminada == NEGRO) {

				if (tipoPromocion == 1) {
					pieza[numero] = new Alfil(NEGRO, CoordProm);
				}
				else if (tipoPromocion == 2) {
					pieza[numero] = new Caballo(NEGRO, CoordProm);
				}
				else if (tipoPromocion == 3) {
					pieza[numero] = new Dama(NEGRO, CoordProm);
				}
				else if (tipoPromocion == 4) {
					pieza[numero] = new Torre(NEGRO, CoordProm);
				}
			}
		}

		pieza[numero++]->dibuja();
		tipoPromocion = 0;
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
	pieza[numero - 1] = nullptr;
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

	//Comprobamos si hay una colision
	if (mirarCasilla(start, fila, columna) and (start->getColor() == final->getColor())) {
		//Si hay una pieza pero es de distinto color permitimos el movimiento
		//if (buscarPieza(fila, columna)->getColor() != pieza->getColor()) return true;
		return false;
	}
}

bool ListaPiezas::comprobarDama(int fila, int columna)
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
	else if (start->getTipo() == DAMA) return comprobarDama(fila, columna);
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

void ListaPiezas::setTipoAjedrez(int tipo) {
	
	inicializa();
	tipoAjedrez = tipo;
	for (int i = 0; i < numero; i++) {
		pieza[i]->setTipoAjedrez(tipo);
	}
	
}

bool ListaPiezas::permisoAlJaque(PiezaGen* s) {
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
				}
				else return true;
			}
		}
	}
	std::cout << "Movimiento no permitido por poner en jaque al rey." << std::endl;
	return false;
}

bool ListaPiezas::jaqueMate() {
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
	rey.fila = aux->getCoordenada().fila;
	rey.columna = aux->getCoordenada().columna;

	if ((not movRey(aux)) /* and (not proteccionRey(aux))*/) {
		aux->setCoordenada(rey.fila, rey.columna);
		pieza[r]->setCoordenada(rey.fila, rey.columna);
		start = ini;
		if (not proteccionRey(aux)) return true;
		else return false;
	}
	else {
		pieza[r]->setCoordenada(rey.fila, rey.columna);
		start = ini;
		return false;
	}
}

bool ListaPiezas::movRey(PiezaGen* pr) {
	PiezaGen* p = pr;
	int cont = 0;
	int fila = p->getCoordenada().fila;
	int columna = p->getCoordenada().columna;
	for (int i = fila - 1; i <= fila + 1; i++) {
		for (int j = columna - 1; j <= columna + 1; j++) {
			//COMPROBACION DE PERMANECER DENTRO DEL TABLERO Y CASILLA VACIA
			if ((j > 0) and (j < 9) and (i > 0) and (i < 9) and (select_pieza(i, j) == NULL)) {
				p->setCoordenada(i, j);
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

bool ListaPiezas::proteccionRey(PiezaGen* p) {
	PiezaGen* aux = start;
	Coordenada iniStart = start->getCoordenada();
	Color colorRey = p->getColor();
	Tipo tipoRey = p->getTipo();
	Coordenada posRey = p->getCoordenada();
	Coordenada posRival = start->getCoordenada();
	Coordenada c;
	//tipo jaque
	int tipoJaque = 0;
	std::vector<Coordenada> posicionesProteccion;
	if (abs(posRival.fila - posRey.fila) == abs(posRival.columna - posRey.columna)) tipoJaque = 0;	//Jaque diagonal
	else if (posRival.fila == posRey.fila) tipoJaque = 1;	//Jaque horizontal
	else if (posRival.columna == posRey.columna) tipoJaque = 2;	//Jaque vertical

	if (posRival.fila <= posRey.fila) {
		for (int i = posRival.fila; i <= posRey.fila; i++) {
			if (posRival.columna <= posRey.columna) {
				for (int j = posRival.columna; j <= posRey.columna; j++) {
					if ((j > 0) and (j < 9) and (i > 0) and (i < 9)) {
						if ((posRival.fila != i) or (posRival.columna != j)) {
							if (select_pieza(i, j) == NULL) {
								//Comprobacion de movimiento posible
								if (start->movimientoLegal(i, j, select_pieza(i, j)) and comprobarPieza(i, j)) {
									if (start->getTipo() != DAMA) {
										start->setCoordenada(i, j);
										//Comprobacion de movimiento de nueva posicion hacia el rey
										if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
											c.fila = i;
											c.columna = j;
											posicionesProteccion.push_back(c);
										}
									}
									else {
										switch (tipoJaque) {
										case 0:
											if (abs(i - posRey.fila) == abs(j - posRey.columna)) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										case 1:
											if (i == posRey.fila) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										case 2:
											if (j == posRey.columna) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										}
									}
								}
							}
						}
						else if ((posRival.fila == i) or (posRival.columna == j)) {
							c.fila = i;
							c.columna = j;
							posicionesProteccion.push_back(c);
						}
					}
				}
			}
			else {
				for (int j = posRival.columna; j >= posRey.columna; j--) {
					if ((j > 0) and (j < 9) and (i > 0) and (i < 9)) {
						if ((posRival.fila != i) or (posRival.columna != j)) {
							if (select_pieza(i, j) == NULL) {
								//Comprobacion de movimiento posible
								if (start->movimientoLegal(i, j, select_pieza(i, j)) and comprobarPieza(i, j)) {
									if (start->getTipo() != DAMA) {
										start->setCoordenada(i, j);
										//Comprobacion de movimiento de nueva posicion hacia el rey
										if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
											c.fila = i;
											c.columna = j;
											posicionesProteccion.push_back(c);
										}
									}
									else {
										switch (tipoJaque) {
										case 0:
											if (abs(i - posRey.fila) == abs(j - posRey.columna)) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										case 1:
											if (i == posRey.fila) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										case 2:
											if (j == posRey.columna) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										}
									}
								}
							}
						}
						else if ((posRival.fila == i) or (posRival.columna == j)) {
							c.fila = i;
							c.columna = j;
							posicionesProteccion.push_back(c);
						}
					}
				}
			}
		}
	}
	else {
		for (int i = posRival.fila; i >= posRey.fila; i--) {
			if (posRival.columna <= posRey.columna) {
				for (int j = posRival.columna; j <= posRey.columna; j++) {
					if ((j > 0) and (j < 9) and (i > 0) and (i < 9)) {
						if ((posRival.fila != i) or (posRival.columna != j)) {
							if (select_pieza(i, j) == NULL) {
								//Comprobacion de movimiento posible
								if (start->movimientoLegal(i, j, select_pieza(i, j)) and comprobarPieza(i, j)) {
									if (start->getTipo() != DAMA) {
										start->setCoordenada(i, j);
										//Comprobacion de movimiento de nueva posicion hacia el rey
										if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
											c.fila = i;
											c.columna = j;
											posicionesProteccion.push_back(c);
										}
									}
									else {
										switch (tipoJaque) {
										case 0:
											if (abs(i - posRey.fila) == abs(j - posRey.columna)) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										case 1:
											if (i == posRey.fila) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										case 2:
											if (j == posRey.columna) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										}

									}
								}
							}
						}
						else if ((posRival.fila == i) or (posRival.columna == j)) {
							c.fila = i;
							c.columna = j;
							posicionesProteccion.push_back(c);
						}
					}
				}
			}
			else {
				for (int j = posRival.columna; j >= posRey.columna; j--) {
					if ((j > 0) and (j < 9) and (i > 0) and (i < 9)) {
						if ((posRival.fila != i) or (posRival.columna != j)) {
							if (select_pieza(i, j) == NULL) {
								//Comprobacion de movimiento posible
								if (start->movimientoLegal(i, j, select_pieza(i, j)) and comprobarPieza(i, j)) {
									if (start->getTipo() != DAMA) {
										start->setCoordenada(i, j);
										//Comprobacion de movimiento de nueva posicion hacia el rey
										if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
											c.fila = i;
											c.columna = j;
											posicionesProteccion.push_back(c);
										}
									}
									else {
										switch (tipoJaque) {
										case 0:
											if (abs(i - posRey.fila) == abs(j - posRey.columna)) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										case 1:
											if (i == posRey.fila) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										case 2:
											if (j == posRey.columna) {
												start->setCoordenada(i, j);
												//Comprobacion de movimiento de nueva posicion hacia el rey
												if (start->movimientoLegal(posRey.fila, posRey.columna, p) and comprobarPieza(posRey.fila, posRey.columna)) {
													c.fila = i;
													c.columna = j;
													posicionesProteccion.push_back(c);
												}
											}
											break;
										}
									}
								}
							}
						}
						else if ((posRival.fila == i) or (posRival.columna == j)) {
							c.fila = i;
							c.columna = j;
							posicionesProteccion.push_back(c);
						}
					}
				}
			}
		}
	}

	//Recorrido por todas las piezas
	for (auto& elemento : pieza) {
		//Restriccion de bucle para ejecutarlo solo con piezas amigas de rey en jaque
		if (elemento == NULL) {}
		else if ((elemento->getColor() == colorRey) and (elemento->getTipo() != tipoRey)) {
			start = elemento;
			//Iteracion para cada casilla guardada con posibilidad de proteccion al rey
			for (auto casilla : posicionesProteccion) {
				if (elemento->movimientoLegal(casilla.fila, casilla.columna, select_pieza(casilla.fila, casilla.columna)) and comprobarPieza(casilla.fila, casilla.columna)) {
					posicionesProteccion.clear();	//Eliminamos todas las casillas guardadas
					start = aux;
					start->setCoordenada(iniStart.fila, iniStart.columna);
					return true;
				}
			}
		}
	}
	posicionesProteccion.clear();
	start = aux;
	start->setCoordenada(iniStart.fila, iniStart.columna);
	return false;
}

ListaPiezas::~ListaPiezas() {
	for (int i = 0; i < numero; i++) {
		delete pieza[i];
	}
}