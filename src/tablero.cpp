#include "Tablero.h"
#include <iostream>

using namespace std;

ListaPiezas lista;

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
	/*
	* 
	*  //PONER NUMEROS EN EL TABLERO
	* 
	for (int i = 0; i < 8; i++) {
		switch (i) {
		case 0:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/1.png").id);
			break;
		case 1:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/2.png").id);
			break;
		case 2:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/3.png").id);
			break;
		case 3:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/4.png").id);
			break;
		case 4:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/5.png").id);
			break;
		case 5:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/6.png").id);
			break;
		case 6:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/7.png").id);
			break;
		case 7:
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/8.png").id);
			break;
		}

		glBegin(GL_POLYGON);
		glTexCoord2d(1, 1); glVertex3f(-1.0f + i * 8.0f, -0.5f, -1.0f);
		glTexCoord2d(0, 1); glVertex3f(-1.0f + i * 8.0f, -0.5f, -9.0f);
		glTexCoord2d(0, 0); glVertex3f(9.0f + i * 8.0f, -0.5f, -9.0f);
		glTexCoord2d(1, 0); glVertex3f(9.0f + i * 8.0f, -0.5f, -1.0f);
		glEnd();
	}
	glEnable(GL_LIGHTING);
	*/
	
}

void Tablero::dibuja() {
	piezas.dibuja();
}

void Tablero::inicializa(){

	int i;
	Coordenada coord;
	for (i = 1; i < 17; i++) {
		if (1 <= i and i <= 8) {
			coord.fila = 2;
			coord.columna = i;
			PiezaGen* aux = new Peon(BLANCO, coord);
			piezas.agregar(aux); // agregar a la lista
		}
		if (8 < i and i <= 17)
		{
			coord.fila = 7;
			coord.columna = i - 8;
			PiezaGen* aux = new Peon(NEGRO, coord);
			piezas.agregar(aux); // agregar a la lista
		}
	}
	//for (i = 8; i < 17; i++) {
	//	if (8 < i <17) 
	//	{
	//		coord.fila = 7;
	//		coord.columna = i - 8;
	//		PiezaGen* aux = new Peon(NEGRO, coord);
	//		piezas.agregar(aux); // agregar a la lista
	//		}
	//}
	

	//for (i = 16; i < 20; i++) {
	//	if (16 <= i < 18) {
	//		PiezaGen* aux = new Caballo(BLANCO, coord);
	//		coord.fila = 1;
	//		if (i == 16)
	//		coord.columna = 2;
	//		if (i == 17)
	//			coord.columna = 7;
	//		piezas.agregar(aux); // agregar a la lista
	//	}
	//	else
	//	{
	//		PiezaGen* aux = new Caballo(NEGRO, coord);
	//		coord.fila = 8;
	//		if (i == 18)
	//			coord.columna = 2;
	//		if (i == 19)
	//			coord.columna = 7;
	//		piezas.agregar(aux); // agregar a la lista
	//	}
	//}
	//for (i = 20; i < 24; i++) {
	//	if (20 <= i < 22) {
	//		PiezaGen* aux = new Torre(BLANCO, coord);
	//		coord.fila = 1;
	//		if (i == 20)
	//			coord.columna = 1;
	//		if (i == 21)
	//			coord.columna = 8;
	//		piezas.agregar(aux); // agregar a la lista
	//	}
	//	else
	//	{
	//		PiezaGen* aux = new Torre(NEGRO, coord);
	//		aux->setColor(NEGRO);
	//		coord.fila = 8;
	//		if (i == 22)
	//			coord.columna = 1;
	//		if (i == 23)
	//			coord.columna = 8;
	//		piezas.agregar(aux); // agregar a la lista
	//	}
	//}
	//for (i = 24; i < 28; i++) {
	//	if (24 <= i < 26) {
	//		PiezaGen* aux = new Alfil(BLANCO, coord);
	//		coord.fila = 1;
	//		if (i == 24)
	//			coord.columna = 3;
	//		if (i == 25)
	//			coord.columna = 6;
	//		piezas.agregar(aux); // agregar a la lista
	//	}
	//	else
	//	{
	//		PiezaGen* aux = new Alfil(NEGRO, coord);
	//		coord.fila = 8;
	//		if (i == 26)
	//			coord.columna = 3;
	//		if (i == 27)
	//			coord.columna = 6;
	//		piezas.agregar(aux); // agregar a la lista
	//	}
	//}
	//for (i = 28; i < 32; i++) {
	//	
	//	if (28 <= i < 30) {

	//		if (i == 28)
	//		{
	//			PiezaGen* aux = new Reina(BLANCO, coord);
	//			coord.fila = 1;
	//			coord.columna = 5;
	//			piezas.agregar(aux); // agregar a la lista
	//		}
	//		if (i == 29)
	//		{
	//			PiezaGen* aux = new Reina(NEGRO, coord);
	//			coord.fila = 8;
	//			coord.columna = 5;
	//			piezas.agregar(aux); // agregar a la lista
	//		}
	//	}
	//	else
	//	{		
	//		if (i == 30)
	//		{
	//			PiezaGen* aux = new Rey(BLANCO, coord);
	//			coord.fila = 1;
	//			coord.columna = 4;
	//			piezas.agregar(aux); // agregar a la lista
	//		}
	//		if (i == 31)
	//		{
	//			PiezaGen* aux = new Rey(NEGRO, coord);
	//			coord.fila = 8;
	//			coord.columna = 4;
	//			piezas.agregar(aux); // agregar a la lista
	//		}
	//	}	
	//}
}

void Tablero::mueve(int fila, int columna) {
	piezas.mueve(fila, columna);
}

void Tablero::destino(int fila, int columna) {
	std::cout << "casilla destino en  fila columna: " << fila << ";" << columna << std::endl;
	piezas.destino(fila,columna);
}