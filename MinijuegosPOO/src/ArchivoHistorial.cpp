#include "ArchivoHistorial.h"
#include <fstream>
#include <iostream>

ArchivoHistorial::ArchivoHistorial(const std::string& nombreArchivo)
    : nombreArchivo(nombreArchivo) {}

void ArchivoHistorial::guardarHistorial(const std::string& entrada) {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (archivo.is_open()) {
        archivo << entrada << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo de historial.\n";
    }
}

void ArchivoHistorial::mostrarHistorial() const {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo leer el historial.\n";
    }
}
