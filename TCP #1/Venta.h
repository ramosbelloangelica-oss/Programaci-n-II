#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include "Producto.h"
using namespace std;

class Venta {
private:
    string idVenta;
    string idCliente;
    vector<Producto> productosVendidos;
    double total;
public:
    Venta(string _idVenta="", string _idCliente="");

    // Getters
    string getIdVenta() const;
    string getIdCliente() const;
    double getTotal() const;

    // Agregar producto a la venta
    void agregarProducto(const Producto &p);

    // Mostrar resumen de la venta
    void mostrarResumen() const;

    // Obtener productos vendidos
    vector<Producto> getProductosVendidos() const;
};

#endif // VENTA_H_INCLUDED
