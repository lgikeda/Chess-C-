#pragma once
#include "PiezaGen.h"
#include "Peon.h"
#include "Caballo.h"
#include "Torre.h"
#include "Alfil.h"
#include "Dama.h"
#include "Rey.h"
#include "Coordenada.h"
#include <vector>

#define MAX_PIEZAS 32

class ListaPiezas
{

private:

	PiezaGen* pieza[MAX_PIEZAS];		// Vector de piezas
	int numero;							// Numero de piezas en el tablero (es menor o igual que MAX_PIEZAS ya que al comer una pieza, esa direccion se vuelve nullptr)
	int tipoPromocion = 0;				// Variable que indica la pieza a la que se va a promocionar
	int piezaEliminada = 0;				// Variable tipo int que indica la pieza que se va a eliminar para generar una nueva y hacer la promocion
	bool condicionPromocion = false;	// Esta variable hace que solo salte una vez el menu de promocion de piezas

	int tipoAjedrez;

	bool e_jaque = false; // estado de jaque
	bool turno = true; // true -> BLANCAS : false -> NEGRAS
	bool turno_destino = false;

public:

	//static int cambio;

	PiezaGen* start = NULL;				// Seleccion de la posicion inicial de la pieza que se va a  mover
	PiezaGen* final = NULL;				// Seleccion de la posicion final de la pieza que se va a  mover
	Coordenada CoordProm;				// Coordenadas de la pieza que se va a promocionar
	ListaPiezas();
	virtual ~ListaPiezas();
	bool agregar(PiezaGen* e);			// Agregar nuevas piezas al vector pieza
	void inicializa();					// Inicializar las piezas
	PiezaGen* select_pieza(int fila, int columna);	// Seleccion de pieza
	void destino(int fila, int columna);			// Funcion que contiene todo lo relacionado a la posicion de destino de la pieza (comer, mover, promocion, etc)
	void dibuja();									// Funcion que dibuja las piezas
	void mueve(int fila, int columna);				// Funcion que mueve las piezas
	void eliminar(PiezaGen* eliminada);				// Elimina las piezas que se han comido (pone esa direccion del vector a null)
	bool posicionIgual(PiezaGen* pstart, PiezaGen* pfinal) { return pstart->getCoordenada() == pfinal->getCoordenada(); }		// Verifica si la posicion inicial y final son distintas
	bool enroque(int fila, int columna);			// Funcion que se encarga de hacer el enroque
	bool comprobarPeon(int fila, int columna);		// Estas siguientes funciones comprueban el movimiento de las distintas piezas
	bool comprobarAlfil(int fila, int columna);		//
	bool comprobarTorre(int fila, int columna);		//
	bool comprobarDama(int fila, int columna);		//
	bool comprobarRey(int fila, int columna);		//
	bool mirarCasilla(PiezaGen* start,int fila, int columna);		// Comprueba si hay alguna pieza en cada casilla que hay entre un punto inicial y uno final
	bool comprobarPieza(int fila, int columna);						// Agrupacion de todas las comrpobaciones de piezas 				
	bool jaque(PiezaGen* s, PiezaGen* f);							// Contiene todo lo relacionado al jaque
	bool trayecto(PiezaGen* s, PiezaGen* f);						// Trayecto que recorre la pieza
	bool permisoAlJaque(PiezaGen* s);								// Verifica si se hace jaque
	bool jaqueMate();												// Todo lo relacionado al jaque mate
	bool movRey(PiezaGen* pr);										// Verifica si el rey tiene algún movimiento posible
	bool proteccionRey(PiezaGen* p);								// Ve si el rey puede protegerse o no

	// Setters //

	void setTipoPromocion(int tipo);
	void setTipoAjedrez(int tipo);

	// Getters //

	bool getTurno(int fila, int columna, bool turno);
};