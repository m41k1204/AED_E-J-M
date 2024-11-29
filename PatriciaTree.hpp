// PatriciaTree.hpp
#ifndef PATRICIATREE_HPP
#define PATRICIATREE_HPP

#include "Node.hpp"

class PatriciaTree {
public:
    PatriciaTree();
    ~PatriciaTree();

    void insert(const std::vector<bool>& key, const std::string& value);
    bool search(const std::vector<bool>& key, std::string& value) const;
    bool remove(const std::vector<bool>& key);
    bool isEmpty() const;
    void makeEmpty();

private:
    Node::Ptr root;

    bool getBit(const std::vector<bool>& key, unsigned int bitIndex) const;
    unsigned int firstDifferentBit(const std::vector<bool>& key1, const std::vector<bool>& key2) const;
    void deleteSubtree(Node::Ptr node);
};

#endif // PATRICIATREE_HPP
