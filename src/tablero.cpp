#include "tablero.h"
#include "freeglut.h"

tablero::tablero()
{
}

void tablero::dibujartablero()
{
	int fila = 1, columna = 1, x = -40, y = -40;
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
					c1 = 0;
					c2 = 0;
					c3 = 0;
				}
				glDisable(GL_LIGHTING);
				glBegin(GL_POLYGON);
				glColor3ub(c1, c2, c3);
				glTexCoord2d(0, 0);
				glVertex3f(x, 0, y);
				glTexCoord2d(0, 1);
				glVertex3f(x, 0, y + 10);
				glTexCoord2d(1, 0);
				glVertex3f(x + 10, 0, y);
				glTexCoord2d(1, 1);
				glVertex3f(x + 10, 0, y + 10);
				glEnd();
				glEnable(GL_LIGHTING);
			}

			else {
				if (fila % 2 == 0) {
					c1 = 255;
					c2 = 255;
					c3 = 255;
				}
				else {
					c1 = 0;
					c2 = 0;
					c3 = 0;
				}
				glDisable(GL_LIGHTING);
				glBegin(GL_POLYGON);
				glColor3ub(c1, c2, c3);
				glColor3ub(c1, c2, c3);
				glTexCoord2d(0, 0);
				glVertex3f(x, 0, y);
				glTexCoord2d(0, 1);
				glVertex3f(x, 0, y + 10);
				glTexCoord2d(1, 0);
				glVertex3f(x + 10, 0, y);
				glTexCoord2d(1, 1);
				glVertex3f(x + 10, 0, y + 10);
				glEnd();
				glEnable(GL_LIGHTING);
			}	
			x = x + 10;
		}
		y = y + 10;
		x = -40;
	}
}
