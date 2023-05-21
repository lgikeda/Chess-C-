#include "Peon.h"

Peon::Peon()
{

}

Peon::Peon(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = PEON;
}

//Color Peon::getColor(Color color) {
//	return color;
//}

void Peon::dibuja() {
	if (getColor() == NEGRO){
		spriteN.setCenter(-coord.to_cartesianas(coord.fila, coord.columna).first + 5, -coord.to_cartesianas(coord.fila, coord.columna).second + 5);
		spriteN.setSize(10, 10);
		spriteN.draw();
	}
		
	if (getColor() == BLANCO) {
		spriteB.setCenter(-coord.to_cartesianas(coord.fila, coord.columna).first + 5, -coord.to_cartesianas(coord.fila, coord.columna).second + 5);
		spriteB.setSize(10, 10);
		spriteB.draw();
	}
}

bool Peon::movimientoLegal(int fila, int columna, PiezaGen* casilla) {

	if ((coord.fila == fila) and (coord.columna == columna)) {	//Comprobacion de quedarse en la misma casilla
		std::cout << "Movimiento invalido, selecciona distinta casilla a la inicial" << std::endl;
		return false;
	}
	if (first_move) {	//Comprobacion de primer movimiento permitiendo doble desplazamiento
		if ((coord.columna == columna) and (coord.fila - fila) == (color == BLANCO ? -2 : 2) and casilla == NULL) {
			std::cout << "Movimiento valido, se puede desplazar doble" << std::endl;
			first_move = false;
			return true;
		}
	}
	if (((coord.fila - fila) != (color == BLANCO ? -1 : 1)) or abs(coord.columna - columna) > 1) {	//Comprobacion de movimiento en direccion correcta segun el color
		std::cout << "Movimiento invalido, no se puede desplazar en x" << std::endl;;
		std::cout << "coord.columna = " << coord.columna << ";" << "columa = " << columna << std::endl;
		return false;
	}
	if (abs(coord.columna - columna)) {	//Comprobacion para el desplazamiento lateral
		if (casilla == NULL) {	//Comprobacion de existencia de pieza para comer
			std::cout << std::endl << "Movimiento invalido: La casilla debe tener una pieza contraria";
			return false;
		}
		if (casilla->getColor() == color) {	//Comprobacion de pieza de color contraria para comer
			std::cout << std::endl << "Movimiento invalido: La casilla debe tener una pieza contraria";
			return false;
		}
	}
	else if ((casilla != NULL) /*or (casillas != NULL)*/) {
		std::cout << "Movimiento no valido: La casilla debe estar vacia";
		return false;
	}

	first_move = false;
	return true;
}

//bool Peon::comprobar(PiezaGen* casilla, int fila, int columna)
//{
//	bool flag = false;
//
//	//Primero comprobamos el color del peon
//	if (getColor() == BLANCO)
//	{
//		//Comprobacion para la captura en la diagonal derecha
//		if (((casilla->getCoordenada().second - columna) == 1) && ((casilla->getCoordenada().first - fila) == 1)) {
//			if (mirarCasilla(fila, columna)) return true;
//			else return false;
//		}
//		//Comprobacion para la captura en la diagonal izquierda
//		if (((casilla->getCoordenada().second - columna) == -1) && ((casilla->getCoordenada().first - fila) == 1)) {
//			if (mirarCasilla(fila, columna)) return true;
//			else return false;
//		}
//
//		//Colision en el movimiento hacia delante
//		if (mirarCasilla(fila + 1, columna)) return false;
//
//		//Movimiento de dos casillas hacia delante si el peon no se ha movido
//		if ((fila) == (2))
//		{
//			//Comprobamos si hay colisiones
//			if (mirarCasilla(fila + 2, columna)) flag = true;
//			if (mirarCasilla(fila + 1, columna)) return false;
//
//			if (casilla->getCoordenada().first == 3) return true;
//			else if (flag) return false;
//		}
//		return true;
//	}
//	else {
//		//El negro tiene el mismo esquema que el del peon blanco pero cambiando las comprobaciones para ajustarse a su naturaleza simétrica
//
//		if (((casilla->getCoordenada().second - columna) == -1) && ((casilla->getCoordenada().first - fila) == -1)) {
//			if (mirarCasilla(fila, columna)) return true;
//			else return false;
//		}
//		if (((casilla->getCoordenada().second - columna) == 1) && ((casilla->getCoordenada().first - fila) == -1)) {
//			if (mirarCasilla(fila, columna)) return true;
//			else return false;
//		}
//
//		if (mirarCasilla(fila - 1, columna)) return false;
//
//		if (fila == (7))
//		{
//			if (mirarCasilla(fila - 2, columna)) flag = true;
//			if (mirarCasilla(fila - 1, columna)) return false;
//
//			if (casilla->getCoordenada().first == 6) return true;
//
//			else if (flag) return false;
//		}
//		flag = false;
//		return true;
//	}
//}

	