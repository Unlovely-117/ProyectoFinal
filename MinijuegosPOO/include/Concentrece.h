#ifndef CONCENTRECE_H
#define CONCENTRECE_H

#include "Juego.h"
#include "Jugador.h"
#include <string>

class Concentrece : public Juego {
private:
    int filas;
    int columnas;
    std::string tablero[6][6];       // Máximo tablero 6x6
    bool descubiertas[6][6];         // Indica qué cartas están descubiertas

public:
    Concentrece(Jugador* jugador, int filas = 4, int columnas = 4);  // Constructor
    void iniciar() override;                                         // Inicia el juego
    void mostrarTablero() const;                                     // Muestra el tablero actual
};

#endif // CONCENTRECE_H
