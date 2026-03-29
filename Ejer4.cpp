#include <bits/stdc++.h>
using namespace std;

class Fraccion {
private:
    int num;
    int den;

    int mcd(int a, int b) {
        while(b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    void simplificar() {
        int divisor = mcd(abs(num), abs(den));
        num /= divisor;
        den /= divisor;
        if(den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Fraccion(int n, int d) {
        if(d == 0) {
            cout << "Error: denominador no puede ser cero\n";
            exit(1);
        }
        num = n;
        den = d;
        simplificar();
    }

    Fraccion sumar(Fraccion otra) {
        int n = num  otra.den + otra.num  den;
        int d = den * otra.den;
        return Fraccion(n, d);
    }

    Fraccion restar(Fraccion otra) {
        int n = num  otra.den - otra.num  den;
        int d = den * otra.den;
        return Fraccion(n, d);
    }

    Fraccion multiplicar(Fraccion otra) {
        return Fraccion(num  otra.num, den  otra.den);
    }

    Fraccion dividir(Fraccion otra) {
        return Fraccion(num  otra.den, den  otra.num);
    }

    double valorReal() {
        return (double)num / den;
    }

    void mostrar() {
        cout << num << "/" << den;
    }
};

int main() {
    Fraccion f1(2, 4);
    Fraccion f2(3, 6);

    Fraccion suma = f1.sumar(f2);
    cout << "Suma: "; suma.mostrar(); cout << " = " << suma.valorReal() << endl;

    Fraccion resta = f1.restar(f2);
    cout << "Resta: "; resta.mostrar(); cout << " = " << resta.valorReal() << endl;

    Fraccion prod = f1.multiplicar(f2);
    cout << "Producto: "; prod.mostrar(); cout << " = " << prod.valorReal() << endl;

    Fraccion div = f1.dividir(f2);
    cout << "Division: "; div.mostrar(); cout << " = " << div.valorReal() << endl;

    return 0;
}
