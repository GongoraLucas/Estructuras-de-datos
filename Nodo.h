#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

struct Nodo {
    string nombre;
    string cedula;
    Nodo* siguiente;

    Nodo(string nom, string ced) : nombre(nom), cedula(ced), siguiente(nullptr) {}
};

#endif
