#include <iostream>
using namespace std;

// Estructura de nodo de la pila
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para insertar un elemento en la pila
void push(Nodo*& tope, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
}

// Función para buscar un elemento en la pila mediante el método de búsqueda lineal
bool busquedaLineal(Nodo* tope, int valor) {
    Nodo* actual = tope;

    while (actual != nullptr) {
        if (actual->dato == valor) {
            return true;
        }
        actual = actual->siguiente;
    }

    return false;
}

// Función para imprimir los elementos de la pila
void imprimir(Nodo* tope) {
    Nodo* actual = tope;

    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }

    cout << endl;
}

int main() {
    Nodo* tope = nullptr;
    int opcion;
    int valor;
    bool encontrado;

    do {
        cout << endl;
        cout << "Menú:" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Buscar elemento" << endl;
        cout << "3. Imprimir pila" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un valor: ";
                cin >> valor;
                push(tope, valor);
                break;
            case 2:
                cout << "Ingrese el valor que desea buscar: ";
                cin >> valor;
                encontrado = busquedaLineal(tope, valor);
                if (encontrado) {
                    cout << "El valor " << valor << " fue encontrado en la pila." << endl;
                } else {
                    cout << "El valor " << valor << " no fue encontrado en la pila." << endl;
                }
                break;
            case 3:
                cout << "Pila: ";
                imprimir(tope);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
