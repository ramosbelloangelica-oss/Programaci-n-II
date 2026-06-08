#ifndef JUGADOR_H
#define JUGADOR_H
#include "Tablero.h"

class Juego; // declaración adelantada

class Jugador {
protected:
    Color color;
public:
    Jugador(Color c);
    virtual void jugar(Juego& juego) = 0;
    Color getColor() const;
};

class JugadorHumano : public Jugador {
public:
    JugadorHumano(Color c);
    void jugar(Juego& juego) override;
};

class JugadorCPU : public Jugador {
private:
    int evaluar(Tablero& tablero);
    int minimax(Tablero& tablero, int profundidad, bool maximizando);
public:
    JugadorCPU(Color c);
    void jugar(Juego& juego) override;
};

#endif
