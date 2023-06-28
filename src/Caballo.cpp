#include "Caballo.h"

Caballo::Caballo(Color color, Coordenada coord) :PiezaGen(color, coord, CABALLO) {}

void Caballo::dibuja() {
	if (tipoAjedrez != 1) {
		Sprite spriteN{ "bin/imagenes/caballoNegro.png" };
		Sprite spriteB{ "bin/imagenes/caballoBlanco.png" };

		if (getColor() == NEGRO) {
			spriteN.setCenter(-coord.to_cartesianas(coord.fila, coord.columna).first + 5, -coord.to_cartesianas(coord.fila, coord.columna).second + 5);
			spriteN.setSize(10, 10);
			spriteN.draw();
		}

		else if (getColor() == BLANCO) {
			spriteB.setCenter(-coord.to_cartesianas(coord.fila, coord.columna).first + 5, -coord.to_cartesianas(coord.fila, coord.columna).second + 5);
			spriteB.setSize(10, 10);
			spriteB.draw();
		}
	}

	else if (tipoAjedrez == 1) {

		Sprite spriteN{ "bin/imagenes/gollum.png" };
		Sprite spriteB{ "bin/imagenes/sam.png" };

		if (getColor() == NEGRO) {
			spriteN.setCenter(-coord.to_cartesianas(coord.fila, coord.columna).first + 5, -coord.to_cartesianas(coord.fila, coord.columna).second + 5);
			spriteN.setSize(10, 10);
			spriteN.draw();
		}

		else if (getColor() == BLANCO) {
			spriteB.setCenter(-coord.to_cartesianas(coord.fila, coord.columna).first + 5, -coord.to_cartesianas(coord.fila, coord.columna).second + 5);
			spriteB.setSize(10, 10);
			spriteB.draw();
		}
	}
}

bool Caballo::movimientoLegal(int fila, int columna, PiezaGen* casilla) {
	if ((coord.fila == fila) and (coord.columna == columna)) {	//Comprobacion de quedarse en la misma casilla
		std::cout << "Movimiento invalido, selecciona distinta casilla a la inicial" << std::endl;
		return false;
	}

	else if (((abs(coord.fila - fila) == 1) or (abs(coord.columna - columna) == 1)) and ((abs(coord.fila - fila) == 2) or (abs(coord.columna - columna) == 2))) {	//Comprobacion de movimiento en direccion correcta
		std::cout << "Movimiento invalido, no se puede desplazar en x" << std::endl;;
		std::cout << "coord.columna = " << coord.columna << ";" << "columa = " << columna << std::endl;;
		return true;
	}

	else if (casilla != NULL) {
		std::cout << "Movimiento no valido: La casilla debe estar vacia";
		return false;
	}
	first_move = false;
	return false;
}