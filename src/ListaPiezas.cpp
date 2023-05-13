#include "ListaPiezas.h"
#include<iostream>

ListaPiezas::ListaPiezas() {
	numero = 0;
	for (int i = 0; i < MAX_PIEZAS; i++)
		pieza[i] = 0;
}

bool ListaPiezas::agregar(PiezaGen* p) {
	if (numero < MAX_PIEZAS)
		pieza[numero++] = p; // �ltimo puesto sin rellenar
	else
		return false; // capacidad m�xima alcanzada
	return true;
}

PiezaGen* ListaPiezas::select_pieza(int fil, int col) {
	for (int i = 0; i < numero; i++)
	{
		if (pieza[i]->getPos_x() == fil and pieza[i]->getPos_y() == col) {
			std::cout << "//////////Objeto seleccionado///////////" << std::endl;
			return pieza[i];
		}
		
		/*std::cout << "no se encontro objeto en : " << fil << ";"<<  col << std::endl;
		std::cout << "para pieza[] : " << pieza[i]->getPos_x() << ";" << pieza[i]->getPos_y() << std::endl;
		return NULL;*/
	}
	std::cout << "no se encontro objeto en : " << fil << ";" << col << std::endl;
	//std::cout << "para pieza[] : " << pieza[i]->getPos_x() << ";" << pieza[i]->getPos_y() << std::endl;
	return NULL;
}

void ListaPiezas::destino(int fila, int columna) {
	final = select_pieza(fila, columna);
	if (start->movimientoLegal(fila, columna, final)) {
		start->setCoordenada(fila, columna);
	}
}

void ListaPiezas::mueve(int fila, int columna) {
	if (select_pieza(fila, columna) != NULL) {
		start = select_pieza(fila, columna);
	}
}

void ListaPiezas::dibuja() {
	for (int i = 0; i < numero; i++)
		pieza[i]->dibuja();
}

ListaPiezas::~ListaPiezas() {

}