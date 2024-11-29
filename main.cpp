// main.cpp
#include "PatriciaTree.hpp"
#include <iostream>

std::vector<bool> stringToBits(const std::string& str) {
    std::vector<bool> bits;
    for (char c : str) {
        for (int i = 7; i >= 0; --i) {
            bits.push_back((c >> i) & 1);
        }
    }
    return bits;
}

int main() {
    PatriciaTree tree;

    // Claves y valores de ejemplo
    std::string key1 = "apple";
    std::string key2 = "app";
    std::string key3 = "banana";
    std::string key4 = "band";
    std::string key5 = "bandana";

    tree.insert(stringToBits(key1), "Fruta roja o verde");
    tree.insert(stringToBits(key2), "Aplicación o programa");
    tree.insert(stringToBits(key3), "Fruta amarilla");
    tree.insert(stringToBits(key4), "Grupo musical");
    tree.insert(stringToBits(key5), "Accesorio de vestir");

    std::string value;
    if (tree.search(stringToBits("app"), value)) {
        std::cout << "Valor encontrado para 'app': " << value << std::endl;
    } else {
        std::cout << "Clave 'app' no encontrada." << std::endl;
    }

    // Eliminar una clave
    tree.remove(stringToBits("band"));

    if (tree.search(stringToBits("band"), value)) {
        std::cout << "Valor encontrado para 'band': " << value << std::endl;
    } else {
        std::cout << "Clave 'band' no encontrada (eliminada)." << std::endl;
    }

    // Verificar si el árbol está vacío
    if (tree.isEmpty()) {
        std::cout << "El árbol está vacío." << std::endl;
    } else {
        std::cout << "El árbol no está vacío." << std::endl;
    }

    // Vaciar el árbol
    tree.makeEmpty();

    if (tree.isEmpty()) {
        std::cout << "El árbol ha sido vaciado." << std::endl;
    } else {
        std::cout << "El árbol aún contiene elementos." << std::endl;
    }

    return 0;
}
