#ifndef COLAGRAFICA_HPP
#define COLAGRAFICA_HPP

#include "NodoCola.hpp"
#include <graphics.h>
#include <string>
using namespace std;

class ColaGrafica {
public:
    void inicializarVentana() {
        setbkcolor(LIGHTGRAY);
        cleardevice();
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    }

    void cerrarVentana() {
        outtextxy(10, 370, const_cast<char*>("Presione una tecla para salir..."));
        getch();
    }

    void animarIngreso(NodoCola* frente) {
        cleardevice();
        int total = contarNodos(frente);
        int pasos = 20;
        int espacio = 180;

        for (int paso = 0; paso <= pasos; paso++) {
            cleardevice();
            NodoCola* actual = frente;
            int i = 0;
            while (actual) {
                int x = 1000 - (paso * (espacio / pasos)) - espacio * (total - i - 1);
                int y = 100;

                setfillstyle(SOLID_FILL, (i == 0) ? LIGHTRED : CYAN);
                bar(x, y, x + 160, y + 60);
                setcolor(BLACK);
                rectangle(x, y, x + 160, y + 60);

                outtextxy(x + 5, y + 10, const_cast<char*>(actual->nombre.c_str()));
                outtextxy(x + 5, y + 35, const_cast<char*>(actual->cedula.c_str()));

                actual = actual->siguiente;
                i++;
            }
            delay(30);
        }
    }

    void animarSalida(NodoCola* frente) {
        if (!frente) return;

        int pasos = 20;
        int espacio = 180;

        for (int paso = 0; paso <= pasos; paso++) {
            cleardevice();
            NodoCola* actual = frente;
            int i = 0;
            while (actual) {
                int x = (i == 0) ? 30 - paso * (espacio / pasos) : 30 + espacio * i;
                int y = 100;

                setfillstyle(SOLID_FILL, (i == 0) ? LIGHTRED : CYAN);
                bar(x, y, x + 160, y + 60);
                setcolor(BLACK);
                rectangle(x, y, x + 160, y + 60);

                outtextxy(x + 5, y + 10, const_cast<char*>(actual->nombre.c_str()));
                outtextxy(x + 5, y + 35, const_cast<char*>(actual->cedula.c_str()));

                actual = actual->siguiente;
                i++;
            }
            delay(30);
        }
    }

    void mostrarColaVacia() {
        cleardevice();
        outtextxy(30, 150, const_cast<char*>("YA NO HAY CLIENTES EN LA COLA"));
    }

private:
    int contarNodos(NodoCola* nodo) {
        int cont = 0;
        while (nodo) {
            cont++;
            nodo = nodo->siguiente;
        }
        return cont;
    }
};

#endif // COLAGRAFICA_HPP
