#ifndef COLADINAMICA_HPP
#define COLADINAMICA_HPP

#include "NodoCola.hpp"
#include <iostream>
using namespace std;

class ColaDinamica {
private:
    NodoCola* frente;
    NodoCola* final;

public:
    ColaDinamica() : frente(nullptr), final(nullptr) {}

    void registrarPaciente(string nombre, string cedula) {
        NodoCola* nuevo = new NodoCola(nombre, cedula);
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
            NodoCola* temp = frente;
            frente = frente->siguiente;
            delete temp;
            if (!frente) final = nullptr;
        }
    }

    void mostrarPacientesRecursivo(NodoCola* nodo) {
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

    NodoCola* obtenerFrente() { return frente; }
    bool estaVacia() { return frente == nullptr; }
};

#endif // COLADINAMICA_HPP
