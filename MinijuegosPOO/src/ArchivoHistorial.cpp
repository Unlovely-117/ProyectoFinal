#include "ArchivoHistorial.h"
#include <fstream>
#include <iostream>
#include <ctime>

ArchivoHistorial::ArchivoHistorial(const std::string& nombreArchivo)
    : nombreArchivo(nombreArchivo) {}

bool ArchivoHistorial::guardarHistorial(const std::string historial) const {
    std::ofstream archivo(nombreArchivo.c_str(), std::ios::app);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo para escribir el historial.\n";
        return false;
    }

    time_t ahora = time(0);
    char* fechaHora = ctime(&ahora);
    if (fechaHora) {
        for (int i = 0; fechaHora[i]; ++i) {
            if (fechaHora[i] == '\n') fechaHora[i] = '\0';
        }
    }

    archivo << "[" << fechaHora << "] " << historial << "\n";
    archivo.close();
    return true;
}

void ArchivoHistorial::mostrarHistorial() const {
    std::ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo para leer el historial.\n";
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::cout << linea << "\n";
    }

    archivo.close();
}
