#include "Juego.h"
#include "Jugador.h"

Juego::Juego(const std::string& nombre, Jugador* jugador)
    : nombre(nombre), jugador(jugador) {}

Juego::~Juego() {}
