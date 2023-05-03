
#include <iostream>
using namespace std;

struct Node {   // estructura de nodo que se utiliza en la pila
    int data;
    Node *next;
};

class Stack {   // clase para la pila que utiliza punteros
private:
    Node *top;
public:
    Stack() {   // constructor para inicializar la pila vacía
        top = nullptr;
    }
    void push(int x) {   // función para insertar un elemento en la pila
        Node *t = new Node;
        t->data = x;
        t->next = top;   // el nuevo nodo se enlaza con el nodo anterior en la pila
        top = t;   // el nuevo nodo se convierte en el nodo superior en la pila
    }
    int pop() {   // función para eliminar el elemento superior de la pila y devolver su valor
        int x = -1;
        if (top) {   // si la pila no está vacía
            x = top->data;   // se guarda el valor del elemento superior
            Node *t = top;   // se guarda la dirección del nodo superior
            top = top->next;   // se mueve el puntero al nodo siguiente en la pila
            delete t;   // se libera la memoria del nodo superior
        }
        return x;   // se devuelve el valor del elemento superior eliminado
    }
    bool isEmpty() {   // función que devuelve verdadero si la pila está vacía
        return top == nullptr;
    }
    void display() {   // función para mostrar los elementos de la pila
        Node *p = top;   // se utiliza un puntero para recorrer la pila
        while (p) {   // mientras el puntero no sea nulo
            cout << p->data << " ";   // se muestra el valor del nodo actual
            p = p->next;   // se mueve el puntero al nodo siguiente
        }
        cout << endl;   // se muestra un salto de línea al final
    }
    void bubbleSort() {   // función que implementa el método de burbuja para ordenar los elementos en la pila
        Node *p, *q;
        int temp;
        for (p = top; p != nullptr; p = p->next) {   // se recorre la pila con un puntero p
            for (q = p->next; q != nullptr; q = q->next) {   // se recorre la pila con un puntero q que está adelante de p
                if (p->data > q->data) {   // si el valor en el nodo actual p es mayor que el valor en el nodo actual q
                    // intercambiar los valores en los nodos utilizando punteros
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
            }
        }
    }
};

int main() {
    Stack s;
    int n, x;
    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;
    cout << "Ingrese los elementos: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.push(x);   // se inserta cada elemento en la pila utilizando la función push()
    }
    cout << "Pila antes de ordenar: ";
    s.display();  
    s.bubbleSort();
    cout << "Pila ordenada: ";
    s.display();
    return 0;
}
