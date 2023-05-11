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
	return color;
}

Coordenada PiezaGen::getCoordenada()
{
	return coord;
}

void PiezaGen::setTipo(Tipo t) {
	this->tipo = t;
}

void PiezaGen::setColor(Color c) {
	this->color = c;
}

void PiezaGen::setCoordenada(Coordenada coord) {
	this->coord = coord;
}

void PiezaGen::dibuja() {

}


PiezaGen::~PiezaGen()
{
}