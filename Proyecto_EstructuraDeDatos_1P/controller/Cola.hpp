#ifndef COLA_HPP
#define COLA_HPP
#include "../model/NodoCola.hpp"
#include <iostream>
using namespace std;

struct ColaDinamica {
private:
    NodoCola* frente;
    NodoCola* final;

public:
    ColaDinamica() : frente(nullptr), final(nullptr) {}

    void registrarCliente(string nombre, string cedula) {
        NodoCola* nuevo = new NodoCola(nombre, cedula);
        if (!frente) {
            frente = nuevo;
            final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }

    void atenderCliente() {
        if (frente) {
            NodoCola* temp = frente;
            frente = frente->siguiente;
            delete temp;
            if (!frente) final = nullptr;
        }
    }

    void mostrarClientesRecursivo(NodoCola* nodo) {
        if (!nodo) return;
        cout << "Nombre: " << nodo->nombre << ", Cédula: " << nodo->cedula << endl;
        mostrarClientesRecursivo(nodo->siguiente);
    }

    void mostrarClientesRecursivo() {
        if (!frente) {
            cout << "Ya no hay clientes  en la cola.\n";
            return;
        }
        mostrarClientesRecursivo(frente);
    }

    NodoCola* obtenerFrente() { return frente; }
    bool estaVacia() { return frente == nullptr; }
};

#endif // COLA_HPP
