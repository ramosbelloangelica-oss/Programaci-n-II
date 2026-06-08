#ifndef TABLERO_H
#define TABLERO_H
#include "Pieza.h"

class Tablero {
private:
    Pieza* casillas[8][8];
public:
    Tablero();
    Tablero(const Tablero& otro);
    ~Tablero();
    void inicializar();
    Pieza* getPieza(int f,int c) const;
    bool moverValido(int f1,int c1,int f2,int c2, Color turno);
    void moverPieza(int f1,int c1,int f2,int c2);
    int contarPiezas(Color c);
};

#endif
