#include "Juego.h"

Juego::Juego(Jugador* jr, Jugador* jn)
    : jugadorRojo(jr), jugadorNegro(jn) { reiniciar(); }

void Juego::reiniciar() {
    tablero.inicializar();
    turno = ROJO;
    terminado = false;
    ganador = "";
}

Tablero& Juego::getTablero() { return tablero; }
Color Juego::getTurno() const { return turno; }
void Juego::cambiarTurno() { turno = (turno==ROJO ? NEGRO : ROJO); }
bool Juego::estaTerminado() const { return terminado; }
std::string Juego::getGanador() const { return ganador; }

Jugador* Juego::getJugadorActual() {
    return (turno==ROJO ? jugadorRojo : jugadorNegro);
}

void Juego::verificarVictoria() {
    int rojas = tablero.contarPiezas(ROJO);
    int negras = tablero.contarPiezas(NEGRO);
    if(rojas==0) { terminado=true; ganador="NEGRO"; }
    if(negras==0) { terminado=true; ganador="ROJO"; }
}
