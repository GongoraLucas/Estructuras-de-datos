#ifndef PILA_HPP
#define PILA_HPP

#include <iostream>

template <typename T>
struct PilaDinamica {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(const T& d) : dato(d), siguiente(nullptr) {}
    };

    Nodo* cima;
    int tamanio;

    Nodo* obtenerNodo(int posicion) const {
        if (posicion < 0 || posicion >= tamanio) {
            return nullptr;
        }
        Nodo* actual = cima;
        for (int i = 0; i < posicion; i++) {
            actual = actual->siguiente;
        }
        return actual;
    }

public:
    PilaDinamica() : cima(nullptr), tamanio(0) {}

    ~PilaDinamica() {
        while (!estaVacia()) {
            pop();
        }
    }

    void push(const T& valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cima;
        cima = nuevo;
        tamanio++;
    }

    void pop() {
        if (cima != nullptr) {
            Nodo* temp = cima;
            cima = cima->siguiente;
            delete temp;
            tamanio--;
        }
    }

    T top() const {
        if (cima != nullptr) {
            return cima->dato;
        }
        return T();
    }

    bool estaVacia() const {
        return (cima == nullptr);
    }


    int getTamanio() const {
        return tamanio;
    }

    T obtenerValor(int posicion) const {
        Nodo* nodo = obtenerNodo(posicion);
        return (nodo != nullptr) ? nodo->dato : T();
    }
};

#endif // PILA_HPP
