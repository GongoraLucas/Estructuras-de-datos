#include <iostream>
#include <windows.h>
#include "Lista.hpp"
#include "VisualLista.hpp"
using namespace std;

int main() {
    Lista lista;
    int opcion;
    int valor;

    initVentana(); // Inicia la ventana

    do {
        system("cls");
        cout << "------ MENU LISTA ------" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Eliminar elemento" << endl;
        cout << "3. Mostrar lista" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese valor a insertar: ";
                cin >> valor;
                lista.insertar(valor);
                dibujarLista(lista, valor, true, false); // Animar inserción
                break;

            case 2:
                cout << "Ingrese valor a eliminar: ";
                cin >> valor;
                dibujarLista(lista, valor, false, true); // Animar eliminación antes de borrar
                lista.eliminar(valor);
                dibujarLista(lista); // Redibujar lista limpia
                break;

            case 3:
                cout << "Lista (modo recursivo): ";
                lista.mostrarRecursivo();
                cout << endl;
                system("pause");
                break;
        }

        cout << "\n";
        system("pause");
        system("cls");

    } while(opcion != 4);

    cerrarVentana();
    return 0;
}
