#include "entorno.h"
#include "freeglut.h"
#include <iostream>

//Entorno::Entorno() {};

void Entorno::inicial() {
    //peon = Peon(5, 5, 'b');
    //rey = Rey(55, 55, 'b');
}

void Entorno::dibuja() {
	tablero.dibujartablero();
	//peon.dibuja();
    //rey.dibuja();
}

void Entorno::mover() {
	
}

void Entorno::tecla(unsigned char key) {
	if (key == 'd') {
		//peon.mov_rey("a2");
	}
}


void Entorno::raton(int button, int state, int x, int y) {
    // Verificar si se hizo clic en el botón izquierdo del raton y si se soltó
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        // Convertir las coordenadas del mouse a una casilla en el tablero
      
        int casilla_x = x/10;
        int casilla_y = (800 - y)/ 10;

        for (int i = 0; i < 81; i+=10) {
            if (casilla_x >= i && casilla_x <= i+10) {casilla_x = (i + (i+10))/2;}
            if (casilla_y >= i && casilla_y <= i + 10) {casilla_y = (i + (i + 10)) / 2;}
        }
     
        std::cout << "Casilla seleccionada: (" << casilla_x << ", " << casilla_y << ")" << std::endl;
        tablero.mover(casilla_x, casilla_y);
    }
    // Verificar si se hizo clic en el botón derecho del raton y si se soltó
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        // Convertir las coordenadas del mouse a una casilla en el tablero

        int casilla_x = x / 10;
        int casilla_y = (800 - y) / 10;

        for (int i = 0; i < 81; i += 10) {
            if (casilla_x >= i && casilla_x <= i + 10) { casilla_x = (i + (i + 10)) / 2; }
            if (casilla_y >= i && casilla_y <= i + 10) { casilla_y = (i + (i + 10)) / 2; }
        }

        std::cout << "Casilla seleccionada: (" << casilla_x << ", " << casilla_y << ")" << std::endl;
        tablero.destino(casilla_x, casilla_y);
    }
}