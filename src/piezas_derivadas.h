#pragma once
#include "pieza.h"

class Peon:public Pieza
{
	bool first_move=true; 

public:
	Peon();
	Peon(int x, int y, char c);
	~Peon() override;

	bool verification_move(int x, int y, Pieza* casilla) override;
};

class Rey :public Pieza
{

public:
	Rey();
	Rey(int x, int y, char c);
	~Rey() override;

	bool verification_move(int x, int y, Pieza* casilla) override;
};