#include "Jugador.h"

Jugador::Jugador(const std::string& nombre, int puntaje)
    : nombre(nombre), puntaje(puntaje) {}

std::string Jugador::getNombre() const {
    return nombre;
}

int Jugador::getPuntaje() const {
    return puntaje;
}

void Jugador::setPuntaje(int nuevoPuntaje) {
    puntaje = nuevoPuntaje;
}

void Jugador::aumentarPuntaje(int cantidad) {
    puntaje += cantidad;
}

void Jugador::reiniciarPuntaje() {
    puntaje = 0;
}
