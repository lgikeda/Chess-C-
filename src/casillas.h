#pragma once
#include <map>
#include<string>

class casillas {
    friend class select_pieza;
public:
    casillas();
    std::pair<int, int> ajedrez_cartesianas(std::string coordenada);
    std::string cartesianas_ajedrez(int& x, int& y);

private:
    std::map<std::string, std::pair<int, int>> mapaCoordenadas;
};