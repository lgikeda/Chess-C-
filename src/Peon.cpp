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
	if (getColor() == NEGRO) {
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
	if (abs(coord.columna - columna) == 1) {	//Comprobacion para el desplazamiento lateral
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

	