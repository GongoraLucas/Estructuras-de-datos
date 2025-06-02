#ifndef GESTORCOLA_HPP
#define GESTORCOLA_HPP
#include <iostream>
#include <windows.h>
#include <clocale>
#include "../controller/Cola.hpp"
#include "VisualizadorCola.hpp"
#include "MenuInputCola.hpp"

struct GestorCola {
private:
    ColaDinamica cola;
    VisualizadorCola vista;

public:
    GestorCola() {
        setlocale(LC_ALL, "");
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
        vista.inicializarVentana();
    }

    ~GestorCola() {
        vista.cerrarVentana();
    }

    void ejecutar() {
        int opcion;
        std::string nombre, cedula;

        do {
            system("cls");
            mostrarMenu();
            std::cin >> opcion;
            std::cin.ignore();

            switch (opcion) {
                case 1:
                    std::cout << "Nombre: ";
                    std::getline(std::cin, nombre);
                    std::cout << "Cédula: ";
                    std::getline(std::cin, cedula);
                    cola.registrarCliente(nombre, cedula);
                    vista.animarIngreso(cola.obtenerFrente());
                    break;

                case 2:
                    if (!cola.estaVacia()) {
                        vista.animarSalida(cola.obtenerFrente());
                        cola.atenderCliente();
                        if (cola.estaVacia())
                            vista.mostrarColaVacia();
                        std::cout << "Cliente atendido.\n";
                    } else {
                        std::cout << "No hay clientes en la cola.\n";
                        vista.mostrarColaVacia();
                    }
                    break;

                case 3:
                    std::cout << "--- COLA ACTUAL ---\n";
                    cola.mostrarClientesRecursivo();
                    break;

                case 4:
                    std::cout << "Saliendo del gestor de cola...\n";
                    break;

                default:
                    std::cout << "Opción inválida. Intente nuevamente.\n";
            }

            if (opcion != 4) {
                std::cout << "\nPresione ENTER para continuar...";
                std::cin.get();
            }

        } while (opcion != 4);
    }
};

#endif // GESTORCOLA_HPP
