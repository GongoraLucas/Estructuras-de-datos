
#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>
using namespace std;

struct Nodo {
        int dato;
        Nodo* siguiente;

        Nodo(int d) : dato(d), siguiente(nullptr) {}
};

struct Lista {
private:
    Nodo* cabeza;

    void mostrarRec(Nodo* nodo) {
        if (nodo == nullptr) {
            cout << "NULL" << endl;
            return;
        }
        cout << nodo->dato << " -> ";
        mostrarRec(nodo->siguiente);
    }

public:
    Lista() : cabeza(nullptr) {}

    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente)
                temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }

    void eliminar(int valor) {
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        while (actual && actual->dato != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (!actual) return;

        if (!anterior)
            cabeza = actual->siguiente;
        else
            anterior->siguiente = actual->siguiente;

        delete actual;
    }

    void mostrarRecursivo() {
        mostrarRec(cabeza);
    }

    Nodo* obtenerCabeza() const {
        return cabeza;
    }
};

#endif

