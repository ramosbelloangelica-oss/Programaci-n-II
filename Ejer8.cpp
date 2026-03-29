#include <bits/stdc++.h>
using namespace std;

class Contacto {
public:
    string nombre, telefono, email;
    Contacto(string n, string t, string e) {
        nombre = n;
        telefono = t;
        email = e;
    }
};

class Agenda {
private:
    vector<Contacto> contactos;
public:
    void agregar(Contacto c) {
        for(auto &x : contactos) {
            if(x.nombre == c.nombre) {
                cout << "Contacto existente\n";
                return;
            }
        }
        contactos.push_back(c);
    }

    void eliminar(string name) {
        for(size_t i = 0; i < contactos.size(); i++) {
            if(contactos[i].nombre == name) {
                contactos.erase(contactos.begin() + i);
                return;
            }
        }
        cout << "No existe ese contacto\n";
    }

    void buscar(string name) {
        for(auto &x : contactos) {
            if(x.nombre == name) {
                cout << x.nombre << "\n" << x.telefono << "\n" << x.email << "\n";
                return;
            }
        }
        cout << "No se encontro el contacto\n";
    }

    void mostrarTodos() {
        for(auto &x : contactos) {
            cout << "----------------\n";
            cout << x.nombre << "\n" << x.telefono << "\n" << x.email << "\n";
        }
    }
};

int main() {
    Agenda ag;
    ag.agregar(Contacto("Angélica","111","angelica@mail.com"));
    ag.agregar(Contacto("Andriel","222","andriel@mail.com"));
    ag.agregar(Contacto("Juan","333","juan@mail.com"));
    ag.mostrarTodos();
    ag.buscar("Juan");
    ag.eliminar("Andriel");
    ag.mostrarTodos();
    return 0;
}
