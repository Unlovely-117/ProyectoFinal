#ifndef CONCENTRECE_H
#define CONCENTRECE_H

#include "Juego.h"
#include <string>

class Concentrece : public Juego {
private:
    int filas;
    int columnas;
    std::string tablero[6][6];      // máximo tablero 6x6
    bool descubiertas[6][6];        // si la carta está descubierta

    void cargarCartas();
    void mezclarCartas(std::string cartas[], int total);
    void mostrarTablero() const;
    void jugarTurno(int& parejasEncontradas);

public:
    Concentrece(Jugador* jugador, int filas = 4, int columnas = 4);
    void iniciar() override;
};

#endif
