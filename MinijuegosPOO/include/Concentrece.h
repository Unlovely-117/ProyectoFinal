#ifndef CONCENTRECE_H
#define CONCENTRECE_H

#include <vector>
#include <string>

class Concentrece {
public:
    Concentrece(int filas, int columnas);
    void iniciarJuego();
    void mostrarTablero() const;
    bool seleccionarCarta(int fila1, int col1, int fila2, int col2);
    bool juegoTerminado() const;

private:
    int filas;
    int columnas;
    std::vector<std::vector<std::string>> tablero;
    std::vector<std::vector<bool>> descubiertas;

    void mezclarCartas();
};

#endif // CONCENTRECE_H