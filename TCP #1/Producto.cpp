#include "Producto.h"

// Constructor
Producto::Producto(string _id, string _nombre, string _categoria, double _precio, double _costo, int _stock)
    : id(_id), nombre(_nombre), categoria(_categoria), precio(_precio), costo(_costo), stock(_stock) {}

// Getters
string Producto::getId() const { return id; }
string Producto::getNombre() const { return nombre; }
string Producto::getCategoria() const { return categoria; }
double Producto::getPrecio() const { return precio; }
double Producto::getCosto() const { return costo; }
int Producto::getStock() const { return stock; }

// Setters
void Producto::setNombre(string n) { nombre = n; }
void Producto::setCategoria(string c) { categoria = c; }
void Producto::setPrecio(double p) { precio = p; }
void Producto::setCosto(double c) { costo = c; }
void Producto::setStock(int s) { stock = s; }

// Mostrar información
void Producto::mostrarInfo() const {
    cout << "ID: " << id
         << " | Nombre: " << nombre
         << " | Categoria: " << categoria
         << " | Precio: " << precio
         << " | Costo: " << costo
         << " | Stock: " << stock << endl;
}

// Calcular margen de ganancia
double Producto::margenGanancia() const {
    return precio - costo;
}
