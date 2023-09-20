#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <string>
using namespace std;

// Función para limpiar la pantalla
void LimpiarPantalla() {
    system("cls"); 
}

// Función para pausar el programa
void PausarPrograma() {
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

#endif

