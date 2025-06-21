#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
private:
    std::string nombre;
    int puntaje;

public:
    Jugador(const std::string& nombre) : nombre(nombre), puntaje(0) {}
    std::string getNombre() const { return nombre; }
    int getPuntaje() const { return puntaje; }
    void aumentarPuntaje(int puntos) { puntaje += puntos; }
    void reiniciarPuntaje() { puntaje = 0; }
};

#endif