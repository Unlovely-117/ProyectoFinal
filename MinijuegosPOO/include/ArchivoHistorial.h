#ifndef ARCHIVOHISTORIAL_H
#define ARCHIVOHISTORIAL_H

#include <string>
#include <fstream>
#include <iostream>

class ArchivoHistorial {
private:
    std::string nombreArchivo;

public:
    ArchivoHistorial(const std::string& archivo) : nombreArchivo(archivo) {}

    void guardarHistorial(const std::string& linea) {
        std::ofstream archivo(nombreArchivo, std::ios::app);
        if (archivo.is_open()) {
            archivo << linea << std::endl;
            archivo.close();
        } else {
            std::cerr << "Error al guardar en el historial." << std::endl;
        }
    }

    void mostrarHistorial() const {
        std::ifstream archivo(nombreArchivo);
        std::string linea;
        while (getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        archivo.close();
    }
};

#endif
