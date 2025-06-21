#ifndef CONCENTRECE_H
#define CONCENTRECE_H

#include "Juego.h"
#include "Jugador.h"
#include <string>

class Concentrece : public Juego {
private:
    int filas;
    int columnas;
    std::string tablero[6][6]; // máximo 6x6
    bool descubiertas[6][6];

public:
    Concentrece(Jugador* jugador, int filas = 4, int columnas = 4);
    void iniciar();
    void mostrarTablero() const;
};

#endif
