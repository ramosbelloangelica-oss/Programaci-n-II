#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"
#include "Jugador.h"
#include <string>

class Juego {
private:
    Tablero tablero;
    Color turno;
    bool terminado;
    std::string ganador;
    Jugador* jugadorRojo;
    Jugador* jugadorNegro;
public:
    Juego(Jugador* jr, Jugador* jn);
    void reiniciar();
    Tablero& getTablero();
    Color getTurno() const;
    void cambiarTurno();
    bool estaTerminado() const;
    std::string getGanador() const;
    Jugador* getJugadorActual();
    void verificarVictoria();
};

#endif
