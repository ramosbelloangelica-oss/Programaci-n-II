#include "Venta.h"

Venta::Venta(string _idVenta, string _idCliente)
    : idVenta(_idVenta), idCliente(_idCliente), total(0) {}

string Venta::getIdVenta() const { return idVenta; }
string Venta::getIdCliente() const { return idCliente; }
double Venta::getTotal() const { return total; }

void Venta::agregarProducto(const Producto &p) {
    productosVendidos.push_back(p);
    total += p.getPrecio();
}

void Venta::mostrarResumen() const {
    cout << "Venta ID: " << idVenta
         << " | Cliente ID: " << idCliente
         << " | Total: " << total << endl;
    cout << "Productos vendidos: " << endl;
    for(const auto &p : productosVendidos){
        cout << " - " << p.getNombre() << " (" << p.getPrecio() << ")\n";
    }
}

vector<Producto> Venta::getProductosVendidos() const {
    return productosVendidos;
}
