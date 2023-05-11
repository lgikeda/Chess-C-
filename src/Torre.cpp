#include "Torre.h"

Torre::Torre()
{

}

Torre::Torre(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = TORRE;
}