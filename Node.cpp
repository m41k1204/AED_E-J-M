// Node.cpp
#include "Node.hpp"

Node::Node(bool isLeaf, unsigned int bitIndex, const std::vector<bool>& key, const std::string& value, Ptr parent)
    : isLeaf(isLeaf), bitIndex(bitIndex), key(key), value(value), left(nullptr), right(nullptr), parent(parent) {}