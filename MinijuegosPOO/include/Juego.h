#ifndef JUEGO_H
#define JUEGO_H

#include <string>

class Jugador;

class Juego {
protected:
    std::string nombre;
    Jugador* jugador;

public:
    Juego(const std::string& nombre, Jugador* jugador);
    virtual void iniciar() = 0;
    virtual ~Juego();
};

#endif
