#include "PiezaGen.h"

PiezaGen::PiezaGen()
{
	
}

PiezaGen::PiezaGen(Color color, Coordenada coord, Tipo tipo)
{
	this->color = color;
	this->coord = coord;
	this->tipo = tipo;
}

Color PiezaGen::getColor()
{

	this->color = color;
	return color;
}

int PiezaGen::getPos_x()
{
	return coord.getFila();
}

int PiezaGen::getPos_y() {
	return coord.getColumna();
}

void PiezaGen::setTipo(Tipo t) {
	this->tipo = t;
}

void PiezaGen::setColor(Color c) {
	this->color = c;
}

void PiezaGen::setCoordenada(int fila, int columna) {
	this->coord.fila = fila;
	this->coord.columna = columna;
}

/*
bool movimientoLegal(int fila, int columna, PiezaGen*) {
	///Desde aquí de llamará a la función específica de cada pieza
}
*/

PiezaGen::~PiezaGen()
{

}