#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include "Jugador.h"

class Juego {
protected:
    std::string nombre;
    Jugador* jugador;

public:
    Juego(const std::string& nombre, Jugador* jugador) : nombre(nombre), jugador(jugador) {}
    virtual void iniciar() = 0;
    virtual ~Juego() = default;
};

#endif