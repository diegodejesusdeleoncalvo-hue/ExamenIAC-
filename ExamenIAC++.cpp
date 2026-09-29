// ExamenIAC++.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// --- PROTOTIPOS DE FUNCIONES ---
void crearMatriz(string arr[], string matriz[2][3]);
vector<string> crearPila(string arr[]);
void mostrarResultados(string matriz[2][3], const vector<string>& pila);

int main() {
    // 1. Arreglo estático con 6 valores de series predefinidos
    string series[6] = {
        "Death Note",
        "Jujutsu Kaisen",
        "Re:Zero",
        "Breaking Bad",
        "The Boys",
        "One Punch Man"
    };

    int opcion = 0;
    string matriz2x3[2][3];
    vector<string> pilaSeries;
    bool datosProcesados = false; // Bandera para verificar si las funciones ya operaron

    // Ciclo continuo del menú (Do-While)
    do {
        cout << "\n========================================\n";
        cout << "       MENU PRINCIPAL - ESTRUCTURAS     \n";
        cout << "========================================\n";
        cout << "1. Procesar datos (Crear Matriz y Pila)\n";
        cout << "2. Mostrar Resultados (Matriz y Pila)\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";

        // Validación básica de entrada
        if (!(cin >> opcion)) {
            cout << "\n[Error] Ingrese un valor numerico valido.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        // Estructura condicional lógica para la gestión del menú
        switch (opcion) {
        case 1:
            // Llamada a las funciones solicitadas
            crearMatriz(series, matriz2x3);
            pilaSeries = crearPila(series);
            datosProcesados = true;
            cout << "\n[Exito] Matriz y Pila generadas correctamente a partir del arreglo estatico.\n";
            break;

        case 2:
            if (datosProcesados) {
                mostrarResultados(matriz2x3, pilaSeries);
            }
            else {
                cout << "\n[Aviso] Primero debe procesar los datos (Opcin 1).\n";
            }
            break;

        case 3:
            cout << "\nSaliendo del programa. ¡Hasta luego!\n";
            break;

        default:
            cout << "\n[Error] Opcion invalida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 3);

    return 0;
}

// --- FUNCIÓN MATRIZ ---
// Convierte el arreglo estático de 1D (6 elementos) en una matriz de 2x3 usando ciclos For anidados.
void crearMatriz(string arr[], string matriz[2][3]) {
    int indice = 0;
    for (int i = 0; i < 2; i++) {       // Ciclo para filas
        for (int j = 0; j < 3; j++) {   // Ciclo para columnas
            matriz[i][j] = arr[indice];
            indice++;
        }
    }
}

// --- FUNCIÓN PILA ---
// Almacena los valores iniciales y agrega dos elementos adicionales usando un vector.
vector<string> crearPila(string arr[]) {
    vector<string> pila;

    // Insertar los 6 valores iniciales del arreglo estático usando un ciclo For
    for (int i = 0; i < 6; i++) {
        pila.push_back(arr[i]);
    }

    // Agregar dos valores adicionales de series a la pila (Push)
    pila.push_back("Fire Force");
    pila.push_back("KonoSuba");

    return pila;
}

// --- FUNCIÓN DE IMPRESIÓN ---
// Muestra de forma ordenada y clara los valores finales de la matriz y la pila.
void mostrarResultados(string matriz[2][3], const vector<string>& pila) {
    cout << "\n----------------------------------------\n";
    cout << "           RESULTADOS FINALES           \n";
    cout << "----------------------------------------\n";

    // Impresión de la Matriz 2x3
    cout << "Matriz de Series (2x3):\n";
    for (int i = 0; i < 2; i++) {
        cout << "  [ ";
        for (int j = 0; j < 3; j++) {
            cout << setw(16) << left << matriz[i][j] << " ";
        }
        cout << "]\n";
    }

    cout << "\n----------------------------------------\n";

    // Impresión de la Pila (Simulando el orden de salida LIFO, del tope a la base)
    cout << "Pila de Series (Total: " << pila.size() << " elementos):\n";
    cout << "  (Tope de la pila -> ultimo elemento agregado)\n";
    for (int i = pila.size() - 1; i >= 0; i--) {
        cout << "  | " << setw(16) << left << pila[i] << " |\n";
    }
    cout << "  +--------------------+\n";
    cout << "  (Base de la pila)\n";
}
