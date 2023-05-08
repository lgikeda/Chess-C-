#include "piezas_derivadas.h"

Peon::Peon(int x, int y, char c) :Pieza(x, y, c), first_move(true) { tipo_pieza[0] = 'P'; }
Peon::Peon() :Pieza() {}
Peon::~Peon() {}

bool Peon::verification_move(int x, int y, Pieza* casilla) {
	if ((x_ == x) and (y_ == y)) {	//Comprobacion de quedarse en la misma casilla
		std::cout << "Movimiento invalido" << std::endl;
		return false;
	}
	if (first_move) {	//Comprobacion de primer movimiento permitiendo doble desplazamiento
		if ((x_ == x) and (y_ - y) == (color == 'b' ? -20 : 20) and casilla == NULL) {
			std::cout << "Movimiento valido" << std::endl;
			first_move = false;
			return true;
		}
	}
	if (((y_-y)!=(color == 'b'? -10:10)) or abs(x_ -x)>1) {	//Comprobacion de movimiento en direccion correcta segun el color
		std::cout << "Movimiento invalido" << std::endl;;
		return false;
	}
	if (abs(x-x)) {	//Comprobacion para el desplazamiento lateral
		if (casilla == NULL) {	//Comprobacion de existencia de pieza para comer
			std::cout << std::endl << "Movimiento invalido: La casilla debe tener una pieza contraria";
			return false;
		}
		/*if (casilla->get_color() == color) {	//Comprobacion de pieza de color contraria para comer
			std::cout << std::endl << "Movimiento invalido: La casilla debe tener una pieza contraria";
			return false;
		}*/
	}
	else if (casilla != NULL) {
		std::cout << "Movimiento no valido: La casilla debe estar vacia";
		return false;
	}
	first_move = false;
	return true;
}

Rey::Rey(int x, int y, char c) :Pieza(x, y, c) { tipo_pieza[0] = 'R'; }
Rey::Rey() :Pieza() {}
Rey::~Rey() {}

bool Rey::verification_move(int x, int y, Pieza* casilla) { return false; }