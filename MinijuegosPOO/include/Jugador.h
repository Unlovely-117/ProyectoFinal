#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
private:
    std::string nombre;
    int puntaje;

public:
    Jugador(const std::string& nombre);
    std::string getNombre() const;
    int getPuntaje() const;
    void aumentarPuntaje(int puntos);
    void reiniciarPuntaje();
};

#endif
