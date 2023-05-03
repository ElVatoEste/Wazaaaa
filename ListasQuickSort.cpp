#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node** head, int value) {  
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {  
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* getLastNode(Node* head) {   
    while (head != nullptr && head->next != nullptr) {
        head = head->next;
    }
    return head;   
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {   
    Node* pivot = end;  
    Node* prev = nullptr;
    Node* current = head;
    Node* tail = pivot;  
    
    while (current != pivot) {
        if (current->data < pivot->data) {   
            if (*newHead == nullptr) {
                *newHead = current;
            }
            prev = current;
            current = current->next;
        } else {   
            if (prev != nullptr) {
                prev->next = current->next;
            }
            Node* tmp = current->next;
            current->next = nullptr;
            tail->next = current;
            tail = current;
            current = tmp;
        }
    }
    if (*newHead == nullptr) {   
        *newHead = pivot;
    }
    *newEnd = tail;   
    return pivot;   
}

Node* quickSort(Node* head, Node* end) {   
    if (head == nullptr || head == end) {   
        return head;
    }
    Node* newHead = nullptr;
    Node* newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);   
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        newHead = quickSort(newHead, tmp);   
        tmp = getLastNode(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSort(pivot->next, newEnd);   
    return newHead;
}

int main() {
    Node* head = nullptr;
    int numNodes = 0;
    cout << "Ingrese el numero de datos: ";
    cin >> numNodes;
    for (int i = 0; i < numNodes; i++) {
        int num;
        cout << "Ingrese el valor del nodo " << i+1 << ": ";
        cin >> num;
        insertNode(&head, num);
    }
    cout << "Lista original: ";
    printList(head);
    head = quickSort(head, getLastNode(head));
    cout << "Lista ordenada: ";
    printList(head);
    return 0;
}
