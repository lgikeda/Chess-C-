#include "Alfil.h"

Alfil::Alfil()
{

}

Alfil::Alfil(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = ALFIL;
}