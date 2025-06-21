#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
private:
    std::string nombre;
    int puntaje;

public:
    Jugador(const std::string& nombre, int puntaje = 0);
    std::string getNombre() const;
    int getPuntaje() const;
    void setPuntaje(int nuevoPuntaje);
    void aumentarPuntaje(int cantidad);
    void reiniciarPuntaje();
};

#endif
