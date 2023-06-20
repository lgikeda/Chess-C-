#include <iostream>
#include "Interfaz.h"
#include <chrono>
#include <thread>

Interfaz::Interfaz()
{
	estado = INICIO;						//por defecto se va a inicializar en inicio
}

Interfaz::~Interfaz()
{
}

int Interfaz::j = 0;

void Interfaz::dibuja()
{
	if ((j != 0) and (j != 5) and (j != 6)) setEstado();

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
		if (j == 5) {
			//estado = INICIO;
			estado = PROMOCION_B;
		}

		else if (j == 6) {
			//estado = INICIO;
			estado = PROMOCION_N;
		}
		else if (not ((j == 5) or (j == 6)))
		entorno.dibuja(); //llamamos desde aqui a la funcion dibuja de entorno
		
	}
	
	else if (estado == PROMOCION_B)
	{
		//redefimos el punto de vista para el dibujo de los menus
		glLoadIdentity();
		gluLookAt(0, 0, 33, // posicion del ojo									//z me aleja de la imagen, he centrado la imagen en 0,0 
			0, 0, 0, // hacia que punto mira (0,0,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		glEnable(GL_TEXTURE_2D);
		//glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MenuPromocion.png").id);
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

	else if (estado == PROMOCION_N)
	{
		//redefimos el punto de vista para el dibujo de los menus
		glLoadIdentity();
		gluLookAt(0, 0, 33, // posicion del ojo									//z me aleja de la imagen, he centrado la imagen en 0,0 
			0, 0, 0, // hacia que punto mira (0,0,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		glEnable(GL_TEXTURE_2D);
		//glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MenuPromocion.png").id);
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

	else if (estado == AJUSTES)
	{
		//redefimos el punto de vista para el dibujo de los menus
		glLoadIdentity();
		gluLookAt(0, 0, 33, // posicion del ojo									//z me aleja de la imagen, he centrado la imagen en 0,0 
			0, 0, 0, // hacia que punto mira (0,0,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 
		glEnable(GL_TEXTURE_2D);
		//glColor3f(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/MenuAjustesAudio.png").id);
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
	else if (estado == JAQUE) {
		
		// Configura el color del texto
		//glColor3f(1.0f, 1.0f, 1.0f); // Blanco
		// Configura la posición del texto
		glRasterPos2f(20.0f, 40.0f);

		// Dibuja cada carácter individual del texto "JAQUE"
		if (j == 1) {
			std::string texto = "JAQUE AL REY NEGRO!!!";
			for (char c : texto) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
			}	
			estado = JUEGO;
		}
		else if(j==2){
			std::string texto = "JAQUE AL REY BLANCO!!!";
			for (char c : texto) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c); 
			}
			estado = JUEGO;
		}
		else if (j == 3) {
			std::string texto = "JAQUE MATE AL REY NEGRO!!!";
			for (char c : texto) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
			}
			estado = INICIO;
		}
		else if (j == 4) {
			std::string texto = "JAQUE MATE AL REY BLANCO!!!";
			for (char c : texto) {
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
			}
			estado = INICIO;
		}
		
		glutSwapBuffers();
		//estado = JUEGO;
		j = 0;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		dibuja();
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

	if (estado == JUEGO) {

		if (key == 27) {
			estado = AJUSTES;
		}

	}

	if ((estado == PROMOCION_B) or (estado == PROMOCION_N))
	{
			if (key == '1')								//ALFIL
			{
				estado = JUEGO;
				tipoPromocion = 1;
				j = 0;
			}
			if (key == '2')								//CABALLO
			{
				estado = JUEGO;
				tipoPromocion = 2;
				j = 0;
			}
			if (key == '3')								//REINA							
			{
				estado = JUEGO;
				tipoPromocion = 3;
				j = 0;
			}
			if (key == '4')								//TORRE							
			{
				estado = JUEGO;
				tipoPromocion = 4;
				j = 0;
			}
			entorno.getTipoPromocion(tipoPromocion);
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
