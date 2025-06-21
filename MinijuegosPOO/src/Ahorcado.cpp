#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Ahorcado.h"

Ahorcado::Ahorcado(Jugador* jugador, const std::string& palabra, int maxIntentos)
    : Juego("Ahorcado", jugador), palabraSecreta(palabra), palabraActual(""), cantidadUsadas(0), intentosRestantes(maxIntentos) {
    palabraActual = std::string(palabraSecreta.size(), '_');
}

bool Ahorcado::juegoTerminado() const {
    return intentosRestantes <= 0 || jugadorGano();
}

bool Ahorcado::jugadorGano() const {
    return palabraActual == palabraSecreta;
}

void Ahorcado::dibujarAhorcado() const {
    int estado = 6 - intentosRestantes;
    const std::string partes[7] = {
        " +---+\n |   |\n     |\n     |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n     |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n |   |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n/|   |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n/|\\  |\n     |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n/|\\  |\n/    |\n     |\n=======\n",
        " +---+\n |   |\n O   |\n/|\\  |\n/ \\  |\n     |\n=======\n"
    };
    std::cout << partes[estado];
}

void Ahorcado::iniciar() {
    std::ifstream archivo("palabras.txt");
    std::string palabras[100];
    int total = 0;
    std::string linea;
    while (archivo >> linea && total < 100) {
        palabras[total++] = linea;
    }
    archivo.close();

    if (total > 0) {
        srand(time(0));
        palabraSecreta = palabras[rand() % total];
        palabraActual = std::string(palabraSecreta.size(), '_');
    }

    std::cout << "\n--- AHORCADO ---\n";

    while (!juegoTerminado()) {
        dibujarAhorcado();
        std::cout << "\nPalabra: " << palabraActual << "\nIntentos restantes: " << intentosRestantes << "\nLetras usadas: ";
        for (int i = 0; i < cantidadUsadas; ++i) std::cout << letrasUsadas[i] << " ";
        std::cout << "\nIngresa una letra: ";

        char letra;
        std::cin >> letra;

        bool yaUsada = false;
        for (int i = 0; i < cantidadUsadas; ++i)
            if (letrasUsadas[i] == letra) yaUsada = true;
        if (yaUsada) {
            std::cout << "Ya usaste esa letra.\n";
            continue;
        }

        letrasUsadas[cantidadUsadas++] = letra;
        bool acierto = false;
        for (size_t i = 0; i < palabraSecreta.size(); ++i)
            if (palabraSecreta[i] == letra) {
                palabraActual[i] = letra;
                acierto = true;
            }

        if (!acierto) {
            intentosRestantes--;
            std::cout << "Incorrecto.\n";
        } else std::cout << "¡Correcto!\n";
    }

    if (jugadorGano()) {
        std::cout << "\n¡Ganaste, " << jugador->getNombre() << "!\n";
        jugador->aumentarPuntaje(10);
    } else {
        std::cout << "\nPerdiste. La palabra era: " << palabraSecreta << "\n";
    }
}