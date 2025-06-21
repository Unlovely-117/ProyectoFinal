#include "Ahorcado.h"
#include "Jugador.h"
#include "ArchivoHistorial.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <sstream>

Ahorcado::Ahorcado(Jugador* jugador, const std::string& palabra, int maxIntentos)
    : Juego("Ahorcado", jugador), palabraSecreta(palabra), palabraActual(""), cantidadUsadas(0), intentosRestantes(maxIntentos) {
    palabraActual = std::string(palabraSecreta.size(), '_');
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

void Ahorcado::seleccionarPalabra() {
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
}

void Ahorcado::jugarTurno() {
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
        return;
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
    } else std::cout << "Correcto!\n";
}

bool Ahorcado::juegoTerminado() const {
    return intentosRestantes <= 0 || jugadorGano();
}

bool Ahorcado::jugadorGano() const {
    return palabraActual == palabraSecreta;
}

void Ahorcado::iniciar() {
    std::cout << "\n--- AHORCADO ---\n";
    std::cout << "Selecciona modo de juego:\n";
    std::cout << "1. Jugador vs Jugador\n";
    std::cout << "2. Jugador vs CPU (palabras aleatorias)\n";
    int modo;
    std::cin >> modo;
    std::cin.ignore();

    if (modo == 1) {
        std::cout << "Quien ingresa la palabra secreta?\n";
        std::cout << "1. Jugador actual\n";
        std::cout << "2. Otro jugador\n";
        int opcion;
        std::cin >> opcion;
        std::cin.ignore();
        std::string palabra;
        std::cout << "Escribe la palabra secreta: ";
        std::getline(std::cin, palabra);
        palabraSecreta = palabra;
    } else {
        seleccionarPalabra();
    }

    palabraActual = std::string(palabraSecreta.size(), '_');
    cantidadUsadas = 0;
    intentosRestantes = 6;

    while (!juegoTerminado()) {
        jugarTurno();
    }

    ArchivoHistorial historial;
    std::string resultado = jugadorGano() ? "G" : "P";

    if (jugadorGano()) {
        std::cout << "\nGanaste, " << jugador->getNombre() << "!\n";
        jugador->aumentarPuntaje(10);
    } else {
        std::cout << "\nPerdiste. La palabra era: " << palabraSecreta << "\n";
    }

    time_t tiempoActual;
    time(&tiempoActual);
    tm* tiempoLocal = localtime(&tiempoActual);

    std::stringstream ssFecha;
    ssFecha << std::put_time(tiempoLocal, "%Y-%m-%d_%H:%M:%S");
    std::string fecha = ssFecha.str();

    resultado = jugadorGano() ? "G" : "P";
    historial.guardarHistorial(fecha, jugador->getNombre(), "AH", resultado, jugador->getPuntaje());
}
