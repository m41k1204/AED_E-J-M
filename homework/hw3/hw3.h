#ifndef HW3_H
#define HW3_H

/*******************************************************************************

MODIFIQUE ESTE ARCHIVO Y LA CORRESPONDIENTE IMPLEMENTACIÓN A SU GUSTO.


Los tests que se usarán para calificar esta tarea serán los provistos en el
archivo de tests y muchos otros. El archivo de tests se incluye solo a modo
de referencia, pero no es una version completa de los tests que serán
utilizados.

Todas las funciones listadas en este archivo serán testeadas por el corrector
automático, con el mismo prototipo mostrado en este archivo.

*******************************************************************************/

template <typename T>
struct BST {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;

        explicit Node(T val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(T const& value, Node*& node);
    bool contains(T const& value, Node* node) const;
    Node* remove(T const& value, Node* node);
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;
    size_t size(Node* node) const;
    void clear(Node*& node);

public:
    BST();
    ~BST();

    void insert(T const& value);
    bool search(T const& value) const;
    void remove(T const& value);
    size_t size() const;
    T findMin() const;
    T findMax() const;
    bool isEmpty() const;
    void clear();
};

#include "hw3_impl.h"

#endif
