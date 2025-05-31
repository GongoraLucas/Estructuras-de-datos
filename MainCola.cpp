#include <iostream>
#include <windows.h>
#include <clocale>
#include "ColaDinamica.h"
#include "ColaGrafica.h"
#include "Menu.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    ColaDinamica cola;
    ColaGrafica vista;
    int opcion;
    string nombre, cedula;

    vista.inicializarVentana();

    do {
        system("cls");
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Cédula: ";
                getline(cin, cedula);
                cola.registrarPaciente(nombre, cedula);
                vista.animarIngreso(cola.obtenerFrente());
                break;

            case 2:
                if (!cola.estaVacia()) {
                    vista.animarSalida(cola.obtenerFrente());
                    cola.atenderPaciente();
                    if (cola.estaVacia())
                        vista.mostrarColaVacia();
                    cout << "Paciente atendido.\n";
                } else {
                    cout << "No hay clientes en la cola.\n";
                    vista.mostrarColaVacia();
                }
                break;

            case 3:
                cout << "--- COLA ACTUAL ---\n";
                cola.mostrarPacientesRecursivo();
                break;

            case 4:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }

        if (opcion != 4) {
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }

    } while (opcion != 4);

    vista.cerrarVentana();
    return 0;
}
