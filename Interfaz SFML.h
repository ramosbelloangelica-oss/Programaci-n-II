#ifndef INTERFAZSFML_H
#define INTERFAZSFML_H
#include "Juego.h"
#include <SFML/Graphics.hpp>

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
    InterfazSFML(Juego& j);
    void ejecutar();
    void dibujarTablero();
    void dibujarPiezas();
    void dibujarTexto();
    void procesarClick(const sf::Event& evento);
};

#endif
