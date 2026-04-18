#include "Empleado.h"

Empleado::Empleado(string _id, string _nombre, string _cargo, double _salario)
    : id(_id), nombre(_nombre), cargo(_cargo), salario(_salario) {}

string Empleado::getId() const { return id; }
string Empleado::getNombre() const { return nombre; }
string Empleado::getCargo() const { return cargo; }
double Empleado::getSalario() const { return salario; }

void Empleado::setNombre(string n) { nombre = n; }
void Empleado::setCargo(string c) { cargo = c; }
void Empleado::setSalario(double s) { salario = s; }

void Empleado::mostrarInfo() const {
    cout << "Empleado: " << nombre
         << " | ID: " << id
         << " | Cargo: " << cargo
         << " | Salario: " << salario << endl;
}
