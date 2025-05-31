#ifndef COLADINAMICA_H
#define COLADINAMICA_H

#include "Nodo.h"
#include <iostream>
using namespace std;

class ColaDinamica {
private:
    Nodo* frente;
    Nodo* final;

public:
    ColaDinamica() : frente(nullptr), final(nullptr) {}

    void registrarPaciente(string nombre, string cedula) {
        Nodo* nuevo = new Nodo(nombre, cedula);
        if (!frente) {
            frente = nuevo;
            final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
    }

    void atenderPaciente() {
        if (frente) {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
            if (!frente) final = nullptr;
        }
    }

    void mostrarPacientesRecursivo(Nodo* nodo) {
        if (!nodo) return;
        cout << "Nombre: " << nodo->nombre << ", Cédula: " << nodo->cedula << endl;
        mostrarPacientesRecursivo(nodo->siguiente);
    }

    void mostrarPacientesRecursivo() {
        if (!frente) {
            cout << "Ya no hay pacientes en la cola.\n";
            return;
        }
        mostrarPacientesRecursivo(frente);
    }

    Nodo* obtenerFrente() { return frente; }
    bool estaVacia() { return frente == nullptr; }
};

#endif
