#include "Rey.h"

Rey::Rey()
{

}

Rey::Rey(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = REY;
}

//Color Peon::getColor(Color color) {
//	return color;
//}

void Rey::dibuja() {
	if (tipoAjedrez != 1) {
		Sprite spriteN{ "bin/imagenes/reyNegro.png" };
		Sprite spriteB{ "bin/imagenes/reyBlanco.png" };

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

	if (tipoAjedrez == 1) {

		Sprite spriteN{ "bin/imagenes/sauron.png" };
		Sprite spriteB{ "bin/imagenes/frodo.png" };

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
}

bool Rey::movimientoLegal(int fila, int columna, PiezaGen* casilla) {
	if ((coord.fila == fila) and (coord.columna == columna)) {	//Comprobacion de quedarse en la misma casilla
		std::cout << "Movimiento invalido, selecciona distinta casilla a la inicial" << std::endl;
		return false;
	}
	if (((abs(coord.fila - fila) == 1) and (abs(coord.columna - columna) == 1)) or ((abs(coord.fila - fila) == 1) and (abs(coord.columna - columna) == 0)) or ((abs(coord.fila - fila) == 0) and (abs(coord.columna - columna) == 1))) {	//Comprobacion de movimiento en direccion correcta
		std::cout << "Movimiento invalido, no se puede desplazar en x" << std::endl;;
		std::cout << "coord.columna = " << coord.columna << ";" << "columa = " << columna << std::endl;;
		first_move = false;
		return true;
	}
	else if (casilla != NULL) {
		std::cout << "Movimiento no valido: La casilla debe estar vacia";
		return false;
	}
	return false;
}