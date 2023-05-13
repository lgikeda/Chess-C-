#include "Caballo.h"

Caballo::Caballo()
{

}

Caballo::Caballo(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = CABALLO;
}