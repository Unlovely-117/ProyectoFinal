#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include "Jugador.h"

class Juego {
protected:
    std::string nombreJuego;
    Jugador* jugador;

public:
    Juego(const std::string& nombreJuego, Jugador* jugador);
    virtual void iniciar() = 0;
    std::string getNombreJuego() const;
    Jugador* getJugador() const;
    virtual ~Juego() {}
};

#endif
