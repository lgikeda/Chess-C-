#include "Coordenada.h"
#include <iostream>

Coordenada::Coordenada() {
    for (int x = 5; x < 85; x += 10) {
        for (int y = 5; y < 85; y += 10) {
            int coordenada_x = (x - 5) / 10 + 1;
            int coordenada_y = (y - 5) / 10 + 1;
            std::pair<int, int> coordenada = { coordenada_x, coordenada_y };
            mapeado[coordenada] = {x, y};
        }
    }
}

std::pair<int, int> Coordenada::to_cartesianas(int& x, int& y) {
    const auto& aux = std::make_pair(y, x);
    return mapeado[aux];
}

std::pair<int, int> Coordenada::to_filaColumna(int& x, int& y) {
    for (const auto& par_aux : mapeado) {
        if (par_aux.second == std::make_pair(y, x)) {
            return par_aux.first;
        }
    }
    return { 0,0 };
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

bool Coordenada::operator == (Coordenada v)
{
    if ((fila == v.fila) and (columna == v.columna))
        return true;
    else
        return false;
}

