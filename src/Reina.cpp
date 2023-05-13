#include "Reina.h"

Reina::Reina()
{

}

Reina::Reina(Color color, Coordenada coord)
{
	//En el futuro hacer in-line
	this->color = color;
	this->coord = coord;
	this->tipo = REINA;
}