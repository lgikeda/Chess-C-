#include "Peon.h"

Peon::Peon()
{

}

Peon::Peon(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = PEON;
}
