#include <iostream>
using namespace std;

// Estructura de nodo de la lista
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Función para insertar un elemento en la lista
void insertar(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

// Función para buscar un elemento en la lista mediante el método de búsqueda binaria
Nodo* busquedaBinaria(Nodo* cabeza, int valor) {
    Nodo* inicio = cabeza;
    Nodo* fin = nullptr;

    while (inicio != fin) {
        Nodo* medio = inicio;
        int longitud = 0;

        // Calcular la longitud de la lista desde "inicio" hasta "fin"
        while (medio != fin) {
            medio = medio->siguiente;
            longitud++;
        }

        // Calcular el índice del elemento medio
        medio = inicio;
        for (int i = 0; i < longitud / 2; i++) {
            medio = medio->siguiente;
        }

        // Realizar la comparación entre el elemento medio y el valor buscado
        if (medio->dato == valor) {
            return medio;
        } else if (medio->dato < valor) {
            inicio = medio->siguiente;
        } else {
            fin = medio;
        }
    }

    return nullptr;
}

// Función para imprimir los elementos de la lista
void imprimir(Nodo* cabeza) {
    Nodo* actual = cabeza;

    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }

    cout << endl;
}

int main() {
    Nodo* cabeza = nullptr;
    int opcion;
    int valor;
    Nodo* encontrado;

    do {
        cout << endl;
        cout << "Menú:" << endl;
        cout << "1. Insertar elemento" << endl;
        cout << "2. Buscar elemento" << endl;
        cout << "3. Imprimir lista" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un valor: ";
                cin >> valor;
                insertar(cabeza, valor);
                break;
            case 2:
                cout << "Ingrese el valor que desea buscar: ";
                cin >> valor;
                encontrado = busquedaBinaria(cabeza, valor);
                if (encontrado != nullptr) {
                    cout << "El valor " << valor << " fue encontrado en la lista." << endl;
                } else {
                    cout << "El valor " << valor << " no fue encontrado en la lista." << endl;
                }
                break;
            case 3:
                cout << "Lista: ";
                imprimir(cabeza);
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
