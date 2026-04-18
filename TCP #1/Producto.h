#ifndef _PRODUCTO_H_INCLUDED
#define _PRODUCTO_H_INCLUDED
class Producto {
private:
    string id;
    string nombre;
    string categoria;
    double precio;
    double costo;
    int stock;
public:
    Producto(string _id, string _nombre, string _categoria, double _precio, double _costo, int _stock)
        : id(_id), nombre(_nombre), categoria(_categoria), precio(_precio), costo(_costo), stock(_stock) {}

    // Getters
    string getId() const { return id; }
    string getNombre() const { return nombre; }
    string getCategoria() const { return categoria; }
    double getPrecio() const { return precio; }
    double getCosto() const { return costo; }
    int getStock() const { return stock; }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setCategoria(string c) { categoria = c; }
    void setPrecio(double p) { precio = p; }
    void setCosto(double c) { costo = c; }
    void setStock(int s) { stock = s; }

    // Mostrar información
    void mostrarInfo() const {
        cout << "ID: " << id
             << " | Nombre: " << nombre
             << " | Categoria: " << categoria
             << " | Precio: " << precio
             << " | Costo: " << costo
             << " | Stock: " << stock << endl;
    }

    // Calcular margen de ganancia
    double margenGanancia() const {
        return precio - costo;
    }
};


#endif // _PRODUCTO_H_INCLUDED
