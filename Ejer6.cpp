#include <bits/stdc++.h>
using namespace std;

class Punto {
public:
    double x, y;
    Punto(double px, double py) {
        x = px;
        y = py;
    }
};

class Circulo {
private:
    Punto centro;
    double radio;
public:
    Circulo(Punto c, double r) : centro(c), radio(r) {
        if(r <= 0) {
            cout << "Error: radio invalido\n";
            exit(1);
        }
    }
    double area() {
        return M_PI  radio  radio;
    }
    double perimetro() {
        return 2  M_PI  radio;
    }
    bool contienePunto(Punto p) {
        double dx = p.x - centro.x;
        double dy = p.y - centro.y;
        double distancia = sqrt(dxdx + dydy);
        return distancia <= radio;
    }
    void mostrar() {
        cout << "Centro: (" << centro.x << "," << centro.y << ") Radio: " << radio << endl;
    }
};

int main() {
    Punto p1(0,0);
    Circulo c1(p1, 5);
    cout << "Area: " << c1.area() << endl;
    cout << "Perimetro: " << c1.perimetro() << endl;
    Punto p2(3,4);
    if(c1.contienePunto(p2)) {
        cout << "El punto esta dentro del circulo\n";
    } else {
        cout << "El punto esta fuera del circulo\n";
    }
    return 0;
}
