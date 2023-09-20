#include <iostream>
#include <string>
#include "utilidades.h"
using namespace std;

// Estructura para representar un usuario
struct Usuario {
    char nombre[20];
    char contrasena[20];
    int edad;
    char nacionalidad[20];
    char direccion[25];
};

// Declaración de funciones
void RegistrarUsuario(Usuario *&nUsuario);
bool AutenticarUsuario(const Usuario *nUsuario);
void opcion(int *&op1);

int main() {
	setlocale(LC_ALL, "spanish");
    int *op1 = new int;
    Usuario *nUsuario = new Usuario;

    do {
        cout << "\tSistema de Registro y Autenticación" << endl;
        cout << "1. Registrar Usuario" << endl;
        cout << "2. Iniciar Sesión" << endl;
        cout << "3. Salir" << endl;
        opcion(op1);

        switch (*op1) {
            case 1:
                RegistrarUsuario(nUsuario);
                PausarPrograma();
                LimpiarPantalla();
                break;
            case 2:
                if (AutenticarUsuario(nUsuario)) {
                    cout << "Bienvenido, " << nUsuario->nombre << "!" << endl;
                } else {
                    cout << "Autenticación fallida. Intente nuevamente." << endl;
                }
                PausarPrograma();
                LimpiarPantalla();
                break;
            case 3:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (*op1 != 3);

    delete nUsuario;
    delete op1;
    return 0;
}

// Función para registrar un nuevo usuario
void RegistrarUsuario(Usuario *&nUsuario) {
    cout << "Ingrese un nombre de usuario: ";
    cin.get();
    cin.getline(nUsuario->nombre, 20);
    cout << "Ingrese una contraseña: ";
    cin.getline(nUsuario->contrasena, 20);
    cout << "Ingrese edad: ";
    cin >> nUsuario->edad;
    cout << "Ingrese nacionalidad: ";
    cin.get();
    cin.getline(nUsuario->nacionalidad, 20);
    cout << "Ingrese dirección: ";
    cin.get();
    cin.getline(nUsuario->direccion, 25);
    cout << "Usuario registrado con éxito." << endl;
}

// Función para autenticar un usuario
bool AutenticarUsuario(const Usuario *nUsuario) {
    string nombreUsuario, contrasena;
    cout << "Ingrese su nombre de usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese su contraseña: ";
    cin >> contrasena;

    if (nombreUsuario == nUsuario->nombre && contrasena == nUsuario->contrasena) {
        return true;
    } else {
        return false;
    }
}

void opcion(int *&op1) {
    do {
        cout << "Ingrese opción: ";
        cin >> *op1;
        if (*op1 < 1 || *op1 > 3) {
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (*op1 < 1 || *op1 > 3);
}

