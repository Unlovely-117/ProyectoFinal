#include "Ahorcado.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Ahorcado::Ahorcado(Jugador* jugador, const std::string& palabra, int maxIntentos)
    : Juego("Ahorcado", jugador), palabraSecreta(palabra), intentosRestantes(maxIntentos), cantidadUsadas(0) {
    palabraActual = std::string(palabraSecreta.size(), '_');
}

bool Ahorcado::juegoTerminado() const {
    return intentosRestantes <= 0 || jugadorGano();
}

bool Ahorcado::jugadorGano() const {
    return palabraActual == palabraSecreta;
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

    std::cout << "\n--- AHORCADO ---\nAdivina la palabra letra por letra.\n";

    while (!juegoTerminado()) {
        std::cout << "\nPalabra: " << palabraActual << "\n";
        std::cout << "Intentos restantes: " << intentosRestantes << "\n";
        std::cout << "Letras usadas: ";
        for (int i = 0; i < cantidadUsadas; ++i) {
            std::cout << letrasUsadas[i] << " ";
        }
        std::cout << "\nIngresa una letra: ";

        char letra;
        std::cin >> letra;

        bool yaUsada = false;
        for (int i = 0; i < cantidadUsadas; ++i) {
            if (letrasUsadas[i] == letra) {
                yaUsada = true;
                break;
            }
        }
        if (yaUsada) {
            std::cout << "Ya usaste esa letra. Intenta con otra.\n";
            continue;
        }

        letrasUsadas[cantidadUsadas++] = letra;

        bool acierto = false;
        for (size_t i = 0; i < palabraSecreta.size(); ++i) {
            if (palabraSecreta[i] == letra) {
                palabraActual[i] = letra;
                acierto = true;
            }
        }

        if (!acierto) {
            intentosRestantes--;
            std::cout << "Incorrecto.\n";
        } else {
            std::cout << "¡Correcto!\n";
        }
    }

    if (jugadorGano()) {
        std::cout << "\n¡Felicidades, " << jugador->getNombre() << "! Adivinaste la palabra: " << palabraSecreta << "\n";
        jugador->aumentarPuntaje(10);
    } else {
        std::cout << "\nPerdiste. La palabra era: " << palabraSecreta << "\n";
    }
}