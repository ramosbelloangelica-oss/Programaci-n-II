#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Empleado {
private:
    string id;
    string nombre;
    string cargo;
    double salario;
public:
    Empleado(string _id="", string _nombre="", string _cargo="", double _salario=0);

    // Getters
    string getId() const;
    string getNombre() const;
    string getCargo() const;
    double getSalario() const;

    // Setters
    void setNombre(string n);
    void setCargo(string c);
    void setSalario(double s);

    // Mostrar información completa
    void mostrarInfo() const;
};

#endif // EMPLEADO_H_INCLUDED
