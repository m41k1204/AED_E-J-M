#ifndef HW3_IMPL_H
#define HW3_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include "hw3.h"

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    clear();
}

template <typename T>
void BST<T>::insert(T const& value) {
    insert(value, root);
}

template <typename T>
bool BST<T>::search(T const& value) const {
    return contains(value, root);
}

template <typename T>
void BST<T>::remove(T const& value) {
    root = remove(value, root);
}

template <typename T>
size_t BST<T>::size() const {
    return size(root);
}

template <typename T>
T BST<T>::findMin() const {
    if (root == nullptr) {
        throw std::runtime_error("BST is empty");
    }
    return findMin(root)->value;
}

template <typename T>
T BST<T>::findMax() const {
    if (root == nullptr) {
        throw std::runtime_error("BST is empty");
    }
    return findMax(root)->value;
}

template <typename T>
bool BST<T>::isEmpty() const {
    return root == nullptr;
}

template <typename T>
void BST<T>::clear() {
    clear(root);
}

// Private functions

template <typename T>
typename BST<T>::Node* BST<T>::findMin(Node* node) const {
    if (node == nullptr) {
        return nullptr;
    }
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::findMax(Node* node) const {
    if (node == nullptr) {
        return nullptr;
    }
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

template <typename T>
void BST<T>::insert(T const& value, Node*& node) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value < node->value) {
        insert(value, node->left);
    } else if (value > node->value) {
        insert(value, node->right);
    }
}

template <typename T>
bool BST<T>::contains(T const& value, Node* node) const {
    if (node == nullptr) {
        return false;
    }
    if (value == node->value) {
        return true;
    } else if (value < node->value) {
        return contains(value, node->left);
    } else {
        return contains(value, node->right);
    }
}

template <typename T>
typename BST<T>::Node* BST<T>::remove(T const& value, Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (value < node->value) {
        node->left = remove(value, node->left);
    } else if (value > node->value) {
        node->right = remove(value, node->right);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->value = temp->value;
        node->right = remove(temp->value, node->right);
    }
    return node;
}

template <typename T>
size_t BST<T>::size(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return 1 + size(node->left) + size(node->right);
}

template <typename T>
void BST<T>::clear(Node*& node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }
}

#endif