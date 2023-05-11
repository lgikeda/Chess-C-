#include "ListaPiezas.h"

ListaPiezas::ListaPiezas() {
	
	numero = 0;
	for (int i = 0; i < MAX_PIEZAS; i++)
		pieza[i] = 0;
	
}

bool ListaPiezas::agregar(PiezaGen* p) {
	if (numero < MAX_PIEZAS)
		pieza[numero++] = p; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaPiezas::dibuja() {
	for (int i = 0; i < numero; i++)
		pieza[i]->dibuja();

}

void ListaPiezas::movimiento() {
	
}

ListaPiezas::~ListaPiezas() {

}