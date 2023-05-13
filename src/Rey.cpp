#include "Rey.h"

Rey::Rey()
{

}

Rey::Rey(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = REY;
}