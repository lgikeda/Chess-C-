#pragma once
#include <iostream>

class Pieza {
protected:

    int x_ =0;
    int y_ =0;
    
    char color = 'b';
    std::string tipo_pieza;

public:
    Pieza();
    Pieza(int x, int y, char c);
    virtual ~Pieza() = default;
   void set_pos_x(int posX);
   void set_pos_y(int posY);
   int get_pos_x() const;
   int get_pos_y() const;
   //char get_color() const;
   //std::string get_icono();

    virtual bool verification_move(int x, int y,Pieza* casilla) = 0;
  
    virtual void dibuja() const;
    
    /*
    std::string obtenerPosicion();
    void mov_rey(std::string casilla);
    */
};
