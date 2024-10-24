class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output = "";
        TrieNode* root = new TrieNode();
        for (auto s: strs) {
            if (s == "") return output;
            insert(root, s);
        }
        while (true) {
            char letter = getChild(root);
            if (letter == '$') return output;
            output.push_back(letter);
            int index = letter - 'a';
            root = root -> children[index];
        }
        return output;


    }

    struct TrieNode {
        std::array<TrieNode*, 26> children;
        bool isFinal = false;
        TrieNode() {
            children.fill(nullptr);
        }
    };
    void insert(TrieNode* root, string &word) {
        for (auto c: word) {
            int index = c - 'a';
            if (root -> children[index] == nullptr) {
                root -> children[index] = new TrieNode();
            }
            root = root -> children[index];
        }
        root -> isFinal = true;
    }

    char getChild(TrieNode* root) {
        char letter = '$';
        int amount = 0;
        for (int i = 0; i < 26; i++) {
            if (root -> children[i] != nullptr && !root -> isFinal) {
                letter = 'a' + i;
                amount++;
            }
        }
        if (amount == 1) return letter;
        return '$';
    }

};


