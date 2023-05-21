#pragma once
#include <map>

class Coordenada{

public:
	int fila=0;
	int columna=0;
	//Constructor
	Coordenada();
	
	//Getters
	int getColumna() { return columna; }
	int getFila() { return fila; }

	int getColorcasilla() {};
	//string getLetra();

	//Setters
	void setFila() {};
	void setColumna() {};
	
	//Convertidores y Operadores
	bool operator == (Coordenada corrd);
	Coordenada operator + (Coordenada v);
	Coordenada operator - (Coordenada coord);


	std::pair<int, int> to_cartesianas(int& x, int& y);
	std::pair<int, int> to_filaColumna(int& x, int& y);

private:
	std::map<std::pair<int,int>, std::pair<int, int>> mapeado;
};