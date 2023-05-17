#include "entorno.h"
#include "freeglut.h"
#include <iostream>

void Entorno::inicial() {
    piezas.inicializa();
}

void Entorno::dibuja() {
    tablero.dibujarTablero();
    piezas.dibuja();

}

void Entorno::raton(int button, int state, int x, int y) {
    // Verificar si se hizo clic en el botón izquierdo del raton y si se soltó
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        // Convertir las coordenadas del mouse a una casilla en el tablero

        int casilla_x = x / 10;
        int casilla_y = (800 - y) / 10;

        for (int i = 0; i < 81; i += 10) {
            if (casilla_x >= i && casilla_x <= i + 10) { casilla_x = (i + (i + 10)) / 2; }
            if (casilla_y >= i && casilla_y <= i + 10) { casilla_y = (i + (i + 10)) / 2; }
        }

        std::cout << "Casilla seleccionada: (" << coord.to_filaColumna(casilla_x, casilla_y).first << ", " << coord.to_filaColumna(casilla_x, casilla_y).second << ")" << std::endl;
        
        piezas.mueve(coord.to_filaColumna(casilla_x, casilla_y).first, coord.to_filaColumna(casilla_x, casilla_y).second);
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

        piezas.destino(coord.to_filaColumna(casilla_x, casilla_y).first, coord.to_filaColumna(casilla_x, casilla_y).second);
    }
}