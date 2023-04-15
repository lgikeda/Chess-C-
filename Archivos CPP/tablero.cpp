#include "tablero.h"
#include "freeglut.h"

tablero::tablero()
{
}

void tablero::dibujartablero()
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
