#include "Tablero.h"
#include <cmath>

Tablero::Tablero() {
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            casillas[i][j] = nullptr;
}

Tablero::Tablero(const Tablero& otro) {
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++) {
            if(otro.casillas[i][j]!=nullptr)
                casillas[i][j] = new Pieza(*otro.casillas[i][j]);
            else
                casillas[i][j] = nullptr;
        }
}

Tablero::~Tablero() {
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            delete casillas[i][j];
}

void Tablero::inicializar() {
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++) {
            delete casillas[i][j];
            casillas[i][j] = nullptr;
        }
    for(int i=0;i<3;i++)
        for(int j=0;j<8;j++)
            if((i+j)%2==1) casillas[i][j] = new Pieza(ROJO);
    for(int i=5;i<8;i++)
        for(int j=0;j<8;j++)
            if((i+j)%2==1) casillas[i][j] = new Pieza(NEGRO);
}

Pieza* Tablero::getPieza(int f,int c) const { return casillas[f][c]; }

bool Tablero::moverValido(int f1,int c1,int f2,int c2, Color turno) {
    if(f2<0||f2>=8||c2<0||c2>=8) return false;
    Pieza* p = casillas[f1][c1];
    if(p==nullptr || p->getColor()!=turno) return false;
    if(casillas[f2][c2]!=nullptr) return false;
    int df=f2-f1, dc=c2-c1;
    if(abs(df)==1 && abs(dc)==1) {
        if(p->esDama()) return true;
        if(p->getColor()==ROJO && df==1) return true;
        if(p->getColor()==NEGRO && df==-1) return true;
    }
    if(abs(df)==2 && abs(dc)==2) {
        int midF=(f1+f2)/2, midC=(c1+c2)/2;
        Pieza* medio=casillas[midF][midC];
        if(medio!=nullptr && medio->getColor()!=p->getColor()) return true;
    }
    return false;
}

void Tablero::moverPieza(int f1,int c1,int f2,int c2) {
    Pieza* p=casillas[f1][c1];
    casillas[f2][c2]=p;
    casillas[f1][c1]=nullptr;
    if(abs(f2-f1)==2 && abs(c2-c1)==2) {
        int midF=(f1+f2)/2, midC=(c1+c2)/2;
        delete casillas[midF][midC];
        casillas[midF][midC]=nullptr;
    }
    if(p!=nullptr) {
        if(p->getColor()==ROJO && f2==7) p->coronar();
        if(p->getColor()==NEGRO && f2==0) p->coronar();
    }
}

int Tablero::contarPiezas(Color c) {
    int total=0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(casillas[i][j]!=nullptr && casillas[i][j]->getColor()==c) total++;
    return total;
}
