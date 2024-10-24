
struct TrieNode {
    std::array<TrieNode*, 26> children;
    TrieNode* parent;
    bool isFinal = false;
    TrieNode() : parent(nullptr) {
        children.fill(nullptr); 
    }
    void addNode(TrieNode* node, int index) {
        children[index] = node;
    }
};

class Trie {

public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        insertHelper(word, root);
    }
    
    void insertHelper(string &word, TrieNode* node) {
        if (word.size() == 0) {
            node->isFinal = true;
            return;
        }

        int index = word[0] - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }

        insertHelper(word.erase(0,1), node->children[index]);
    }
    
    bool search(string word) {
        return searchHelper(word, root);
    }

    bool searchHelper(string &word, TrieNode* node) {
        if (word.size() == 0) {
            return node->isFinal;
        }

        int index = word[0] - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }

        return searchHelper(word.erase(0,1), node->children[index]);
    }
    
    bool startsWith(string prefix) {
        return startWithHelper(prefix, root);
    }

    bool startWithHelper(string &prefix, TrieNode* node) {
        if (prefix.size() == 0) return true;
        

        int index = prefix[0] - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }

        return startWithHelper(prefix.erase(0, 1), node->children[index]);
    }
};
