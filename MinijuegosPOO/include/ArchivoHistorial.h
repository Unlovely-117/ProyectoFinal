#ifndef ARCHIVOHISTORIAL_H
#define ARCHIVOHISTORIAL_H

#include <string>

class ArchivoHistorial {
private:
    std::string nombreArchivo;

public:
    ArchivoHistorial(const std::string& archivo = "historial.txt");
    void guardarHistorial(const std::string& fecha, const std::string& jugador, const std::string& juego, const std::string& resultado, int puntaje);
    void mostarHistrorial() const;
    void registrar(const std::string& jugador, const std::string& juego, const std::string& resultado, int puntaje);
    void mostrarHistorial() const;
};

#endif
