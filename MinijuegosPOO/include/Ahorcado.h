#ifndef AHORCADO_H
#define AHORCADO_H

#include <string>
#include <vector>

class Ahorcado {
private:
    std::string palabraSecreta;
    std::string palabraActual;
    std::vector<char> letrasUsadas;
    int intentosRestantes;

public:
    Ahorcado(const std::string& palabra, int maxIntentos);
    bool adivinarLetra(char letra);
    bool juegoTerminado() const;
    bool jugadorGano() const;
    std::string obtenerPalabraActual() const;
    int obtenerIntentosRestantes() const;
    std::vector<char> obtenerLetrasUsadas() const;
};

#endif // AHORCADO_H