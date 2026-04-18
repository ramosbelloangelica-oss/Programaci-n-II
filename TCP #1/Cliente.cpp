#include "Cliente.h"

Cliente::Cliente(string _id, string _nombre) : id(_id), nombre(_nombre), totalGastado(0) {}

string Cliente::getId() const { return id; }
string Cliente::getNombre() const { return nombre; }
double Cliente::getTotalGastado() const { return totalGastado; }
int Cliente::getNumeroCompras() const { return historialCompras.size(); }

void Cliente::setNombre(string n) { nombre = n; }

void Cliente::agregarCompra(string idVenta, double monto) {
    historialCompras.push_back(idVenta);
    totalGastado += monto;
}

void Cliente::mostrarHistorial() const {
    cout << "Cliente: " << nombre << " | ID: " << id << endl;
    cout << "Compras registradas: " << historialCompras.size() << endl;
    cout << "Total gastado: " << totalGastado << endl;
}

bool Cliente::tieneCompras() const {
    return !historialCompras.empty();
}
