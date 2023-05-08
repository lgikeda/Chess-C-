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


void PiezaGen::dibuja() {

	

}


PiezaGen::~PiezaGen()
{
}