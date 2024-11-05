#ifndef HW2_H
#define HW2_H

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
struct Heap {
private:
    std::vector<T> cnt;
    bool minHeap;

    size_t get_left_child_idx(const size_t parent_idx) const;
    size_t get_right_child_idx(const size_t parent_idx) const;
    size_t get_parent_idx(const size_t idx) const;
    bool is_root(const size_t idx) const;
    bool has_children(const size_t parent_idx) const;
    bool has_right_child(const size_t parent_idx) const;
    size_t get_select_child_idx(size_t parent_idx) const;
    void percolate_up(size_t idx);
    void percolate_down(size_t idx);

public:
    Heap(bool isMinHeap = true);

    void insert(T const& element);
    T extractTop();
    T peek() const;
    size_t size() const;
    bool isEmpty() const;
    void clear();
};

#include "hw2_impl.h"

#endif
