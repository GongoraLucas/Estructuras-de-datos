#ifndef COLAGRAFICA_H
#define COLAGRAFICA_H

#include "Nodo.h"
#include <graphics.h>
#include <string>
using namespace std;

class ColaGrafica {
public:
    void inicializarVentana() {
        initwindow(1000, 400, "Consultorio Médico");
        setbkcolor(LIGHTGRAY);
        cleardevice();
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    }

    void cerrarVentana() {
        outtextxy(10, 370, const_cast<char*>("Presione una tecla para salir..."));
        getch();
    }

    void animarIngreso(Nodo* frente) {
        cleardevice();
        int total = contarNodos(frente);
        int pasos = 20;
        int espacio = 180;
        for (int paso = 0; paso <= pasos; paso++) {
            cleardevice();
            Nodo* actual = frente;
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

    void animarSalida(Nodo* frente) {
        if (!frente) return;

        int pasos = 20;
        int espacio = 180;
        for (int paso = 0; paso <= pasos; paso++) {
            cleardevice();
            Nodo* actual = frente;
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

    int contarNodos(Nodo* nodo) {
        int cont = 0;
        while (nodo) {
            cont++;
            nodo = nodo->siguiente;
        }
        return cont;
    }
};

#endif
