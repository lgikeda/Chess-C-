#include <iostream>
#include "Interfaz.h"


Interfaz::Interfaz()
{
	estado = INICIO;						//por defecto se va a inicializar en inicio
}

Interfaz::~Interfaz()
{
}

void Interfaz::dibuja()
{
	if (estado == INICIO)
	{
		//redefimos el punto de vista para el dibujo de los menus
		glLoadIdentity();
		gluLookAt(0, 0, 33, // posicion del ojo									//z me aleja de la imagen, he centrado la imagen en 0,0 
			0, 0, 0, // hacia que punto mira (0,0,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		glEnable(GL_TEXTURE_2D);
		//glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MenuPrincipal.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex2f(-13.7f, -12);
		glTexCoord2d(1, 1); glVertex2f(13.7f, -12);
		glTexCoord2d(1, 0); glVertex2f(13.7f, 12);
		glTexCoord2d(0, 0); glVertex2f(-13.7f, 12);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	

	}
	else if (estado == JUEGO)
	{
		entorno.dibuja();					//llamamos desde aqui a la funcion dibuja de entorno
		//aqui debe ir todo el codigo correspondiente a los jaques y promociones de piezas
	}
	else if (estado == SEL_EJERCITO)
	{

		//redefinimos el punto de vista para el dibujo de los menus
		glLoadIdentity();
		gluLookAt(0, 0, 33, // posicion del ojo									//z me aleja de la imagen, he centrado la imagen en 0,0 
			0, 0, 0, // hacia que punto mira (0,0,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		glEnable(GL_TEXTURE_2D);
		//glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/SelEjercito.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 1); glVertex2f(-10, -10);
		glTexCoord2d(1, 1); glVertex2f(10, -10);
		glTexCoord2d(1, 0); glVertex2f(10, 10);
		glTexCoord2d(0, 0); glVertex2f(-10, 10);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	//else if de los estados de jaque mate blanco y jaque mate negro, y de promocionar


}


void Interfaz::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'a' || key == 'A')								//si se presiona a se inicia una partida rapida
		{
			entorno.inicial();
			estado = JUEGO;
		}
		if (key == 's' || key == 'S')								//si presionamos s se detiene el ejecutable
		{
			exit(0);
		}
		if (key == 'm' || key == 'M')								//si presionamos m pasamos a seleccion de ejercito							
		{
			estado = SEL_EJERCITO;
		}
	}

	else if (estado == SEL_EJERCITO)
	{
		if (key == '1')												//seleccionando 1 se inicia la partida con el ejercito 1
		{
			estado = JUEGO;
			entorno.inicial();										//habria que llamar a esta inicializacion de un modo especial para cada ejercito, de momento la llamo default
		}
		if (key == '2')
		{
			estado = JUEGO;
			entorno.inicial();										//deberia ser una llamada especial tambien
		}
		if (key == '3')
		{
			estado = JUEGO;
			entorno.inicial();
		}
		if (key == '4')
		{
			estado = JUEGO;
			entorno.inicial();
		}
		if (key == 's' || key == 'S')
			exit(0);

	}

}

void Interfaz::raton(int button, int state, int x, int y)
{
	entorno.raton(button, state, x, y);
}