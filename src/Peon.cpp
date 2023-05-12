#include "Peon.h"
#include "freeglut.h"

Peon::Peon() {
    sprite.setCenter(0, 0);
    sprite.setSize(1, 1);
    tamano = 0.01f;
    estado = 0;
}

Peon::Peon(int _f, int _c, int _color) {
    sprite.setCenter(0, 0);
    sprite.setSize(1, 1);
    tamano = 0.01f;
    posicion = Vector().conversor(_f, _c);
    color = _color;
    estado = 0;
    fc.setCasillas(_f, _c);
}

void Peon::dibuja() {
    glTranslatef(posicion.getX(), posicion.getY(), 0.5);
    if (color == 0) {
        glColor3f(1.0f, 0.0f, 0.0f);
    }
    else {
        glColor3f(0.0f, 0.0f, 1.0f);
    }
    sprite.draw();
}

int Peon::getTipoPieza() {
    return 6;
}
