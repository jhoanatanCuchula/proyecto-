#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <string>
using namespace std;

// Funci�n para limpiar la pantalla
void LimpiarPantalla() {
    system("cls"); 
}

// Funci�n para pausar el programa
void PausarPrograma() {
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

#endif

