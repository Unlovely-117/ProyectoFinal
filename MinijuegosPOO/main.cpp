#include <iostream>
#include <string>
#include "Jugador.h"
#include "Ahorcado.h"
#include "Concentrece.h"
#include "ArchivoHistorial.h"

void mostrarMenu() {
    std::cout << "\n==============================\n";
    std::cout << "     MENU DE MINI JUEGOS\n";
    std::cout << "==============================\n";
    std::cout << "1. Jugar Ahorcado\n";
    std::cout << "2. Jugar Concentrece\n";
    std::cout << "3. Ver Historial\n";
    std::cout << "4. Ver Puntaje Actual\n";
    std::cout << "5. Reiniciar Puntaje\n";
    std::cout << "6. Salir\n";
    std::cout << "==============================\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    std::string nombre;
    std::cout << "Ingresa tu nombre: ";
    std::getline(std::cin, nombre);

    Jugador jugador(nombre);
    ArchivoHistorial historial("historial.txt");

    int opcion = 0;
    while (opcion != 6) {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(); // para limpiar el buffer

        switch (opcion) {
            case 1: {
                Ahorcado ahorcado(&jugador, "default"); // "default" será reemplazada por palabra aleatoria del archivo
                ahorcado.iniciar();
                historial.guardarHistorial(jugador.getNombre() + " jugó Ahorcado y obtuvo " +
                                           std::to_string(jugador.getPuntaje()) + " puntos.");
                break;
            }
            case 2: {
                Concentrece concentrece(&jugador, 4, 4); // tablero 4x4
                concentrece.iniciar();
                historial.guardarHistorial(jugador.getNombre() + " jugó Concentrece y obtuvo " +
                                           std::to_string(jugador.getPuntaje()) + " puntos.");
                break;
            }
            case 3:
                std::cout << "\n--- HISTORIAL DE PARTIDAS ---\n";
                historial.mostrarHistorial();
                break;
            case 4:
                std::cout << "\nPuntaje actual de " << jugador.getNombre() << ": "
                          << jugador.getPuntaje() << " puntos.\n";
                break;
            case 5:
                jugador.reiniciarPuntaje();
                std::cout << "Puntaje reiniciado correctamente.\n";
                break;
            case 6:
                std::cout << "Gracias por jugar, " << jugador.getNombre() << ". ¡Hasta la próxima!\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    }

    return 0;
}
