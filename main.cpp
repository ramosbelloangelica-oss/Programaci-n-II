#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

enum Color { ROJO, NEGRO };

// -------------------- PIEZA --------------------
class Pieza {
private:
    Color color;
    bool dama;
public:
    Pieza(Color c) : color(c), dama(false) {}
    Pieza(const Pieza& otra) : color(otra.color), dama(otra.dama) {} // copia segura
    Color getColor() const { return color; }
    bool esDama() const { return dama; }
    void coronar() { dama = true; }
};

// -------------------- TABLERO --------------------
class Tablero {
private:
    Pieza* casillas[8][8];
public:
    Tablero() {
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                casillas[i][j] = nullptr;
    }

    // Constructor de copia profundo
    Tablero(const Tablero& otro) {
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                if(otro.casillas[i][j]!=nullptr)
                    casillas[i][j] = new Pieza(*otro.casillas[i][j]);
                else
                    casillas[i][j] = nullptr;
            }
        }
    }

    ~Tablero() {
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                delete casillas[i][j];
    }

    void inicializar() {
        // limpiar antes de inicializar
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++) {
                delete casillas[i][j];
                casillas[i][j] = nullptr;
            }

        for(int i=0;i<3;i++) {
            for(int j=0;j<8;j++) {
                if((i+j)%2==1) casillas[i][j] = new Pieza(ROJO);
            }
        }
        for(int i=5;i<8;i++) {
            for(int j=0;j<8;j++) {
                if((i+j)%2==1) casillas[i][j] = new Pieza(NEGRO);
            }
        }
    }

    Pieza* getPieza(int f,int c) const { return casillas[f][c]; }

    bool moverValido(int f1,int c1,int f2,int c2, Color turno) {
        if(f2<0||f2>=8||c2<0||c2>=8) return false;
        Pieza* p = casillas[f1][c1];
        if(p==nullptr || p->getColor()!=turno) return false;
        if(casillas[f2][c2]!=nullptr) return false;

        int df = f2-f1;
        int dc = c2-c1;

        // Movimiento simple
        if(abs(df)==1 && abs(dc)==1) {
            if(p->getColor()==ROJO && (df==1 || p->esDama())) return true;
            if(p->getColor()==NEGRO && (df==-1 || p->esDama())) return true;
        }

        // Captura
        if(abs(df)==2 && abs(dc)==2) {
            int midF = (f1+f2)/2;
            int midC = (c1+c2)/2;
            Pieza* medio = casillas[midF][midC];
            if(medio!=nullptr && medio->getColor()!=p->getColor()) return true;
        }
        return false;
    }

    void moverPieza(int f1,int c1,int f2,int c2) {
        Pieza* p = casillas[f1][c1];
        casillas[f2][c2] = p;
        casillas[f1][c1] = nullptr;

        // Captura
        if(abs(f2-f1)==2 && abs(c2-c1)==2) {
            int midF = (f1+f2)/2;
            int midC = (c1+c2)/2;
            delete casillas[midF][midC];
            casillas[midF][midC] = nullptr;
        }

        // Coronación
        if(p!=nullptr) {
            if(p->getColor()==ROJO && f2==7) p->coronar();
            if(p->getColor()==NEGRO && f2==0) p->coronar();
        }
    }

    int contarPiezas(Color c) {
        int total=0;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(casillas[i][j]!=nullptr && casillas[i][j]->getColor()==c) total++;
        return total;
    }
};
// -------------------- JUGADOR --------------------
class Juego; // declaración adelantada

class Jugador {
protected:
    Color color;
public:
    Jugador(Color c) : color(c) {}
    virtual void jugar(Juego& juego) = 0;
    Color getColor() const { return color; }
};

// -------------------- JUGADOR HUMANO --------------------
class JugadorHumano : public Jugador {
public:
    JugadorHumano(Color c) : Jugador(c) {}
    void jugar(Juego& juego) override {
        // El humano juega desde la interfaz gráfica
    }
};

// -------------------- JUGADOR CPU --------------------
class JugadorCPU : public Jugador {
private:
    int evaluar(Tablero& tablero);
    int minimax(Tablero& tablero, int profundidad, bool maximizando);
public:
    JugadorCPU(Color c) : Jugador(c) {}
    void jugar(Juego& juego) override; // implementación vendrá después
};
// -------------------- JUEGO --------------------
class Juego {
private:
    Tablero tablero;
    Color turno;
    bool terminado;
    std::string ganador;
    Jugador* jugadorRojo;
    Jugador* jugadorNegro;
public:
    Juego(Jugador* jr, Jugador* jn)
        : jugadorRojo(jr), jugadorNegro(jn) { reiniciar(); }

    void reiniciar() {
        tablero.inicializar();
        turno = ROJO;
        terminado = false;
        ganador = "";
    }

    Tablero& getTablero() { return tablero; }
    Color getTurno() const { return turno; }
    void cambiarTurno() { turno = (turno==ROJO ? NEGRO : ROJO); }
    bool estaTerminado() const { return terminado; }
    std::string getGanador() const { return ganador; }

    Jugador* getJugadorActual() {
        return (turno==ROJO ? jugadorRojo : jugadorNegro);
    }

    void verificarVictoria() {
        int rojas = tablero.contarPiezas(ROJO);
        int negras = tablero.contarPiezas(NEGRO);
        if(rojas==0) { terminado=true; ganador="NEGRO"; }
        if(negras==0) { terminado=true; ganador="ROJO"; }
    }
};
// -------------------- IMPLEMENTACIÓN DE JUGADORCPU --------------------
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

// -------------------- INTERFAZ SFML --------------------
class InterfazSFML {
private:
    Juego& juego;
    sf::RenderWindow ventana;
    bool seleccionado;
    int origenFila, origenCol;

    sf::Font fuente;
    sf::Text textoTurno;
    sf::Text textoInfo;

public:
    InterfazSFML(Juego& j)
        : juego(j), ventana(sf::VideoMode(800,800),"Juego de Damas"),
          seleccionado(false), origenFila(-1), origenCol(-1)
    {
        if(!fuente.loadFromFile("arial.ttf")) {
            std::cout << "No se pudo cargar la fuente.\n";
        }
        textoTurno.setFont(fuente);
        textoTurno.setCharacterSize(24);
        textoTurno.setFillColor(sf::Color::Black);
        textoTurno.setPosition(10, 760);

        textoInfo.setFont(fuente);
        textoInfo.setCharacterSize(20);
        textoInfo.setFillColor(sf::Color::Black);
        textoInfo.setPosition(400, 760);
    }

    void ejecutar() {
        while(ventana.isOpen()) {
            sf::Event evento;
            while(ventana.pollEvent(evento)) {
                if(evento.type==sf::Event::Closed) ventana.close();
                if(evento.type==sf::Event::MouseButtonPressed) procesarClick(evento);
            }

            Jugador* actual = juego.getJugadorActual();
            if(dynamic_cast<JugadorCPU*>(actual)!=nullptr && !juego.estaTerminado()) {
                actual->jugar(juego);
            }

            ventana.clear(sf::Color::White);
            dibujarTablero();
            dibujarPiezas();
            dibujarTexto();
            ventana.display();
        }
    }

    void dibujarTablero() {
        sf::RectangleShape cuadro(sf::Vector2f(100,100));
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                if((i+j)%2==0) cuadro.setFillColor(sf::Color(240,240,240));
                else cuadro.setFillColor(sf::Color(50,50,50));
                cuadro.setPosition(j*100,i*100);
                ventana.draw(cuadro);
            }
        }
    }

    void dibujarPiezas() {
        sf::CircleShape ficha(40);
        ficha.setOrigin(40,40);
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                Pieza* p=juego.getTablero().getPieza(i,j);
                if(p!=nullptr) {
                    if(p->getColor()==ROJO) ficha.setFillColor(sf::Color::Red);
                    else ficha.setFillColor(sf::Color::Blue);
                    ficha.setPosition(j*100+50,i*100+50);
                    ventana.draw(ficha);

                    if(p->esDama()) {
                        sf::CircleShape corona(40);
                        corona.setOrigin(40,40);
                        corona.setPosition(j*100+50,i*100+50);
                        corona.setFillColor(sf::Color::Transparent);
                        corona.setOutlineThickness(5);
                        corona.setOutlineColor(sf::Color::Yellow);
                        ventana.draw(corona);
                    }
                }
            }
        }
    }

    void dibujarTexto() {
        if(juego.estaTerminado()) {
            textoTurno.setString("Juego terminado. Ganador: " + juego.getGanador());
        } else {
            if(juego.getTurno()==ROJO) textoTurno.setString("Turno: ROJO");
            else textoTurno.setString("Turno: NEGRO");
        }
        ventana.draw(textoTurno);

        if(!juego.estaTerminado() && dynamic_cast<JugadorHumano*>(juego.getJugadorActual())!=nullptr) {
            textoInfo.setString("Haz clic en una pieza y luego en la casilla destino");
            ventana.draw(textoInfo);
        }
    }

    void procesarClick(const sf::Event& evento) {
        int fila=evento.mouseButton.y/100;
        int col=evento.mouseButton.x/100;
        if(fila<0||fila>=8||col<0||col>=8) return;

        Jugador* actual = juego.getJugadorActual();
        if(dynamic_cast<JugadorHumano*>(actual)==nullptr) return;

        if(!seleccionado) {
            Pieza* p=juego.getTablero().getPieza(fila,col);
            if(p!=nullptr && p->getColor()==juego.getTurno()) {
                origenFila=fila; origenCol=col; seleccionado=true;
            }
        } else {
            if(juego.getTablero().moverValido(origenFila,origenCol,fila,col,juego.getTurno())) {
                juego.getTablero().moverPieza(origenFila,origenCol,fila,col);
                juego.verificarVictoria();
                if(!juego.estaTerminado()) juego.cambiarTurno();
            }
            seleccionado=false;
        }
    }
};

// -------------------- MAIN --------------------
int main() {
    JugadorHumano jugadorHumano(ROJO);
    JugadorCPU jugadorCPU(NEGRO);

    Juego juego(&jugadorHumano, &jugadorCPU);
    InterfazSFML interfaz(juego);

    interfaz.ejecutar();
    return 0;
}
