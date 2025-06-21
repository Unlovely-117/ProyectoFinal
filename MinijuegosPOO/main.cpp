#include <iostream>
#include <string>
#include "Jugador.h"
#include "Ahorcado.h"
#include "Concentrece.h"
#include "ArchivoHistorial.h"

void mostrarIntroduccion() {
    std::cout << "=============================================\n";
    std::cout << "     Bienvenido al sistema de minijuegos     \n";
    std::cout << "=============================================\n";
    std::cout << "Aqui podras jugar dos clasicos juegos:\n";
    std::cout << " 1. Ahorcado: Adivina la palabra secreta antes de quedarte sin intentos.\n";
    std::cout << "    - Modo jugador vs jugador o jugador vs CPU\n";
    std::cout << "    - Palabras cargadas desde archivo\n";
    std::cout << "    - Control de intentos fallidos\n";
    std::cout << "\n";
    std::cout << " 2. Concentrece (Memoria): Encuentra todas las parejas escondidas en el tablero.\n";
    std::cout << "    - Simbolos cargados desde archivo\n";
    std::cout << "    - Juega solo y mejora tu memoria visual\n";
    std::cout << "\n";
    std::cout << "  Cada partida que juegues quedara registrada con tu nombre, puntaje, fecha\n";
    std::cout << "    y si ganaste o perdiste. Aumenta tu historial y supera tu record.\n";
    std::cout << "=============================================\n\n";
}

void mostrarMenu() {
    std::cout << "\n===== MENU PRINCIPAL =====\n";
    std::cout << "1. Jugar Ahorcado\n";
    std::cout << "2. Jugar Concentrece\n";
    std::cout << "3. Ver historial\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    std::string nombreJugador;
    std::cout << "Ingrese su nombre: ";
    std::getline(std::cin, nombreJugador);

    mostrarIntroduccion();

    Jugador* jugador = new Jugador(nombreJugador);
    ArchivoHistorial historial("historial.txt");

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(); // limpiar buffer

        switch (opcion) {
            case 1: {
                jugador->reiniciarPuntaje();
                Juego* juego = new Ahorcado(jugador);
                juego->iniciar();
                delete juego;
                break;
            }
            case 2: {
                jugador->reiniciarPuntaje();
                Juego* juego = new Concentrece(jugador);
                juego->iniciar();
                delete juego;
                break;
            }
            case 3:
                historial.mostrarHistorial();
                break;
            case 4:
                std::cout << "Gracias por jugar. Hasta pronto!\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente nuevamente.\n";
        }
    } while (opcion != 4);

    delete jugador;
    return 0;
}

