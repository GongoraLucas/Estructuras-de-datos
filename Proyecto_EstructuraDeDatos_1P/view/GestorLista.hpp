#ifndef GESTOR_LISTA_HPP
#define GESTOR_LISTA_HPP

#include <iostream>
#include <windows.h>
#include "../controller/Lista.hpp"
#include "VisualizadorLista.hpp"

using namespace std;

struct GestorLista {
public:
    void ejecutar() {
        visual.initVentana(); // Inicia la ventana
        menuLoop();
        visual.cerrarVentana(); // Cierra la ventana
    }

private:
    Lista lista;
    VisualizadorLista visual; // Instancia de la vista

    void menuLoop() {
        int opcion;
        int valor;

        do {
            system("cls");
            mostrarMenu();
            cin >> opcion;

            switch (opcion) {
                case 1:
                    insertarElemento();
                    break;
                case 2:
                    eliminarElemento();
                    break;
                case 3:
                    mostrarLista();
                    break;
            }

            cout << "\n";
            system("pause");
            system("cls");

        } while (opcion != 4);
    }

    void mostrarMenu() {
        cout << "------ MENU LISTA ------" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Eliminar elemento" << endl;
        cout << "3. Mostrar lista" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
    }

    void insertarElemento() {
        int valor;
        cout << "Ingrese valor a insertar: ";
        cin >> valor;
        lista.insertar(valor);
        visual.dibujarLista(lista, valor, true, false); // Animar inserción
    }

    void eliminarElemento() {
        int valor;
        cout << "Ingrese valor a eliminar: ";
        cin >> valor;
        visual.dibujarLista(lista, valor, false, true); // Animar eliminación antes
        lista.eliminar(valor);
        visual.dibujarLista(lista); // Redibujar sin animación
    }

    void mostrarLista() {
        cout << "Lista (modo recursivo): ";
        lista.mostrarRecursivo();
        cout << endl;
    }
};

#endif // GESTOR_LISTA_HPP
