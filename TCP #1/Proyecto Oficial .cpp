#include <bits/stdc++.h>
using namespace std;

// Validar un ID de 11 dígitos (solo números), mostrando un mensaje personalizado
string validarID(string mensaje) {
    string id;
    while (true) {
        cout << mensaje;
        cin >> id;
        if (id.length() != 11) {
            cout << "Debe tener exactamente 11 dígitos.\n";
            continue;
        }
        bool valido = true;
        for (char c : id) {
            if (!isdigit(c)) {
                valido = false;
                break;
            }
        }
        if (!valido) {
            cout << "El ID solo puede contener números.\n";
            continue;
        }
        return id;
    }
}

// Validar un número double positivo
double validarDouble(string mensaje) {
    double valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail() || valor < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida. Debe ser un número positivo.\n";
            continue;
        }
        return valor;
    }
}

// Validar un número entero positivo
int validarEntero(string mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;
        if (cin.fail() || valor < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida. Debe ser un número entero positivo.\n";
            continue;
        }
        return valor;
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ---------------------- Clase Producto ----------------------
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

// ---------------------- Clase Cliente ----------------------
class Cliente {
private:
    string id;
    string nombre;
    vector<string> historialCompras; // IDs de ventas
    double totalGastado;
public:
    Cliente(string _id, string _nombre) : id(_id), nombre(_nombre), totalGastado(0) {}

    // Getters
    string getId() const { return id; }
    string getNombre() const { return nombre; }
    double getTotalGastado() const { return totalGastado; }
    int getNumeroCompras() const { return historialCompras.size(); }

    // Setters
    void setNombre(string n) { nombre = n; }

    // Agregar compra
    void agregarCompra(string idVenta, double monto) {
        historialCompras.push_back(idVenta);
        totalGastado += monto;
    }

    // Mostrar historial
    void mostrarHistorial() const {
        cout << "Cliente: " << nombre << " | ID: " << id << endl;
        cout << "Compras registradas: " << historialCompras.size() << endl;
        cout << "Total gastado: " << totalGastado << endl;
    }

    // Validar si tiene compras
    bool tieneCompras() const {
        return !historialCompras.empty();
    }
};

// ---------------------- Clase Empleado ----------------------
class Empleado {
private:
    string id;
    string nombre;
    string cargo;
    double salario;
public:
    Empleado(string _id, string _nombre, string _cargo, double _salario)
        : id(_id), nombre(_nombre), cargo(_cargo), salario(_salario) {}

    // Getters
    string getId() const { return id; }
    string getNombre() const { return nombre; }
    string getCargo() const { return cargo; }
    double getSalario() const { return salario; }

    // Setters
    void setNombre(string n) { nombre = n; }
    void setCargo(string c) { cargo = c; }
    void setSalario(double s) { salario = s; }

    // Mostrar información completa
    void mostrarInfo() const {
        cout << "Empleado: " << nombre
             << " | ID: " << id
             << " | Cargo: " << cargo
             << " | Salario: " << salario << endl;
    }
};

// ---------------------- Clase Venta ----------------------
class Venta {
private:
    string idVenta;
    string idCliente;
    vector<Producto> productosVendidos;
    double total;
public:
    Venta(string _idVenta, string _idCliente)
        : idVenta(_idVenta), idCliente(_idCliente), total(0) {}

    // Getters
    string getIdVenta() const { return idVenta; }
    string getIdCliente() const { return idCliente; }
    double getTotal() const { return total; }

    // Agregar producto a la venta
    void agregarProducto(const Producto &p) {
        productosVendidos.push_back(p);
        total += p.getPrecio();
    }

    // Mostrar resumen de la venta
    void mostrarResumen() const {
        cout << "Venta ID: " << idVenta
             << " | Cliente ID: " << idCliente
             << " | Total: " << total << endl;
        cout << "Productos vendidos: " << endl;
        for(const auto &p : productosVendidos){
            cout << " - " << p.getNombre() << " (" << p.getPrecio() << ")\n";
        }
    }

    // Obtener productos vendidos
    vector<Producto> getProductosVendidos() const {
        return productosVendidos;
    }
};
// ---------------------- Menú Principal ----------------------
int menuPrincipal() {
    int opcion;
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1. Gestion de Productos\n";
    cout << "2. Gestion de Clientes\n";
    cout << "3. Gestion de Empleados\n";
    cout << "4. Ventas\n";
    cout << "5. Reportes y Estadisticas\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

// ---------------------- Submenú Productos ----------------------
int menuProductos() {
    int opcion;
    cout << "\n--- SUBMENU PRODUCTOS ---\n";
    cout << "1. Agregar producto\n";
    cout << "2. Modificar producto\n";
    cout << "3. Eliminar producto\n";
    cout << "4. Listar productos\n";
    cout << "5. Consultar por categoria\n";
    cout << "6. Consultar por nombre parcial\n";
    cout << "7. Consultar por rango de precios\n";
    cout << "8. Filtrar stock critico\n";
    cout << "9. Producto mas caro\n";
    cout << "10. Producto mas barato\n";
    cout << "0. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

// ---------------------- Submenú Clientes ----------------------
int menuClientes() {
    int opcion;
    cout << "\n--- SUBMENU CLIENTES ---\n";
    cout << "1. Agregar cliente\n";
    cout << "2. Modificar cliente\n";
    cout << "3. Eliminar cliente\n"; // con validación de compras
    cout << "4. Consultar historial de compras\n";
    cout << "5. Filtrar clientes por monto gastado\n";
    cout << "6. Filtrar clientes por numero de compras\n";
    cout << "7. Calcular total gastado por cliente\n";
    cout << "0. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

// ---------------------- Submenú Empleados ----------------------
int menuEmpleados() {
    int opcion;
    cout << "\n--- SUBMENU EMPLEADOS ---\n";
    cout << "1. Agregar empleado\n";
    cout << "2. Modificar empleado\n";
    cout << "3. Eliminar empleado\n";
    cout << "4. Consultar informacion completa\n";
    cout << "5. Estadisticas: salario promedio\n";
    cout << "6. Estadisticas: empleado con mayor salario\n";
    cout << "7. Estadisticas: conteo por cargo\n";
    cout << "0. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

// ---------------------- Submenú Ventas ----------------------
int menuVentas() {
    int opcion;
    cout << "\n--- SUBMENU VENTAS ---\n";
    cout << "1. Registrar venta\n";
    cout << "2. Eliminar venta por ID\n";
    cout << "3. Filtrar ventas por cliente\n";
    cout << "4. Filtrar ventas por rango de fechas\n";
    cout << "5. Estadisticas: total vendido por categoria\n";
    cout << "6. Estadisticas: producto mas vendido\n";
    cout << "7. Estadisticas: cliente que mas compra\n";
    cout << "0. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

// ---------------------- Submenú Reportes ----------------------
int menuReportes() {
    int opcion;
    cout << "\n--- SUBMENU REPORTES Y ESTADISTICAS ---\n";
    cout << "1. Costo total de inventario\n";
    cout << "2. Promedio de ventas por cliente\n";
    cout << "3. Promedio de precios por categoria\n";
    cout << "4. Filtrar productos segun margen de ganancia\n";
    cout << "0. Volver al menu principal\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}
// ---------------------- Funciones Auxiliares: Productos ----------------------

// Agregar producto
void agregarProducto(vector<Producto>& productos) {
    string id = validarID("ID del producto (11 dígitos): ");
    string nombre, categoria;
    double precio = validarDouble("Precio del producto: ");
    double costo = validarDouble("Costo del producto: ");
    int stock = validarEntero("Stock inicial: ");

    cout << "Nombre: "; cin >> nombre;
    cout << "Categoria: "; cin >> categoria;

    productos.push_back(Producto(id, nombre, categoria, precio, costo, stock));
    cout << "Producto agregado correctamente.\n";
}

// Modificar producto
void modificarProducto(vector<Producto>& productos) {
    string id = validarID("ID del producto a modificar (11 dígitos): ");
    for(auto &p : productos){
        if(p.getId() == id){
            string nombre, categoria;
            double precio, costo;
            int stock;
            cout << "Nuevo nombre: "; cin >> nombre;
            cout << "Nueva categoria: "; cin >> categoria;
            precio = validarDouble("Nuevo precio: ");
            costo = validarDouble("Nuevo costo: ");
            stock = validarEntero("Nuevo stock: ");

            p.setNombre(nombre);
            p.setCategoria(categoria);
            p.setPrecio(precio);
            p.setCosto(costo);
            p.setStock(stock);

            cout << "Producto modificado correctamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Eliminar producto
void eliminarProducto(vector<Producto>& productos) {
    string id = validarID("ID del producto a eliminar (11 dígitos): ");
    for(auto it = productos.begin(); it != productos.end(); ++it){
        if(it->getId() == id){
            productos.erase(it);
            cout << "Producto eliminado correctamente.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

// Listar productos
void listarProductos(const vector<Producto>& productos) {
    if(productos.empty()){
        cout << "No hay productos registrados.\n";
        return;
    }
    cout << "\n--- LISTA DE PRODUCTOS ---\n";
    for(const auto &p : productos){
        p.mostrarInfo();
    }
}

// Consultar por categoría
void consultarPorCategoria(const vector<Producto>& productos, string categoria) {
    cout << "\nProductos en categoria '" << categoria << "':\n";
    for(const auto &p : productos){
        if(p.getCategoria() == categoria) p.mostrarInfo();
    }
}

// Consultar por nombre parcial
void consultarPorNombreParcial(const vector<Producto>& productos, string parte) {
    cout << "\nProductos que contienen '" << parte << "' en el nombre:\n";
    for(const auto &p : productos){
        if(p.getNombre().find(parte) != string::npos) p.mostrarInfo();
    }
}

// Consultar por rango de precios
void consultarPorRangoPrecio(const vector<Producto>& productos, double min, double max) {
    cout << "\nProductos en rango de precios [" << min << " - " << max << "]:\n";
    for(const auto &p : productos){
        if(p.getPrecio() >= min && p.getPrecio() <= max) p.mostrarInfo();
    }
}

// Filtrar stock crítico
void filtrarStockCritico(const vector<Producto>& productos, int limite) {
    cout << "\nProductos con stock menor a " << limite << ":\n";
    for(const auto &p : productos){
        if(p.getStock() < limite) p.mostrarInfo();
    }
}

// Producto más caro
void productoMasCaro(const vector<Producto>& productos) {
    if(productos.empty()){ cout << "No hay productos.\n"; return; }
    auto maxIt = max_element(productos.begin(), productos.end(),
        [](const Producto &a, const Producto &b){ return a.getPrecio() < b.getPrecio(); });
    cout << "\nProducto más caro:\n";
    maxIt->mostrarInfo();
}

// Producto más barato
void productoMasBarato(const vector<Producto>& productos) {
    if(productos.empty()){ cout << "No hay productos.\n"; return; }
    auto minIt = min_element(productos.begin(), productos.end(),
        [](const Producto &a, const Producto &b){ return a.getPrecio() < b.getPrecio(); });
    cout << "\nProducto más barato:\n";
    minIt->mostrarInfo();
}
// ---------------------- Funciones Auxiliares: Clientes ----------------------

// Agregar cliente
void agregarCliente(vector<Cliente>& clientes) {
    string id = validarID("ID del cliente (11 dígitos): ");
    string nombre;
    cout << "Nombre del cliente: "; cin >> nombre;

    clientes.push_back(Cliente(id, nombre));
    cout << "Cliente agregado correctamente.\n";
}

// Modificar cliente
void modificarCliente(vector<Cliente>& clientes) {
    string id = validarID("ID del cliente a modificar (11 dígitos): ");
    for(auto &c : clientes){
        if(c.getId() == id){
            string nombre;
            cout << "Nuevo nombre: "; cin >> nombre;
            c.setNombre(nombre);
            cout << "Cliente modificado correctamente.\n";
            return;
        }
    }
    cout << "Cliente no encontrado.\n";
}

// Eliminar cliente (no se puede si tiene compras registradas)
void eliminarCliente(vector<Cliente>& clientes) {
    string id = validarID("ID del cliente a eliminar (11 dígitos): ");
    for(auto it = clientes.begin(); it != clientes.end(); ++it){
        if(it->getId() == id){
            if(it->tieneCompras()){
                cout << "No se puede eliminar: el cliente tiene compras registradas.\n";
                return;
            }
            clientes.erase(it);
            cout << "Cliente eliminado correctamente.\n";
            return;
        }
    }
    cout << "Cliente no encontrado.\n";
}

// Consultar historial de compras de un cliente
void consultarHistorialCliente(const vector<Cliente>& clientes) {
    string id = validarID("ID del cliente para consultar historial: ");
    for(const auto &c : clientes){
        if(c.getId() == id){
            c.mostrarHistorial();
            return;
        }
    }
    cout << "Cliente no encontrado.\n";
}

// Filtrar clientes por monto gastado
void filtrarClientesPorMonto(const vector<Cliente>& clientes, double minimo) {
    cout << "\nClientes con monto gastado >= " << minimo << ":\n";
    for(const auto &c : clientes){
        if(c.getTotalGastado() >= minimo){
            cout << "Cliente: " << c.getNombre()
                 << " | Total gastado: " << c.getTotalGastado() << endl;
        }
    }
}

// Filtrar clientes por número de compras
void filtrarClientesPorCompras(const vector<Cliente>& clientes, int minimo) {
    cout << "\nClientes con número de compras >= " << minimo << ":\n";
    for(const auto &c : clientes){
        if(c.getNumeroCompras() >= minimo){
            cout << "Cliente: " << c.getNombre()
                 << " | Compras: " << c.getNumeroCompras() << endl;
        }
    }
}

// Calcular total gastado por cliente
void calcularTotalGastadoCliente(const vector<Cliente>& clientes) {
    string id = validarID("ID del cliente para calcular total gastado: ");
    for(const auto &c : clientes){
        if(c.getId() == id){
            cout << "Cliente: " << c.getNombre()
                 << " | Total gastado: " << c.getTotalGastado() << endl;
            return;
        }
    }
    cout << "Cliente no encontrado.\n";
}
// ---------------------- Funciones Auxiliares: Empleados ----------------------

// Agregar empleado
void agregarEmpleado(vector<Empleado>& empleados) {
    string id = validarID("ID del empleado (11 dígitos): ");
    string nombre, cargo;
    double salario = validarDouble("Salario del empleado: ");

    cout << "Nombre del empleado: "; cin >> nombre;
    cout << "Cargo del empleado: "; cin >> cargo;

    empleados.push_back(Empleado(id, nombre, cargo, salario));
    cout << "Empleado agregado correctamente.\n";
}

// Modificar empleado
void modificarEmpleado(vector<Empleado>& empleados) {
    string id = validarID("ID del empleado a modificar (11 dígitos): ");
    for(auto &e : empleados){
        if(e.getId() == id){
            string nombre, cargo;
            double salario;
            cout << "Nuevo nombre: "; cin >> nombre;
            cout << "Nuevo cargo: "; cin >> cargo;
            salario = validarDouble("Nuevo salario: ");

            e.setNombre(nombre);
            e.setCargo(cargo);
            e.setSalario(salario);

            cout << "Empleado modificado correctamente.\n";
            return;
        }
    }
    cout << "Empleado no encontrado.\n";
}

// Eliminar empleado
void eliminarEmpleado(vector<Empleado>& empleados) {
    string id = validarID("ID del empleado a eliminar (11 dígitos): ");
    for(auto it = empleados.begin(); it != empleados.end(); ++it){
        if(it->getId() == id){
            empleados.erase(it);
            cout << "Empleado eliminado correctamente.\n";
            return;
        }
    }
    cout << "Empleado no encontrado.\n";
}

// Consultar información completa de un empleado
void consultarInfoEmpleado(const vector<Empleado>& empleados) {
    string id = validarID("ID del empleado a consultar: ");
    for(const auto &e : empleados){
        if(e.getId() == id){
            e.mostrarInfo();
            return;
        }
    }
    cout << "Empleado no encontrado.\n";
}

// Estadística: salario promedio
void salarioPromedio(const vector<Empleado>& empleados) {
    if(empleados.empty()){ cout << "No hay empleados.\n"; return; }
    double suma = 0;
    for(const auto &e : empleados){
        suma += e.getSalario();
    }
    double promedio = suma / empleados.size();
    cout << "Salario promedio: " << promedio << endl;
}

// Estadística: empleado con mayor salario
void empleadoMayorSalario(const vector<Empleado>& empleados) {
    if(empleados.empty()){ cout << "No hay empleados.\n"; return; }
    auto maxIt = max_element(empleados.begin(), empleados.end(),
        [](const Empleado &a, const Empleado &b){ return a.getSalario() < b.getSalario(); });
    cout << "Empleado con mayor salario:\n";
    maxIt->mostrarInfo();
}

// Estadística: conteo por cargo
void conteoPorCargo(const vector<Empleado>& empleados) {
    if(empleados.empty()){ cout << "No hay empleados.\n"; return; }
    cout << "\nConteo de empleados por cargo:\n";
    vector<string> cargos;
    vector<int> conteos;

    for(const auto &e : empleados){
        auto it = find(cargos.begin(), cargos.end(), e.getCargo());
        if(it != cargos.end()){
            int idx = distance(cargos.begin(), it);
            conteos[idx]++;
        } else {
            cargos.push_back(e.getCargo());
            conteos.push_back(1);
        }
    }

    for(size_t i=0; i<cargos.size(); i++){
        cout << cargos[i] << ": " << conteos[i] << endl;
    }
}
// ---------------------- Funciones Auxiliares: Ventas ----------------------

// Registrar venta
void registrarVenta(vector<Venta>& ventas, vector<Cliente>& clientes, vector<Producto>& productos) {
    string idVenta = validarID("ID de la venta (11 dígitos): ");
    string idCliente = validarID("ID del cliente: ");

    // Buscar cliente
    Cliente* clientePtr = nullptr;
    for(auto &c : clientes){
        if(c.getId() == idCliente){
            clientePtr = &c;
            break;
        }
    }
    if(clientePtr == nullptr){
        cout << "Cliente no encontrado.\n";
        return;
    }

    Venta nuevaVenta(idVenta, idCliente);
    double totalVenta = 0;

    char continuar;
    do {
        string idProd = validarID("ID del producto a vender: ");
        int cantidad = validarEntero("Cantidad: ");

        bool encontrado = false;
        for(auto &p : productos){
            if(p.getId() == idProd){
                if(p.getStock() < cantidad){
                    cout << "Stock insuficiente.\n";
                    return;
                }
                // Actualizar stock
                p.setStock(p.getStock() - cantidad);

                // Agregar productos a la venta
                for(int i=0; i<cantidad; i++){
                    nuevaVenta.agregarProducto(p);
                }

                totalVenta += p.getPrecio() * cantidad;
                encontrado = true;
                break;
            }
        }
        if(!encontrado) cout << "Producto no encontrado.\n";

        cout << "¿Agregar otro producto? (s/n): ";
        cin >> continuar;
    } while(continuar == 's' || continuar == 'S');

    ventas.push_back(nuevaVenta);
    clientePtr->agregarCompra(idVenta, totalVenta);

    cout << "Venta registrada correctamente.\n";
    nuevaVenta.mostrarResumen();
}

// Eliminar venta por ID
void eliminarVenta(vector<Venta>& ventas) {
    string id = validarID("ID de la venta a eliminar: ");
    for(auto it = ventas.begin(); it != ventas.end(); ++it){
        if(it->getIdVenta() == id){
            ventas.erase(it);
            cout << "Venta eliminada correctamente.\n";
            return;
        }
    }
    cout << "Venta no encontrada.\n";
}

// Filtrar ventas por cliente
void filtrarVentasPorCliente(const vector<Venta>& ventas, string idCliente) {
    cout << "\nVentas del cliente " << idCliente << ":\n";
    for(const auto &v : ventas){
        if(v.getIdCliente() == idCliente){
            v.mostrarResumen();
        }
    }
}

// Filtrar ventas por rango de fechas (simplificado: usando ID como referencia)
void filtrarVentasPorRango(const vector<Venta>& ventas, string inicio, string fin) {
    cout << "\nVentas en rango [" << inicio << " - " << fin << "]:\n";
    for(const auto &v : ventas){
        if(v.getIdVenta() >= inicio && v.getIdVenta() <= fin){
            v.mostrarResumen();
        }
    }
}

// Estadística: total vendido por categoría
void totalVendidoPorCategoria(const vector<Venta>& ventas) {
    cout << "\nTotal vendido por categoría:\n";
    vector<string> categorias;
    vector<double> totales;

    for(const auto &v : ventas){
        for(const auto &p : v.getProductosVendidos()){
            auto it = find(categorias.begin(), categorias.end(), p.getCategoria());
            if(it != categorias.end()){
                int idx = distance(categorias.begin(), it);
                totales[idx] += p.getPrecio();
            } else {
                categorias.push_back(p.getCategoria());
                totales.push_back(p.getPrecio());
            }
        }
    }

    for(size_t i=0; i<categorias.size(); i++){
        cout << categorias[i] << ": " << totales[i] << endl;
    }
}

// Estadística: producto más vendido
void productoMasVendido(const vector<Venta>& ventas) {
    if(ventas.empty()){ cout << "No hay ventas.\n"; return; }
    vector<string> nombres;
    vector<int> conteos;

    for(const auto &v : ventas){
        for(const auto &p : v.getProductosVendidos()){
            auto it = find(nombres.begin(), nombres.end(), p.getNombre());
            if(it != nombres.end()){
                int idx = distance(nombres.begin(), it);
                conteos[idx]++;
            } else {
                nombres.push_back(p.getNombre());
                conteos.push_back(1);
            }
        }
    }

    int maxIdx = distance(conteos.begin(), max_element(conteos.begin(), conteos.end()));
    cout << "Producto más vendido: " << nombres[maxIdx]
         << " | Cantidad: " << conteos[maxIdx] << endl;
}

// Estadística: cliente que más compra
void clienteMasCompra(const vector<Cliente>& clientes) {
    if(clientes.empty()){ cout << "No hay clientes.\n"; return; }
    auto maxIt = max_element(clientes.begin(), clientes.end(),
        [](const Cliente &a, const Cliente &b){ return a.getNumeroCompras() < b.getNumeroCompras(); });
    cout << "Cliente que más compra:\n";
    maxIt->mostrarHistorial();
}
// ---------------------- Funciones Auxiliares: Reportes ----------------------

// Costo total de inventario
double costoTotalInventario(const vector<Producto>& productos) {
    double total = 0;
    for(const auto &p : productos){
        total += p.getStock() * p.getPrecio();
    }
    return total;
}

// Promedio de ventas por cliente
double promedioVentasPorCliente(const vector<Venta>& ventas, const vector<Cliente>& clientes) {
    if(clientes.empty()) return 0;
    double totalVentas = 0;
    for(const auto &v : ventas){
        totalVentas += v.getTotal();
    }
    return totalVentas / clientes.size();
}

// Promedio de precios por categoría
double promedioPreciosPorCategoria(const vector<Producto>& productos, string categoria) {
    double suma = 0; int count = 0;
    for(const auto &p : productos){
        if(p.getCategoria() == categoria){
            suma += p.getPrecio();
            count++;
        }
    }
    return (count == 0) ? 0 : (suma / count);
}

// Filtrar productos según margen de ganancia
void filtrarPorMargenGanancia(const vector<Producto>& productos, double minimo) {
    cout << "\nProductos con margen >= " << minimo << ":\n";
    for(const auto &p : productos){
        if(p.margenGanancia() >= minimo){
            p.mostrarInfo();
        }
    }
}
int main() {
    vector<Producto> productos;
    vector<Cliente> clientes;
    vector<Empleado> empleados;
    vector<Venta> ventas;

    int opcionPrincipal;
    do {
        opcionPrincipal = menuPrincipal();
        switch(opcionPrincipal) {
            case 1: { // Productos
                int op;
                do {
                    op = menuProductos();
                    switch(op) {
                        case 1: agregarProducto(productos); break;
                        case 2: modificarProducto(productos); break;
                        case 3: eliminarProducto(productos); break;
                        case 4: listarProductos(productos); break;
                        case 5: { string cat; cout << "Categoria: "; cin >> cat; consultarPorCategoria(productos, cat); } break;
                        case 6: { string parte; cout << "Nombre parcial: "; cin >> parte; consultarPorNombreParcial(productos, parte); } break;
                        case 7: { double min = validarDouble("Precio minimo: "); double max = validarDouble("Precio maximo: "); consultarPorRangoPrecio(productos, min, max); } break;
                        case 8: { int limite = validarEntero("Stock limite: "); filtrarStockCritico(productos, limite); } break;
                        case 9: productoMasCaro(productos); break;
                        case 10: productoMasBarato(productos); break;
                    }
                } while(op != 0);
            } break;

            case 2: { // Clientes
                int op;
                do {
                    op = menuClientes();
                    switch(op) {
                        case 1: agregarCliente(clientes); break;
                        case 2: modificarCliente(clientes); break;
                        case 3: eliminarCliente(clientes); break;
                        case 4: consultarHistorialCliente(clientes); break;
                        case 5: { double min = validarDouble("Monto minimo: "); filtrarClientesPorMonto(clientes, min); } break;
                        case 6: { int min = validarEntero("Numero minimo de compras: "); filtrarClientesPorCompras(clientes, min); } break;
                        case 7: calcularTotalGastadoCliente(clientes); break;
                    }
                } while(op != 0);
            } break;

            case 3: { // Empleados
                int op;
                do {
                    op = menuEmpleados();
                    switch(op) {
                        case 1: agregarEmpleado(empleados); break;
                        case 2: modificarEmpleado(empleados); break;
                        case 3: eliminarEmpleado(empleados); break;
                        case 4: consultarInfoEmpleado(empleados); break;
                        case 5: salarioPromedio(empleados); break;
                        case 6: empleadoMayorSalario(empleados); break;
                        case 7: conteoPorCargo(empleados); break;
                    }
                } while(op != 0);
            } break;

            case 4: { // Ventas
                int op;
                do {
                    op = menuVentas();
                    switch(op) {
                        case 1: registrarVenta(ventas, clientes, productos); break;
                        case 2: eliminarVenta(ventas); break;
                        case 3: { string idC = validarID("ID del cliente: "); filtrarVentasPorCliente(ventas, idC); } break;
                        case 4: { string ini, fin; cout << "ID inicio: "; cin >> ini; cout << "ID fin: "; cin >> fin; filtrarVentasPorRango(ventas, ini, fin); } break;
                        case 5: totalVendidoPorCategoria(ventas); break;
                        case 6: productoMasVendido(ventas); break;
                        case 7: clienteMasCompra(clientes); break;
                    }
                } while(op != 0);
            } break;

            case 5: { // Reportes
                int op;
                do {
                    op = menuReportes();
                    switch(op) {
                        case 1: cout << "Costo total de inventario: " << costoTotalInventario(productos) << endl; break;
                        case 2: cout << "Promedio de ventas por cliente: " << promedioVentasPorCliente(ventas, clientes) << endl; break;
                        case 3: { string cat; cout << "Categoria: "; cin >> cat; cout << "Promedio de precios: " << promedioPreciosPorCategoria(productos, cat) << endl; } break;
                        case 4: { double min = validarDouble("Margen minimo: "); filtrarPorMargenGanancia(productos, min); } break;
                    }
                } while(op != 0);
            } break;

            case 0: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }
    } while(opcionPrincipal != 0);

    return 0;
}
