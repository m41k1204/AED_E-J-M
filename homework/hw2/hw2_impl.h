#ifndef HW2_IMPL_H
#define HW2_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "hw2.h"

// Heap

template <typename T>
Heap<T>::Heap(bool isMinHeap) : minHeap(isMinHeap) {
  // COMPLETE HERE
}

template <typename T>
void Heap<T>::insert(T const& element) {
  // COMPLETE HERE
    cnt.push_back(element);
    percolate_up(cnt.size() - 1);
}

template <typename T>
T Heap<T>::extractTop() {
    if (cnt.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    std::swap(cnt[0], cnt[cnt.size() - 1]);
    T top_element = cnt.back();
    cnt.pop_back();
    percolate_down(0);
    return top_element;
}

template <typename T>
T Heap<T>::peek() const {
    if (cnt.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return cnt[0];
}

template <typename T>
size_t Heap<T>::size() const {
    return cnt.size();
}

template <typename T>
bool Heap<T>::isEmpty() const {
    return cnt.empty();
}


template <typename T>
void Heap<T>::clear() {
    cnt.clear();
}

//Funciones privadas

template <typename T>
size_t Heap<T>::get_left_child_idx(const size_t parent_idx) const {
    return parent_idx * 2 + 1;
}

template <typename T>
size_t Heap<T>::get_right_child_idx(const size_t parent_idx) const {
    return parent_idx * 2 + 2;
}

template <typename T>
size_t Heap<T>::get_parent_idx(const size_t idx) const {
    return (idx - 1) / 2;
}

template <typename T>
bool Heap<T>::is_root(const size_t idx) const {
    return idx == 0;
}

template <typename T>
bool Heap<T>::has_children(const size_t parent_idx) const {
    return get_left_child_idx(parent_idx) < cnt.size();
}

template <typename T>
bool Heap<T>::has_right_child(const size_t parent_idx) const {
    return get_right_child_idx(parent_idx) < cnt.size();
}

template <typename T>
size_t Heap<T>::get_select_child_idx(size_t parent_idx) const {
    auto left_child_idx = get_left_child_idx(parent_idx);
    if (has_right_child(parent_idx)) {
        auto right_child_idx = get_right_child_idx(parent_idx);
        return minHeap ? (cnt[left_child_idx] < cnt[right_child_idx] ? left_child_idx : right_child_idx)
                       : (cnt[left_child_idx] > cnt[right_child_idx] ? left_child_idx : right_child_idx);
    }
    return left_child_idx;
}

template <typename T>
void Heap<T>::percolate_up(size_t idx) {
    while (!is_root(idx)) {
        auto parent_idx = get_parent_idx(idx);
        if (minHeap ? cnt[idx] >= cnt[parent_idx] : cnt[idx] <= cnt[parent_idx]) return;
        std::swap(cnt[idx], cnt[parent_idx]);
        idx = parent_idx;
    }
}

template <typename T>
void Heap<T>::percolate_down(size_t idx) {
    while (has_children(idx)) {
        auto select_child_idx = get_select_child_idx(idx);
        if (minHeap ? cnt[idx] <= cnt[select_child_idx] : cnt[idx] >= cnt[select_child_idx]) return;
        std::swap(cnt[idx], cnt[select_child_idx]);
        idx = select_child_idx;
    }
}

#endif
