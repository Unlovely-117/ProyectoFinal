#ifndef ARCHIVO_HISTORIAL_H
#define ARCHIVO_HISTORIAL_H

#include <string>

class ArchivoHistorial {
private:
    std::string nombreArchivo;

public:
    ArchivoHistorial(const std::string& nombreArchivo);
    bool guardarHistorial(const std::string historial) const;
    void mostrarHistorial() const;
};

#endif
