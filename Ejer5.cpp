#include <bits/stdc++.h>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;

    bool esBisiesto(int a) {
        return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
    }

    int diasEnMes(int m, int a) {
        if(m == 2) return esBisiesto(a) ? 29 : 28;
        if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }

    bool validar(int d, int m, int a) {
        if(m < 1 || m > 12 || d < 1 || a < 0) return false;
        if(d > diasEnMes(m,a)) return false;
        return true;
    }

public:
    Fecha(int d, int m, int a) {
        while(!validar(d,m,a)) {
            cout << "Fecha invalida, ingrese nuevamente:\n";
            cout << "Dia: "; cin >> d;
            cout << "Mes: "; cin >> m;
            cout << "Anio: "; cin >> a;
        }
        dia = d;
        mes = m;
        anio = a;
    }

    void avanzarUnDia() {
        dia++;
        if(dia > diasEnMes(mes, anio)) {
            dia = 1;
            mes++;
            if(mes > 12) {
                mes = 1;
                anio++;
            }
        }
    }

    int comparar(Fecha otra) {
        if(anio < otra.anio) return -1;
        if(anio > otra.anio) return 1;
        if(mes < otra.mes) return -1;
        if(mes > otra.mes) return 1;
        if(dia < otra.dia) return -1;
        if(dia > otra.dia) return 1;
        return 0;
    }

    void mostrar() {
        cout << dia << "/" << mes << "/" << anio << endl;
    }
};

int main() {
    Fecha f1(31,12,2024); // si es inválida, pedirá datos al usuario
    f1.avanzarUnDia();
    f1.mostrar();

    Fecha f2(1,1,2025);
    cout << "Comparacion: " << f1.comparar(f2) << endl;

    return 0;
}
