#include "tablero.h"
#include "freeglut.h"

tablero::tablero()
{
	total_piezas.push_back(new Peon(15, 5, 'b'));
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
	total_piezas[0]->dibuja();
}
void tablero::mover(int x, int y) {
	
	if (select_pieza(x, y) != NULL) {
		start = total_piezas[0];
		std::cout << "Casilla Correcta!" << std::endl;
	}
}
Pieza* tablero::select_pieza(int x, int y) {
	if (total_piezas[0]->get_pos_x() == x and total_piezas[0]->get_pos_y() == y) {
		return total_piezas[0];
	}
	return NULL;
}
void tablero::destino(int x, int y) {
	final = select_pieza(x, y);
	if (start->verification_move(x, y, final)) {
		start->set_pos_x(x);
		start->set_pos_y(y);
	}
}