#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Cliente {
private:
    string id;
    string nombre;
    vector<string> historialCompras; // IDs de ventas
    double totalGastado;
public:
    Cliente(string _id="", string _nombre="");

    // Getters
    string getId() const;
    string getNombre() const;
    double getTotalGastado() const;
    int getNumeroCompras() const;

    // Setters
    void setNombre(string n);

    // Agregar compra
    void agregarCompra(string idVenta, double monto);

    // Mostrar historial
    void mostrarHistorial() const;

    // Validar si tiene compras
    bool tieneCompras() const;
};

#endif // CLIENTE_H_INCLUDED
