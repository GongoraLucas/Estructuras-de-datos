#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <cstring>
#include "gestorPila.hpp"

using namespace std;

void mostrarMenu();

int main() {

    initwindow(1280, 768, "Menu Principal");

    while (true) {
        cleardevice();
        mostrarMenu();

        char opcion = getch();

        cleardevice();
        settextstyle(3, 0, 2);  // Fuente y tamaño para los mensajes

        switch (opcion) {
            case '1': {
                outtextxy(getmaxx() / 2 - 150, getmaxy() / 2, (char*)"Gestion de Pila seleccionada");
                GestorPila gestor;
                gestor.ejecutar();
                break;
            }

            case '2':
                outtextxy(getmaxx() / 2 - 150, getmaxy() / 2, (char*)"Gestion de Cola seleccionada");
                // Aquí llamarás a tu función de submenú para Cola
                break;

            case '3':
                outtextxy(getmaxx() / 2 - 150, getmaxy() / 2, (char*)"Gestion de Lista seleccionada");
                // Aquí llamarás a tu función de submenú para Lista
                break;

            case '0':
                closegraph();
                exit(0);

            default:
                outtextxy(getmaxx() / 2 - 150, getmaxy() / 2, (char*)"Opcion invalida. Intente de nuevo.");
        }

        delay(1500);  // Esperar antes de mostrar de nuevo el menú
    }

    return 0;
}

void mostrarMenu() {
    settextstyle(3, 0, 3);  // Fuente, dirección, tamaño

    int midX = getmaxx() / 2;
    int startY = getmaxy() / 2 - 100;

    outtextxy(midX - 150, startY,         (char*)"=== Menu Principal ===");
    outtextxy(midX - 150, startY + 40,    (char*)"1. Gestion de Pila");
    outtextxy(midX - 150, startY + 80,    (char*)"2. Gestion de Cola");
    outtextxy(midX - 150, startY + 120,   (char*)"3. Gestion de Lista");
    outtextxy(midX - 150, startY + 160,   (char*)"0. Salir");
    outtextxy(midX - 150, startY + 200,   (char*)"Seleccione una opcion: ");
}
