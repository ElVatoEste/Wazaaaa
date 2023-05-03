#include <iostream>
#include <queue>
using namespace std;

int searchInterpolated(queue<int>* q, int value) {
    int low = 0, high = q->size() - 1;
    while (!q->empty() && low <= high && value >= q->front() && value <= q->back()) {
        int pos = low + ((value - q->front()) * (high - low)) / (q->back() - q->front());
        int mid = q->size() / 2;
        int count = 0;
        queue<int>* tempQ = new queue<int>;
        while (!q->empty()) {
            if (count == mid) {
                if (q->front() == value) {
                    return pos;
                }
                break;
            }
            tempQ->push(q->front());
            q->pop();
            count++;
        }
        if (q->empty()) {
            break;
        }
        if (q->front() == value) {
            delete tempQ;
            return pos;
        }
        else if (q->front() < value) {
            low = pos + 1;
            while (!tempQ->empty()) {
                q->push(tempQ->front());
                tempQ->pop();
            }
        }
        else {
            high = pos - 1;
            while (!tempQ->empty()) {
                tempQ->pop();
            }
        }
        delete tempQ;
    }
    return -1;
}

int main() {
    queue<int>* q = new queue<int>;
    int n, num, value;
    cout << "Ingrese la cantidad de elementos de la cola: ";
    cin >> n;
    cout << "Ingrese los elementos de la cola separados por espacios: \n";
    for (int i = 0; i < n; i++) {
        cin >> num;
        q->push(num);
    }
    cout << "Ingrese el valor a buscar: ";
    cin >> value;
    int index = searchInterpolated(q, value);
    if (index == -1) {
        cout << "El valor no se encuentra en la cola." << endl;
    }
    else {
        cout << "El valor se encuentra en la posicion " << index << " de la cola." << endl;
    }
    return 0;
}
