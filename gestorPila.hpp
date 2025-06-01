#ifndef GESTORPILA_HPP
#define GESTORPILA_HPP

#include "pila.hpp"
#include "visualizadorPila.hpp"
#include <graphics.h>
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string>

struct GestorPila {
private:
    typedef PilaDinamica<int> PilaEnteros;
    PilaEnteros pila;
    VisualizadorPila visualizador;

public:
    GestorPila(): visualizador(&pila){}

    ~GestorPila(){}

    void mostrarMenu() {
        const int MENU_ANCHO = 300;
        int xMenu = getmaxx() - MENU_ANCHO;
        setfillstyle(SOLID_FILL, BLACK);
        bar(xMenu, 0, getmaxx(), getmaxy());

        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        setcolor(WHITE);

        int yPos = 50;
        char linea1[] = "MENU DE OPERACIONES";
        int ancho1 = textwidth(linea1);
        outtextxy(xMenu + (MENU_ANCHO - ancho1) / 2, yPos, linea1);

        yPos += 40;
        outtextxy(xMenu + 10, yPos, "1. PUSH   - Agregar");
        yPos += 30;
        outtextxy(xMenu + 10, yPos, "2. POP    - Remover");
        yPos += 30;
        outtextxy(xMenu + 10, yPos, "3. TOP    - Ver cima");
        yPos += 30;
        outtextxy(xMenu + 10, yPos, "ESC - SALIR");

        yPos += 60;
        outtextxy(xMenu + 10, yPos, "Estado:");
        yPos += 30;

        char estado[50];
        if (pila.estaVacia()) {
            std::sprintf(estado, "Pila: VACIA");
        } else {
            std::sprintf(estado, "Elementos: %d", pila.getTamanio());
        }
        outtextxy(xMenu + 10, yPos, estado);

        if (!pila.estaVacia()) {
            yPos += 30;
            std::sprintf(estado, "Cima: %d", pila.top());
            outtextxy(xMenu + 10, yPos, estado);
        }
    }

    int obtenerNumero() {
        visualizador.clearArea();
        setfillstyle(SOLID_FILL, BLACK);
        bar(200, 200, 540, 320);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

        char lbl1[] = "Ingrese numero:";
        outtextxy(210, 240, lbl1);
        char lbl2[] = "(Digits + ENTER)";
        outtextxy(210, 280, lbl2);

        std::string numeroStr;
        int xInput = 210;
        int yInput = 320;

        while (true) {
            char buffer[256] = {0};
            std::strncpy(buffer, numeroStr.c_str(), sizeof(buffer) - 1);

            int anchoAnterior = textwidth(buffer);
            int altoAnterior  = textheight(buffer);
            setfillstyle(SOLID_FILL, BLACK);
            bar(xInput, yInput - altoAnterior + 2, xInput + anchoAnterior, yInput + 2);

            if (kbhit()) {
                char c = getch();
                if (c == 8) {
                    if (!numeroStr.empty()) {
                        numeroStr.pop_back();
                    }
                } else if (c == 13) {
                    break;
                } else if (c >= '0' && c <= '9') {
                    numeroStr.push_back(c);
                }
            }

            char dibujo[256] = {0};
            std::strncpy(dibujo, numeroStr.c_str(), sizeof(dibujo) - 1);
            setcolor(WHITE);
            outtextxy(xInput, yInput, dibujo);

            delay(50);
        }

        int valor = 0;
        if (!numeroStr.empty()) {
            valor = std::stoi(numeroStr);
        }
        return valor;
    }

    void ejecutar() {
        bool continuar = true;

        while (continuar) {
            visualizador.dibujarPilaCompleta();
            mostrarMenu();

            char tecla;
            while (!kbhit()) {
                delay(50);
            }
            tecla = getch();

            switch (tecla) {
                case '1': {
                    int valor = obtenerNumero();
                    visualizador.animarPush(valor);
                    break;
                }
                case '2':
                    visualizador.animarPop();
                    break;
                case '3':
                    visualizador.animarTop();
                    break;
                case 27:  // ESC
                    continuar = false;
                    break;
                default:
                    continuar = false;
                    break;
            }

            delay(100);
        }

        // Mensaje de regreso
        visualizador.clearArea();
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        char mensaje[] = "Regresando al menu principal...";
        int ancho = textwidth(mensaje);
        int alto = textheight(mensaje);
        bar(100, 100, 100 + ancho, 100 + alto);
        outtextxy(100, 100 + alto, mensaje);
        delay(1500);
    }
};

#endif // GESTORPILA_HPP
