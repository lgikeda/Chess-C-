#include "Tablero.h"

using namespace std;

Tablero::Tablero()
{
}

void Tablero::dibujarTablero()
{
	Sprite s1{ "bin/imagenes/1 (1).png" };
	Sprite s2{ "bin/imagenes/1 (2).png" };
	Sprite s3{ "bin/imagenes/1 (3).png" };
	Sprite s4{ "bin/imagenes/1 (4).png" };
	Sprite s5{ "bin/imagenes/1 (5).png" };
	Sprite s6{ "bin/imagenes/1 (6).png" };
	Sprite s7{ "bin/imagenes/1 (7).png" };
	Sprite s8{ "bin/imagenes/1 (8).png" };

	int fila = 1, columna = 1, x = 0, y = 0;
	int c1 = 0, c2 = 0, c3 = 0;

	for (fila = 1; fila < 9; fila++) {
		for (columna = 1; columna < 9; columna++) {
			if (columna % 2 == 0) {
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

		glBegin(GL_POLYGON);
		glColor3ub(45, 50, 20);
		glVertex3f(-30, 100, -0.2f);
		glVertex3f(100, 100, -0.2f);
		glVertex3f(100, -30, -0.2f);
		glVertex3f(-30, -30, -0.2f);
		glEnd();

		s1.setCenter(8, -2);
		s1.setSize(5, 5);
		s1.draw();
		s2.setCenter(7.5, -12.5);
		s2.setSize(5, 5);
		s2.draw();
		s3.setCenter(7.5, -21.5f);
		s3.setSize(5, 5);
		s3.draw();
		s4.setCenter(7.1, -32.5f);
		s4.setSize(4.75, 4.65);
		s4.draw();
		s5.setCenter(7.1, -42.5);
		s5.setSize(5, 5);
		s5.draw();
		s6.setCenter(6.75, -52.5);
		s6.setSize(4.75, 5);
		s6.draw();
		s7.setCenter(6.75, -62);
		s7.setSize(5, 5);
		s7.draw();
		s8.setCenter(6.75, -72.5);
		s8.setSize(5.25, 5.25);
		s8.draw();
		s1.setCenter(-2.5, -81.5);
		s1.setSize(5, 5);
		s1.draw();
		s2.setCenter(-12.75, -81.5);
		s2.setSize(5, 5);
		s2.draw();
		s3.setCenter(-22.5, -81.25);
		s3.setSize(5, 5);
		s3.draw();
		s4.setCenter(-32.5, -81.35);
		s4.setSize(4.75, 4.65);
		s4.draw();
		s5.setCenter(-42.5, -81.25);
		s5.setSize(5, 5);
		s5.draw();
		s6.setCenter(-52.5, -81.25);
		s6.setSize(4.75, 5);
		s6.draw();
		s7.setCenter(-62.5, -81.25);
		s7.setSize(5, 5);
		s7.draw();
		s8.setCenter(-72.4, -81.25);
		s8.setSize(5.25, 5.25);
		s8.draw();
	}
}