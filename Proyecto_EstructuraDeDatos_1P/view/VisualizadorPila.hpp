#ifndef VISUALIZADORPILA_HPP
#define VISUALIZADORPILA_HPP

#include <graphics.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include "../controller/Pila.hpp"

struct VisualizadorPila {
private:
    int ANCHO_BLOQUE           = 80;
    int ALTO_BLOQUE            = 40;
    int MARGEN_X               = 50;
    int MARGEN_Y               = 100;
    int ESPACIO_ENTRE_BLOQUES  = 5;

    int COLOR_BLOQUE   = LIGHTBLUE;
    int COLOR_BORDE    = DARKGRAY;
    int COLOR_TEXTO    = WHITE;
    int COLOR_FONDO    = WHITE;
    int COLOR_TEXTO_BG = BLACK;
    int COLOR_CIMA     = RED;
    int COLOR_POP_BG   = WHITE;
    int COLOR_PUSH     = YELLOW;

    typedef PilaDinamica<int> PilaEnteros;
    PilaEnteros* pila;
    int xBase;

    // Calcula dinámicamente yBase para que todos los bloques quepan
    int calcularYBase() {
        int total = pila->getTamanio();
        if (total == 0) return getmaxy() - ALTO_BLOQUE - MARGEN_Y;
        int alturaTotal = total * ALTO_BLOQUE + (total - 1) * ESPACIO_ENTRE_BLOQUES;
        return getmaxy() - MARGEN_Y - alturaTotal;
    }

    void dibujarTextoEnNegro(int x, int y, const char* texto, int tamanioFuente = 2) const {
        char buffer[256];
        std::strncpy(buffer, texto, sizeof(buffer)-1);
        buffer[sizeof(buffer)-1] = '\0';
        settextstyle(DEFAULT_FONT, HORIZ_DIR, tamanioFuente);
        int ancho = textwidth(buffer), alto = textheight(buffer);
        setfillstyle(SOLID_FILL, COLOR_TEXTO_BG);
        bar(x, y-alto+2, x+ancho, y+2);
        setcolor(COLOR_TEXTO);
        outtextxy(x, y, buffer);
    }

    void limpiarArea() {
        setfillstyle(SOLID_FILL, COLOR_FONDO);
        bar(0, 0, getmaxx(), getmaxy());
        char titulo[] = "Pila Dinamica";
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
        int anchoT = textwidth(titulo), altoT = textheight(titulo);
        setfillstyle(SOLID_FILL, COLOR_TEXTO_BG);
        bar(20, 20, 20 + anchoT, 20 + altoT);
        setcolor(COLOR_TEXTO);
        outtextxy(20, 20 + altoT, titulo);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    }

    void dibujarBloque(int x, int y, int valor, bool esCima = false) {
        int colorBloque = esCima ? COLOR_CIMA : COLOR_BLOQUE;
        setfillstyle(SOLID_FILL, colorBloque);
        setcolor(COLOR_BORDE);
        bar(x, y, x + ANCHO_BLOQUE, y + ALTO_BLOQUE);
        rectangle(x, y, x + ANCHO_BLOQUE, y + ALTO_BLOQUE);
        char buf[20];
        std::sprintf(buf, "%d", valor);
        setcolor(COLOR_TEXTO);
        int w = textwidth(buf), h = textheight(buf);
        outtextxy(x + (ANCHO_BLOQUE - w) / 2, y + (ALTO_BLOQUE + h) / 2, buf);
    }

    // Dibujado recursivo de la pila
    void dibujarRecursivo(int idx, int yBase) {
        if (idx >= pila->getTamanio()) return; //caso base
        bool esCima = (idx == 0);
        int y = yBase + idx * (ALTO_BLOQUE + ESPACIO_ENTRE_BLOQUES);
        int val = pila->obtenerValor(idx);
        dibujarBloque(xBase, y, val, esCima);
        dibujarRecursivo(idx + 1, yBase);
    }

public:
    VisualizadorPila(PilaEnteros* p)
        : pila(p), xBase(MARGEN_X) {}

    void clearArea() {
        limpiarArea();
    }

    void dibujarPilaCompleta() {
        limpiarArea();

        // calcular posición de los textos de estado justo debajo del título
        char titulo[] = "Pila Dinamica";
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
        int altoT = textheight(titulo);
        int yInfo = 20 + altoT + 80;

        if (pila->estaVacia()) {
            dibujarTextoEnNegro(xBase, yInfo, "Pila vacia", 2);
            return;
        }

        char info[64];
        std::sprintf(info, "Elementos: %d", pila->getTamanio());
        dibujarTextoEnNegro(20, yInfo, info, 2);
        std::sprintf(info, "Cima: %d", pila->top());
        dibujarTextoEnNegro(20, yInfo + textheight(info) + 28, info, 2);

        int yBase = calcularYBase();
        dibujarRecursivo(0, yBase);
    }

    void animarPush(int valor) {
        dibujarPilaCompleta();
        delay(200);

        int yFin = calcularYBase();
        for (int y = 50; y <= yFin; y += 5) {
            dibujarPilaCompleta();
            setfillstyle(SOLID_FILL, COLOR_PUSH);
            setcolor(COLOR_BORDE);
            bar(xBase, y, xBase + ANCHO_BLOQUE, y + ALTO_BLOQUE);
            rectangle(xBase, y, xBase + ANCHO_BLOQUE, y + ALTO_BLOQUE);
            char buf[20];
            std::sprintf(buf, "%d", valor);
            setcolor(COLOR_TEXTO);
            int w = textwidth(buf), h = textheight(buf);
            outtextxy(xBase + (ANCHO_BLOQUE - w) / 2, y + (ALTO_BLOQUE + h) / 2, buf);
            delay(30);
        }

        pila->push(valor);
        dibujarPilaCompleta();
    }

    void animarPop() {
        if (pila->estaVacia()) {
            dibujarPilaCompleta();
            dibujarTextoEnNegro(xBase, MARGEN_Y, "Error: pila vacia", 2);
            delay(1000);
            return;
        }

        int valorRemover = pila->top();
        int yIni = calcularYBase();
        for (int i = 0; i < 2; ++i) {
            dibujarPilaCompleta();
            delay(100);
        }
        for (int y = yIni; y >= -ALTO_BLOQUE; y -= 5) {
            dibujarPilaCompleta();
            setfillstyle(SOLID_FILL, COLOR_POP_BG);
            setcolor(COLOR_BORDE);
            bar(xBase, y, xBase + ANCHO_BLOQUE, y + ALTO_BLOQUE);
            rectangle(xBase, y, xBase + ANCHO_BLOQUE, y + ALTO_BLOQUE);
            char buf[20];
            std::sprintf(buf, "%d", valorRemover);
            setcolor(COLOR_TEXTO_BG);
            int w = textwidth(buf), h = textheight(buf);
            outtextxy(xBase + (ANCHO_BLOQUE - w) / 2, y + (ALTO_BLOQUE + h) / 2, buf);
            delay(30);
        }

        pila->pop();
        dibujarPilaCompleta();
    }

    void animarTop() {
        if (pila->estaVacia()) {
            dibujarPilaCompleta();
            dibujarTextoEnNegro(xBase, MARGEN_Y, "Error: pila vacia", 2);
            delay(1000);
            return;
        }

        int valorTop = pila->top();
        int yBase    = calcularYBase();
        for (int i = 0; i < 3; ++i) {
            dibujarPilaCompleta();
            setfillstyle(SOLID_FILL, COLOR_POP_BG);
            setcolor(COLOR_BORDE);
            bar(xBase, yBase, xBase + ANCHO_BLOQUE, yBase + ALTO_BLOQUE);
            rectangle(xBase, yBase, xBase + ANCHO_BLOQUE, yBase + ALTO_BLOQUE);
            char buf[20];
            std::sprintf(buf, "%d", valorTop);
            setcolor(COLOR_TEXTO_BG);
            int w = textwidth(buf), h = textheight(buf);
            outtextxy(xBase + (ANCHO_BLOQUE - w) / 2, yBase + (ALTO_BLOQUE + h) / 2, buf);
            delay(200);
            dibujarPilaCompleta();
            delay(200);
        }
    }
};

#endif // VISUALIZADORPILA_HPP
