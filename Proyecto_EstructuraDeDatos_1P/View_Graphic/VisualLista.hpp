#ifndef VISUALLISTA_HPP
#define VISUALLISTA_HPP

#include "Lista.hpp"
#include <graphics.h>
#include <windows.h>

void initVentana() {
    setbkcolor(BLACK);
    cleardevice();
}

void cerrarVentana() {
//    closegraph();
}

void limpiarNodo(int x, int y) {
    setfillstyle(SOLID_FILL, BLACK);
    bar(x - 2, y - 2, x + 62, y + 42); // limpiar área con fondo negro
}

void animarInsercion(int x, int finalY, int valor) {
    char buffer[10];
    sprintf(buffer, "%d", valor);

    for (int y = 0; y <= finalY; y += 5) {
        limpiarNodo(x, y - 5);
        setcolor(WHITE);
        rectangle(x, y, x + 60, y + 40);
        outtextxy(x + 20, y + 10, buffer);
        delay(10);
    }
}

void animarEliminacion(int x, int y, int valor) {
    char buffer[10];
    sprintf(buffer, "%d", valor);

    for (int i = 0; i <= 30; i += 5) {
        limpiarNodo(x, y + i - 5);
        setcolor(RED);
        rectangle(x, y + i, x + 60, y + 40 + i);
        outtextxy(x + 20, y + 10 + i, buffer);
        delay(10);
    }
    limpiarNodo(x, y + 30); // limpiar al final
}

void dibujarLista(const Lista& lista, int animarValor = -1, bool animarInser = false, bool animarElim = false) {
    cleardevice();

    Nodo* actual = lista.obtenerCabeza();
    int x = 50;
    int y = 100;

    while (actual) {
        if (animarInser && actual->siguiente == nullptr && actual->dato == animarValor) {
            animarInsercion(x, y, actual->dato);
        } else {
            setcolor(WHITE);
            rectangle(x, y, x + 60, y + 40);
            char buffer[10];
            sprintf(buffer, "%d", actual->dato);
            outtextxy(x + 20, y + 10, buffer);
        }

        if (actual->siguiente) {
            line(x + 60, y + 20, x + 80, y + 20);
            line(x + 75, y + 15, x + 80, y + 20);
            line(x + 75, y + 25, x + 80, y + 20);
        }

        actual = actual->siguiente;
        x += 100;
    }

    outtextxy(x, y + 10, (char*)"NULL");

    if (animarElim && animarValor != -1) {
        animarEliminacion(x - 100, y, animarValor); // usa x anterior
    }
}
#endif
