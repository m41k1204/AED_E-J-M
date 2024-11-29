// Node.hpp
#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <vector>
#include <string>

class Node {
public:
    using Ptr = std::shared_ptr<Node>;

    Node(bool isLeaf, unsigned int bitIndex, const std::vector<bool>& key = {}, const std::string& value = "", Ptr parent = nullptr);

    bool isLeaf;
    unsigned int bitIndex;
    std::vector<bool> key;
    std::string value;
    Ptr left;
    Ptr right;
    Ptr parent;
};

#endif