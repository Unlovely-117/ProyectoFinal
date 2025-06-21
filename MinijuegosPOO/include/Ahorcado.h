#ifndef AHORCADO_H
#define AHORCADO_H

#include "Juego.h"
#include <string>

class Ahorcado : public Juego {
private:
    std::string palabraSecreta;
    std::string palabraActual;
    char letrasUsadas[26];
    int cantidadUsadas;
    int intentosRestantes;

    void dibujarAhorcado() const;
    void seleccionarPalabra();
    void jugarTurno();

public:
    Ahorcado(Jugador* jugador, const std::string& palabra = "", int maxIntentos = 6);
    void iniciar() override;
    virtual ~Ahorcado() {}
    bool juegoTerminado() const;
    bool jugadorGano() const;
};

#endif
