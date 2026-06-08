#include "InterfazSFML.h"
#include <iostream>

InterfazSFML::InterfazSFML(Juego& j)
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

void InterfazSFML::ejecutar() {
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

void InterfazSFML::dibujarTablero() {
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

void InterfazSFML::dibujarPiezas() {
    sf::CircleShape ficha(40);
    ficha.setOrigin(40,40);
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            Pieza* p=juego.get
