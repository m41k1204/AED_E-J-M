// PatriciaTree.cpp
#include "PatriciaTree.hpp"

PatriciaTree::PatriciaTree() : root(nullptr) {}

PatriciaTree::~PatriciaTree() {
    makeEmpty();
}

bool PatriciaTree::getBit(const std::vector<bool>& key, unsigned int bitIndex) const {
    if (bitIndex >= key.size()) {
        return false;
    }
    return key[bitIndex];
}

unsigned int PatriciaTree::firstDifferentBit(const std::vector<bool>& key1, const std::vector<bool>& key2) const {
    unsigned int maxLength = std::max(key1.size(), key2.size());
    for (unsigned int i = 0; i < maxLength; ++i) {
        bool bit1 = i < key1.size() ? key1[i] : false;
        bool bit2 = i < key2.size() ? key2[i] : false;
        if (bit1 != bit2) {
            return i;
        }
    }
    return maxLength;
}

void PatriciaTree::insert(const std::vector<bool>& key, const std::string& value) {
    if (!root) {
        root = std::make_shared<Node>(true, 0, key, value);
        return;
    }

    Node::Ptr parent = nullptr;
    Node::Ptr current = root;

    while (!current->isLeaf && current->bitIndex < key.size()) {
        parent = current;
        if (getBit(key, current->bitIndex)) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if (current->key == key) {
        // La clave ya existe, actualizamos el valor
        current->value = value;
        return;
    }

    unsigned int diffBit = firstDifferentBit(key, current->key);
    Node::Ptr newLeaf = std::make_shared<Node>(true, diffBit, key, value, parent);
    Node::Ptr newInternal = std::make_shared<Node>(false, diffBit, std::vector<bool>(), "", parent);

    if (getBit(key, diffBit)) {
        newInternal->left = current;
        newInternal->right = newLeaf;
    } else {
        newInternal->left = newLeaf;
        newInternal->right = current;
    }

    current->parent = newInternal; // Actualizar el puntero al nodo padre
    newLeaf->parent = newInternal; // Actualizar el puntero al nodo padre

    if (!parent) {
        root = newInternal;
    } else if (parent->left == current) {
        parent->left = newInternal;
    } else {
        parent->right = newInternal;
    }
}

bool PatriciaTree::search(const std::vector<bool>& key, std::string& value) const {
    if (!root) {
        return false;
    }

    Node::Ptr current = root;
    while (!current->isLeaf && current->bitIndex < key.size()) {
        if (getBit(key, current->bitIndex)) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if (current->key == key) {
        value = current->value;
        return true;
    }

    return false;
}

bool PatriciaTree::remove(const std::vector<bool>& key) {
    if (!root) {
        return false;
    }

    Node::Ptr parent = nullptr;
    Node::Ptr current = root;

    while (!current->isLeaf && current->bitIndex < key.size()) {
        parent = current;
        if (getBit(key, current->bitIndex)) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    if (current->key != key) {
        // La clave no existe
        return false;
    }

    if (!parent) {
        // Eliminando la raíz
        root = nullptr;
    } else {
        Node::Ptr sibling = (parent->left == current) ? parent->right : parent->left;
        if (!parent->parent) {
            // El padre es la raíz
            root = sibling;
        } else {
            if (parent->parent->left == parent) {
                parent->parent->left = sibling;
            } else {
                parent->parent->right = sibling;
            }
        }
        sibling->parent = parent->parent; // Actualizar el puntero al nodo padre
    }

    return true;
}

bool PatriciaTree::isEmpty() const {
    return root == nullptr;
}

void PatriciaTree::makeEmpty() {
    deleteSubtree(root);
    root = nullptr;
}

void PatriciaTree::deleteSubtree(Node::Ptr node) {
    if (node) {
        deleteSubtree(node->left);
        deleteSubtree(node->right);
        node->left = nullptr;
        node->right = nullptr;
    }
}