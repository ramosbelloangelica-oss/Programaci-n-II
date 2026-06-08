#include "Jugador.h"
#include "Juego.h"
#include <algorithm>

Jugador::Jugador(Color c) : color(c) {}
Color Jugador::getColor() const { return color; }

JugadorHumano::JugadorHumano(Color c) : Jugador(c) {}
void JugadorHumano::jugar(Juego& juego) {
    // El humano juega desde la interfaz gráfica
}

JugadorCPU::JugadorCPU(Color c) : Jugador(c) {}

int JugadorCPU::evaluar(Tablero& tablero) {
    return tablero.contarPiezas(color) - tablero.contarPiezas(color==ROJO?NEGRO:ROJO);
}

int JugadorCPU::minimax(Tablero& tablero, int profundidad, bool maximizando) {
    if(profundidad==0) return evaluar(tablero);
    Color turnoActual = maximizando ? color : (color==ROJO?NEGRO:ROJO);
    int mejorValor = maximizando ? -9999 : 9999;

    for(int f=0; f<8; f++) {
        for(int c=0; c<8; c++) {
            Pieza* p = tablero.getPieza(f,c);
            if(p!=nullptr && p->getColor()==turnoActual) {
                for(int df=-2; df<=2; df++) {
                    for(int dc=-2; dc<=2; dc++) {
                        int nf=f+df, nc=c+dc;
                        if(tablero.moverValido(f,c,nf,nc,turnoActual)) {
                            Tablero copia(tablero);
                            copia.moverPieza(f,c,nf,nc);
                            int valor=minimax(copia,profundidad-1,!maximizando);
                            if(maximizando) mejorValor=std::max(mejorValor,valor);
                            else mejorValor=std::min(mejorValor,valor);
                        }
                    }
                }
            }
        }
    }
    return mejorValor;
}

void JugadorCPU::jugar(Juego& juego) {
    int mejorScore=-9999;
    int mejorF1=0, mejorC1=0, mejorF2=0, mejorC2=0;
    Tablero& tablero=juego.getTablero();

    for(int f=0; f<8; f++) {
        for(int c=0; c<8; c++) {
            Pieza* p=tablero.getPieza(f,c);
            if(p!=nullptr && p->getColor()==color) {
                for(int df=-2; df<=2; df++) {
                    for(int dc=-2; dc<=2; dc++) {
                        int nf=f+df, nc=c+dc;
                        if(tablero.moverValido(f,c,nf,nc,color)) {
                            Tablero copia(tablero);
                            copia.moverPieza(f,c,nf,nc);
                            int score=minimax(copia,2,false);
                            if(score>mejorScore) {
                                mejorScore=score;
                                mejorF1=f; mejorC1=c; mejorF2=nf; mejorC2=nc;
                            }
                        }
                    }
                }
            }
        }
    }

    if(mejorScore!=-9999) {
        tablero.moverPieza(mejorF1,mejorC1,mejorF2,mejorC2);
        juego.verificarVictoria();
        if(!juego.estaTerminado()) juego.cambiarTurno();
    }
}
