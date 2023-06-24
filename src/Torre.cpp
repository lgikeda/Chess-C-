#include "Torre.h"

Torre::Torre()
{

}

Torre::Torre(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = TORRE;
}

//Color Peon::getColor(Color color) {
//	return color;
//}

void Torre::dibuja() {
	if (tipoAjedrez != 1) {
		Sprite spriteN{ "bin/imagenes/torreNegra.png" };
		Sprite spriteB{ "bin/imagenes/torreBlanca.png" };

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

		Sprite spriteN{ "bin/imagenes/balrog.png" };
		Sprite spriteB{ "bin/imagenes/gimli.png" };

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

bool Torre::movimientoLegal(int fila, int columna, PiezaGen* casilla) {
	
	if ((coord.fila == fila) and (coord.columna == columna)) {	//Comprobacion de quedarse en la misma casilla
		std::cout << "Movimiento invalido, selecciona distinta casilla a la inicial" << std::endl;
		return false;
	}
	if ((abs(coord.fila - fila) == 0) or (abs(coord.columna - columna) == 0)) {	//Comprobacion de movimiento en direccion correcta
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