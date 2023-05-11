#include "Tablero.h"

using namespace std;

Tablero::Tablero()
{
}

void Tablero::dibujarTablero()
{
	int fila = 1, columna = 1, x = 0, y = 0;
	int c1 = 0, c2 = 0, c3 = 0;

	for (fila = 1; fila < 9; fila++) {
		for (columna = 1; columna <9; columna ++) {
			if (columna % 2 != 0) {
				if (fila % 2 != 0) {
					c1 = 255;
					c2 = 255;
					c3 = 255;
				}
				else {
					c1 = 85;
					c2 = 72;
					c3 = 0;
				}
				glBegin(GL_POLYGON);
				glColor3ub(c1, c2, c3);
				glVertex3f(x, y, 0);
				glVertex3f(x, y + 10, 0);
				glVertex3f(x + 10, y + 10, 0);
				glVertex3f(x + 10, y, 0);
				glEnd();
			}

			else {
				if (fila % 2 == 0) {
					c1 = 255;
					c2 = 255;
					c3 = 255;
				}
				else {
					c1 = 85;
					c2 = 72;
					c3 = 0;
				}
				glBegin(GL_POLYGON);
				glColor3ub(c1, c2, c3);
				glVertex3f(x, y, 0);
				glVertex3f(x, y + 10, 0);
				glVertex3f(x + 10, y + 10, 0);
				glVertex3f(x + 10, y, 0);
				glEnd();
			}	
			x = x + 10;
		}
		y = y + 10;
		x = 0;
	}
}

void Tablero::dibuja() {
	piezas.dibuja();
}

void Tablero::mueve() {
	piezas.movimiento();
}

void Tablero::inicializa(){

	int i;
	Coordenada coord;
	for (i = 0; i < 16; i++) {
		if (0 < i < 8) {
			PiezaGen* aux = new PiezaGen(BLANCO, coord, PEON);
			coord.fila = 2;
			coord.columna = i;
			piezas.agregar(aux); // agregar a la lista
		}
		else
		{
			PiezaGen* aux = new PiezaGen(NEGRO, coord, PEON);
			coord.fila = 7;
			coord.columna = i - 8;
			piezas.agregar(aux); // agregar a la lista
		}
	}
	for (i = 16; i < 20; i++) {
		if (16 <= i < 18) {
			PiezaGen* aux = new PiezaGen(BLANCO, coord, CABALLO);
			coord.fila = 1;
			if (i == 16)
			coord.columna = 2;
			if (i == 17)
				coord.columna = 7;
			piezas.agregar(aux); // agregar a la lista
		}
		else
		{
			PiezaGen* aux = new PiezaGen(NEGRO, coord, CABALLO);
			coord.fila = 8;
			if (i == 18)
				coord.columna = 2;
			if (i == 19)
				coord.columna = 7;
			piezas.agregar(aux); // agregar a la lista
		}
	}
	for (i = 20; i < 24; i++) {
		if (20 <= i < 22) {
			PiezaGen* aux = new PiezaGen(BLANCO, coord, TORRE);
			coord.fila = 1;
			if (i == 20)
				coord.columna = 1;
			if (i == 21)
				coord.columna = 8;
			piezas.agregar(aux); // agregar a la lista
		}
		else
		{
			PiezaGen* aux = new PiezaGen(NEGRO, coord, TORRE);
			aux->setColor(NEGRO);
			coord.fila = 8;
			if (i == 22)
				coord.columna = 1;
			if (i == 23)
				coord.columna = 8;
			piezas.agregar(aux); // agregar a la lista
		}
	}
	for (i = 24; i < 28; i++) {
		if (24 <= i < 26) {
			PiezaGen* aux = new PiezaGen(BLANCO, coord, ALFIL);
			coord.fila = 1;
			if (i == 24)
				coord.columna = 3;
			if (i == 25)
				coord.columna = 6;
			piezas.agregar(aux); // agregar a la lista
		}
		else
		{
			PiezaGen* aux = new PiezaGen(NEGRO, coord, ALFIL);
			coord.fila = 8;
			if (i == 26)
				coord.columna = 3;
			if (i == 27)
				coord.columna = 6;
			piezas.agregar(aux); // agregar a la lista
		}
	}
	for (i = 28; i < 32; i++) {
		
		if (28 <= i < 30) {

			if (i == 28)
			{
				PiezaGen* aux = new PiezaGen(BLANCO, coord, REINA);
				coord.fila = 1;
				coord.columna = 5;
				piezas.agregar(aux); // agregar a la lista
			}
			if (i == 29)
			{
				PiezaGen* aux = new PiezaGen(NEGRO, coord, REINA);
				coord.fila = 8;
				coord.columna = 5;
				piezas.agregar(aux); // agregar a la lista
			}
		}
		else
		{		
			if (i == 30)
			{
				PiezaGen* aux = new PiezaGen(BLANCO, coord, REY);
				coord.fila = 1;
				coord.columna = 4;
				piezas.agregar(aux); // agregar a la lista
			}
			if (i == 31)
			{
				PiezaGen* aux = new PiezaGen(NEGRO, coord, REY);
				coord.fila = 8;
				coord.columna = 4;
				piezas.agregar(aux); // agregar a la lista
			}
		}	
	}
}