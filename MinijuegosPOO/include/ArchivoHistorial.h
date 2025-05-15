#ifndef ARCHIVO_HISTORIAL_H
#define ARCHIVO_HISTORIAL_H

#include <string>
#include <vector>

class ArchivoHistorial {
public:
    ArchivoHistorial(const std::string& nombreArchivo);

    bool guardarHistorial(const std::vector<std::string>& historial) const;
    std::vector<std::string> cargarHistorial() const;

private:
    std::string nombreArchivo;
};

#endif // ARCHIVO_HISTORIAL_H