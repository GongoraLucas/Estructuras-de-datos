#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include <string>
using namespace std;

struct NodoCola {
    string nombre;
    string cedula;
    NodoCola* siguiente;

    NodoCola(string nom, string ced) : nombre(nom), cedula(ced), siguiente(nullptr) {}
};

#endif
