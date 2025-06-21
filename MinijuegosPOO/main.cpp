#include <iostream>
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
    std::cin >> nombre;

    Jugador jugador(nombre);
    ArchivoHistorial historial("historial.txt");

    int opcion = 0;
    while (opcion != 6) {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                Ahorcado ahorcado(&jugador, "palabra");
                ahorcado.iniciar();
                historial.guardarHistorial(jugador.getNombre() + " jugó Ahorcado y obtuvo " + std::to_string(jugador.getPuntaje()) + " puntos");
                break;
            }
            case 2: {
                Concentrece concentrece(&jugador);
                concentrece.iniciar();
                historial.guardarHistorial(jugador.getNombre() + " jugó Concentrece y obtuvo " + std::to_string(jugador.getPuntaje()) + " puntos");
                break;
            }
            case 3:
                std::cout << "\n--- HISTORIAL DE PARTIDAS ---\n";
                historial.mostrarHistorial();
                break;
            case 4:
                std::cout << "\nPuntaje actual de " << jugador.getNombre() << ": " << jugador.getPuntaje() << " puntos.\n";
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
                break;
        }
    }

    return 0;
}
