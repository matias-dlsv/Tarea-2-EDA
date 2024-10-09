#include "image/node.hpp"
#include <iostream>

namespace eda {
    Node::Node(): data(-1), ptrNext(nullptr),visited(false){}

    Node::Node(int val): data(val), ptrNext(nullptr),visited(false){
    }
    int Node::getData(){
        return data;
    }
    void Node::setData(int new_data){
        data = new_data;
    }
    Node* Node::getNext(){
        return ptrNext;
    }
    void Node::setNext(Node* next){
        ptrNext = next;
    }
    void Node::print(){
        std::cout << data;
    }
    bool Node::checkVisited(){
        return visited;
    }
    void Node::getVisited(){
        visited = true;
    }




// Constructor: Inicializa una lista vacía
LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::insertFirst(int val) {
    Node* node = new Node(val);
    
    if (head == nullptr) {  
        head = node;
    } else {
        Node* ptr = head;
        node->setNext(head);
        head = node; 
    }
}
void LinkedList::insertLast(int val) {
    Node* node = new Node(val);
    if (head == nullptr) {  
        head = node;
    } else {
        Node* ptr = head;
        while (ptr->getNext() != nullptr) {
            ptr = ptr->getNext();
        }
        ptr->setNext(node); 
    }
}
void LinkedList::removeFirst() {
    Node* ptr = head;
    if (head != nullptr) {
        head = head->getNext();  
        delete ptr;  
    }
}
void LinkedList::remove(int val) {
    Node* ptr = head;
    Node* ptr_prev = nullptr;  
    while (ptr != nullptr) {
        if (ptr->getData() == val) {  
            if (ptr_prev == nullptr) {  
                head = ptr->getNext();  
                delete ptr;
                ptr = head;
            } else {
                ptr_prev->setNext(ptr->getNext());  
                delete ptr;
                ptr = ptr_prev->getNext();
            }
        } else {
            ptr_prev = ptr;  
            ptr = ptr->getNext();
        }
    }
}
void LinkedList::removeAll() {
    while (head != nullptr) {
        removeFirst(); 
    }
}
Node* LinkedList::find(int val) {
    Node* ptr = head;
    while ((ptr != nullptr) && (ptr->getData() != val)) {
        ptr = ptr->getNext();
    }
    return ptr; 
}
Node* LinkedList::findAtPosition(int n) {
    Node* ptr = head;
    int count = 0;  
    while (ptr != nullptr && count < n) {
        ptr = ptr->getNext();
        count++;
    }
    if (ptr == nullptr) {
        std::cout << "Posición fuera de los límites." << std::endl;
        return nullptr;  
    }
    return ptr; 
}

void LinkedList::print() {
    Node* ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->getData();  // Imprime el valor del nodo
        ptr = ptr->getNext();  // Avanza al siguiente nodo
    } // Indica el final de la lista
}

LinkedList::~LinkedList() {
    removeAll();  // Llama a removeAll() para limpiar la memoria
}

Matrix::Matrix(int h, int w): height(h), width(w) {
    
    matrix = new LinkedList[h];  // Crear un array de listas enlazadas para las filas
    for (int i = 0; i < h; i++) {
        matrix[i] = LinkedList();  // Inicializar cada lista de fila
        for (int j = 0; j < w; j++) {
            matrix[i].insertLast(0);  // Inicializar columnas con ceros
        }
    }
}
void Matrix::setValue(int c, int r, int v) {
    if (r < height && c < width) {
        Node* ptr = matrix[r].findAtPosition(c);
        if (ptr != nullptr) {
            ptr->setData(v);
        }
    }
}
int Matrix::getValue(int r, int c) {
    // Verificar que la posición esté dentro de los límites de la matriz
    if (r < 0 || r >= height || c < 0 || c >= width) {
        std::cerr << "Error: índices fuera de rango" << std::endl;
        return -1;  // Retornar un valor especial o lanzar una excepción
    }
    // Encontrar el nodo en la fila 'r' en la columna 'c'
    Node* node = matrix[r].findAtPosition(c);  // Suponemos que find() devuelve el nodo en la posición 'c'
    if (node != nullptr) {
        return node->getData();
    } else {
        std::cerr << "Error: no se encontró el nodo en la posición especificada" << std::endl;
        return -1;  // Retornar un valor especial si no se encuentra el nodo
    }
}
void Matrix::print() {
    for (int i = 0; i < height; i++) {
        matrix[i].print();  // Imprime cada fila (que es una lista enlazada)
        std::cout << std::endl;  // Para que cada fila aparezca en una nueva línea
    }
}

void Matrix::dfs(int i, int j, int group) {
    // Verifica que (i, j) esté dentro de los límites de la matriz
    if (i < 0 || i >= height || j < 0 || j >= width) {
        return;
    }

    Node* node = matrix[i].findAtPosition(j);
    
    // Si el nodo no es parte del grupo o ya fue visitado, termina
    if (node == nullptr || node->checkVisited() || node->getData() != 1) {
        return;
    }

    // Marca el nodo como visitado y asigna el grupo
    node->getVisited();
    node->setData(group);

    // hace DFS en las 8 direcciones
    dfs(i-1, j, group);   // Arriba
    dfs(i+1, j, group);  // Abajo
    dfs(i, j-1, group);   // Izquierda
    dfs(i, j+1, group);   // Derecha
    dfs(i-1, j-1, group); // Diagonal superior izquierda
    dfs(i-1, j+1, group); // Diagonal superior derecha
    dfs(i+1, j-1, group); // Diagonal inferior izquierda
    dfs(i+1, j+1, group); // Diagonal inferior derecha
}

int Matrix::checkGroups() {
    int group = 1;

    // Recorre todos los nodos de la matriz
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Node* node = matrix[i].findAtPosition(j);
            
            // Si el nodo es parte de una nueva region inicia DFS
            if (node->getData() == 1 && !node->checkVisited()) {
                dfs(i, j, group);
                group++;
              // Incrementa la region 
            }
        }
    }
    return group;
}
void Matrix::getGroups(int totalGroups){
    // Inicializa a 0
    int cantidad[totalGroups] = {0};

    // Recorrer la matriz
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Node* node = matrix[i].findAtPosition(j);

            int group = node->getData();
            if (group != 0 && group < totalGroups) {
                cantidad[group]++;  // Incrementar el contador para ese grupo
            } else if (group >= totalGroups) {
                std::cerr << "Error: Nodo en (" << i << ", " << j << ") tiene un valor de Region fuera del rango: " << group << std::endl;
            }
        }
    }
    // Imprimir los resultados
    for (int i = 1; i < totalGroups; i++) {
        std::cout << "Region " << i << " -> size " << cantidad[i] << std::endl;
    }} 
    void Matrix::printGroups(int group) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Node* node = matrix[i].findAtPosition(j);
            int pixel = node->getData(); 
            if (pixel == group) {
                std::cout << "1";  // Imprimir para el grupo
            } else {
                std::cout << "0";  // Imprimir para el fondo
            }
        }
        std::cout << std::endl;  // Saltar a la siguiente línea de la fila
    }
}
}

