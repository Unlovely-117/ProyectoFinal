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
    void iniciar() override;
    void mostrarTablero() const;
};

#endif

// ===== Concentrece.cpp =====
#include "Concentrece.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Concentrece::Concentrece(Jugador* jugador, int filas, int columnas)
    : Juego("Concentrece", jugador), filas(filas), columnas(columnas) {

    int totalCartas = filas * columnas;
    std::string cartas[36]; // hasta 18 parejas
    int total = 0;

    std::ifstream archivo("parejas.txt");
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir parejas.txt. Usando letras por defecto.\n";
        for (int i = 0; i < totalCartas / 2; ++i) {
            char letra = 'A' + i;
            cartas[total++] = letra;
            cartas[total++] = letra;
        }
    } else {
        std::string linea;
        while (archivo >> linea && total < totalCartas) {
            cartas[total++] = linea;
            cartas[total++] = linea;
        }
        archivo.close();
    }

    srand(time(0));
    for (int i = 0; i < total; ++i) {
        int j = rand() % total;
        std::swap(cartas[i], cartas[j]);
    }

    int index = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (index < total) tablero[i][j] = cartas[index++];
            else tablero[i][j] = "?";
            descubiertas[i][j] = false;
        }
    }
}

void Concentrece::iniciar() {
    std::cout << "\n--- CONCENTRECE ---\n";
    std::cout << "Encuentra las parejas de cartas.\n";

    int parejasEncontradas = 0;
    int totalParejas = (filas * columnas) / 2;

    while (parejasEncontradas < totalParejas) {
        mostrarTablero();
        int f1, c1, f2, c2;
        std::cout << "Ingresa fila y columna de la primera carta: ";
        std::cin >> f1 >> c1;
        std::cout << "Ingresa fila y columna de la segunda carta: ";
        std::cin >> f2 >> c2;

        if (f1 < 0 || f1 >= filas || c1 < 0 || c1 >= columnas ||
            f2 < 0 || f2 >= filas || c2 < 0 || c2 >= columnas ||
            (f1 == f2 && c1 == c2) ||
            descubiertas[f1][c1] || descubiertas[f2][c2]) {
            std::cout << "Movimiento inválido. Intenta nuevamente.\n";
            continue;
        }

        std::cout << "Carta 1: " << tablero[f1][c1] << "\n";
        std::cout << "Carta 2: " << tablero[f2][c2] << "\n";

        if (tablero[f1][c1] == tablero[f2][c2]) {
            std::cout << "¡Pareja encontrada!\n";
            descubiertas[f1][c1] = true;
            descubiertas[f2][c2] = true;
            parejasEncontradas++;
            jugador->aumentarPuntaje(5);
        } else {
            std::cout << "No coinciden.\n";
        }
    }

    std::cout << "\n¡Felicidades, " << jugador->getNombre() << "! Terminaste el juego con "
              << jugador->getPuntaje() << " puntos.\n";
}

void Concentrece::mostrarTablero() const {
    std::cout << "\nTablero:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (descubiertas[i][j]) {
                std::cout << tablero[i][j] << " ";
            } else {
                std::cout << "* ";
            }
        }
        std::cout << std::endl;
    }
}
