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
    // Verificar si se hizo clic en el boton izquierdo del raton y si se solto
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        // Convertir las coordenadas del mouse a una casilla en el tablero
        std::cout << "Casilla click: (" << x << ", " << y << ")" << std::endl;
        /////////////////////////////////////////////////////////////////////////////////// RELACION    //////////////////////////////////////////////////

        int tableroSize = 80;
        int windowWidth = 800;
        int windowHeight = 700;
        int margenX = (windowWidth - (static_cast<float>(tableroSize) * 7.4125)) / 2;
        int margenY = (windowHeight - (static_cast<float>(tableroSize) * 7.425)) / 2;
        float scale = static_cast<float>(tableroSize * 7.4125) / windowWidth;

        int casilla_x = static_cast<int>((x - margenX) * scale);
        int casilla_y = static_cast<int>((windowHeight - y - margenY) * scale);

        std::cout << "Casilla_x e _y: (" << casilla_x << ", " << casilla_y << ")" << std::endl;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (int i = 0; i < 700; i += 55) {
            if (casilla_x >= i && casilla_x <= i + 55) {
                casilla_x = ((i + i + 55) / 5.5) / 2;
            }
            if (casilla_y >= i && casilla_y <= i + 55) {
                casilla_y = ((i + i + 55) / 5.5) / 2;
            }
        }

        std::cout << "Casilla seleccionada: (" << coord.to_filaColumna(casilla_x, casilla_y).first << ", " << coord.to_filaColumna(casilla_x, casilla_y).second << ")" << std::endl;

        piezas.mueve(coord.to_filaColumna(casilla_x, casilla_y).first, coord.to_filaColumna(casilla_x, casilla_y).second);
    }
    // Verificar si se hizo clic en el boton derecho del raton y si se solto
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        int tableroSize = 80;
        int windowWidth = 800;
        int windowHeight = 700;
        int margenX = (windowWidth - (static_cast<float>(tableroSize) * 7.4125)) / 2;
        int margenY = (windowHeight - (static_cast<float>(tableroSize) * 7.425)) / 2;
        float scale = static_cast<float>(tableroSize * 7.4125) / windowWidth;

        int casilla_x = static_cast<int>((x - margenX) * scale);
        int casilla_y = static_cast<int>((windowHeight - y - margenY) * scale);
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (int i = 0; i < 700; i += 55) {
            if (casilla_x >= i && casilla_x <= i + 55) {
                casilla_x = ((i + i + 55) / 5.5) / 2;
            }
            if (casilla_y >= i && casilla_y <= i + 55) {
                casilla_y = ((i + i + 55) / 5.5) / 2;
            }
        }

        piezas.destino(coord.to_filaColumna(casilla_x, casilla_y).first, coord.to_filaColumna(casilla_x, casilla_y).second);
    }
}