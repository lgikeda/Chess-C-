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
				glVertex3f(x, y, -0.1f);
				glVertex3f(x, y + 10, -0.1f);
				glVertex3f(x + 10, y + 10, -0.1f);
				glVertex3f(x + 10, y, -0.1f);
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
				glVertex3f(x, y, -0.1f);
				glVertex3f(x, y + 10, -0.1f);
				glVertex3f(x + 10, y + 10, -0.1f);
				glVertex3f(x + 10, y, -0.1f);
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

