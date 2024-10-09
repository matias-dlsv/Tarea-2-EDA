#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

namespace eda {
class Node {
public:
    Node();
    Node(int val);
    int getData();
    void setData(int val);
    Node* getNext();
    void setNext(Node* nextNode);
    bool checkVisited();
    void getVisited();

    void print();
private:
    int data;  // Valor del nodo
    Node* ptrNext;  // Puntero al siguiente nodo
    bool visited; 

};


class LinkedList {
public:
    // Constructor: Inicializa una lista vacía
    LinkedList();
    // Inserta un nodo al principio de la lista
    void insertFirst(int val);
    // Inserta un nodo al final de la lista
    void insertLast(int val);
    // Elimina el primer nodo de la lista
    void removeFirst();
    // Elimina un nodo que contiene el valor especificado
    void remove(int val);
    // Elimina todos los nodos de la lista
    void removeAll();
    // Busca un nodo con un valor específico
    Node* find(int val);
    Node* findAtPosition(int val);
    // Imprime todos los nodos de la lista
    void print();
    // Destructor: limpia toda la memoria usada
    ~LinkedList();

private:
    Node* head;  // Puntero al primer nodo de la lista
};

class Matrix {
    private:
        LinkedList* matrix; // Array de listas enlazadas para las filas
        int height;
        int width;

    public:
        Matrix(int h, int w);
        void setValue(int r, int c, int v);
        int getValue(int r, int c); 
        void print();
        int checkGroups();
        void getGroups(int totalGroups); 
        void dfs(int i, int j, int group);
        void printGroups(int group);

    }; 
}
#endif 
