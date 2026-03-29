#include <bits/stdc++.h>
using namespace std;

class Estudiante {
public:
    string nombre;
    string carnet;
    vector<int> notas;


    Estudiante(string n, string c) {
        nombre = n;
        carnet = c;
    }


    void agregarNota(int nota) {
        if(nota >= 0 && nota <= 100) {
            notas.push_back(nota);
        } else {
            cout << "Error" << endl;
        }
    }


    double promedio() {
        if(notas.empty()) return 0;
        int suma = 0;
        for(int i = 0; i < notas.size(); i++) {
            suma += notas[i];
        }
        return (double)suma / notas.size();
    }
};

int main() {

    Estudiante est("Angelica Ramos", "A2026");

    est.agregarNota(90);
    est.agregarNota(75);
    est.agregarNota(88);

    cout << "Estudiante: " << est.nombre << endl;
    cout << "Carnet: " << est.carnet << endl;
    cout << "Promedio: " << est.promedio() << endl;

    return 0;
}
