#include "Coordenada.h"

Coordenada::Coordenada() {
	fila = 0;
	columna = 0;
}

///	Esta sbrecarga de suma es porque para las filas y las columnas 
/// se sumarán sus coordenadas, siendo las "x" de fila 0 y las "y" 
/// de columna 0, para así tener la coordenada del centro de impresión

Coordenada Coordenada::operator + (Coordenada v)
{
	Coordenada res;
	res.fila = fila + v.fila;
	res.columna = columna + v.columna;
	return res;
}
