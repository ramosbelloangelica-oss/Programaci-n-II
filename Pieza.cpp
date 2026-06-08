#include "Pieza.h"

Pieza::Pieza(Color c) : color(c), dama(false) {}
Pieza::Pieza(const Pieza& otra) : color(otra.color), dama(otra.dama) {}
Color Pieza::getColor() const { return color; }
bool Pieza::esDama() const { return dama; }
void Pieza::coronar() { dama = true; }
