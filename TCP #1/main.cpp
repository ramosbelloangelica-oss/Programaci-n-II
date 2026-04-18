#include <iostream>
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Venta.h"
using namespace std;
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
                        // aquí seguirían las demás opciones de ventas
                    }
                } while(op != 0);
            } break;

            case 5: { // Reportes
                int op;
                do {
                    op = menuReportes();
                    switch(op) {
                        case 1: cout << "Costo total inventario: " << costoTotalInventario(productos) << endl; break;
                        case 2: cout << "Promedio ventas por cliente: " << promedioVentasPorCliente(ventas, clientes) << endl; break;
                        case 3: { string cat; cout << "Categoria: "; cin >> cat; cout << "Promedio precios: " << promedioPreciosPorCategoria(productos, cat) << endl; } break;
                        case 4: { double min = validarDouble("Margen minimo: "); filtrarPorMargenGanancia(productos, min); } break;
                    }
                } while(op != 0);
            } break;
        }
    } while(opcionPrincipal != 0);

    return 0;
}
