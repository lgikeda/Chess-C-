#include "pieza.h"
#include "freeglut.h"

Pieza::Pieza() {}
Pieza::Pieza(int x, int y, char c) :x_(x), y_(y), color(c) {}


void Pieza::dibuja() const{
	glTranslatef(x_, y_, 0);
	glutSolidSphere(2, 4, 4);
	glTranslatef(-x_, -y_, 0);
	glutPostRedisplay();
}

void Pieza::set_pos_x(int posX) { x_ = posX; }
void Pieza::set_pos_y(int posY) { y_ = posY; }
int Pieza::get_pos_x() const { return x_; }
int Pieza::get_pos_y() const { return y_; }