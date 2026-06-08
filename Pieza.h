#ifndef PIEZA_H
#define PIEZA_H

enum Color { ROJO, NEGRO };

class Pieza {
private:
    Color color;
    bool dama;
public:
    Pieza(Color c);
    Pieza(const Pieza& otra);
    Color getColor() const;
    bool esDama() const;
    void coronar();
};

#endif
