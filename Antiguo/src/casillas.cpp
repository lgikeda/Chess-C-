#pragma
#include "casillas.h"

casillas::casillas() {
    // mapa con las coordenadas cartesianas correspondientes a cada casilla del tablero
    char letra = 'a';
    for (int x = 5; x < 85; x += 10) {
        for (int y = 5; y < 85; y += 10) {
            std::string coordenada = std::string(1, letra) + std::to_string((y - 5) / 10 + 1);
            mapaCoordenadas[coordenada] = { x, y };
        }
        letra++;
    }
}

std::pair<int, int> casillas::ajedrez_cartesianas(std::string coordenada) {
    return mapaCoordenadas[coordenada];
}

std::string casillas::cartesianas_ajedrez(int& x, int& y) {
    for (const auto& par : mapaCoordenadas) {
        if (par.second == std::make_pair(x, y)) {
            return par.first;
        }
    }
    return "";
}