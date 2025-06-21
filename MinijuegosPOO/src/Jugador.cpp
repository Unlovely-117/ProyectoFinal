#include "Jugador.h"

Jugador::Jugador(const std::string& nombre)
    : nombre(nombre), puntaje(0) {}

void Jugador::aumentarPuntaje(int puntos) {
    puntaje += puntos;
}

void Jugador::reiniciarPuntaje() {
    puntaje = 0;
}

int Jugador::getPuntaje() const {
    return puntaje;
}

std::string Jugador::getNombre() const {
    return nombre;
}
