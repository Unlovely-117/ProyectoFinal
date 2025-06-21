#include "ArchivoHistorial.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

ArchivoHistorial::ArchivoHistorial(const std::string& archivo)
    : nombreArchivo(archivo) {}

void ArchivoHistorial::registrar(const std::string& jugador, const std::string& juego, const std::string& resultado, int puntaje) {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de historial.\n";
        return;
    }

    time_t tiempoActual;
    time(&tiempoActual);
    tm* tiempoLocal = localtime(&tiempoActual);

    std::stringstream ssFecha;
    ssFecha << std::put_time(tiempoLocal, "%Y-%m-%d_%H:%M:%S");
    std::string fecha = ssFecha.str();

    archivo << std::put_time(tiempoLocal, "[%Y-%m-%d %H:%M:%S] ") << jugador
            << " Juego: " << juego << " Resultado: " << resultado
            << " Puntaje: " << puntaje << "\n";

    archivo.close();
}

void ArchivoHistorial::guardarHistorial(const std::string& fecha, const std::string& jugador, const std::string& juego, const std::string& resultado, int puntaje) {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (archivo.is_open()) {
        archivo << fecha << " " << jugador << " " << juego << " "
                << resultado << " " << puntaje << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo guardar el historial.\n";
    }
}

void ArchivoHistorial::mostrarHistorial() const {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el historial.\n";
        return;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        std::cout << linea << '\n';
    }
    archivo.close();
}
