class Solution {
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (const std::string& word : wordDict) {
            insert(root, word);
        }
        std::unordered_map<int, std::vector<std::string>> memo;
        std::vector<std::string> result = dfs(s, 0, root, memo);
        deleteTrie(root);
        return result;
    }

private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;

        TrieNode() : isEndOfWord(false) {
            for (auto& child : children) {
                child = nullptr;
            }
        }
    };

    void insert(TrieNode* root, const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    void deleteTrie(TrieNode* node) {
        if (node == nullptr) return;
        for (auto child : node->children) {
            deleteTrie(child);
        }
        delete node;
    }

    std::vector<std::string> dfs(const std::string& s, int start, TrieNode* root,
                                 std::unordered_map<int, std::vector<std::string>>& memo) {
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        std::vector<std::string> results;
        int n = s.length();
        if (start == n) {
            results.push_back("");     
            return results;
        }
        TrieNode* node = root;
        for (int end = start; end < n; ++end) {
            char ch = s[end];
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                break; 
            }
            node = node->children[index];
            if (node->isEndOfWord) {
                std::vector<std::string> sublist = dfs(s, end + 1, root, memo);
                std::string word = s.substr(start, end - start + 1);
                for (const std::string& sub : sublist) {
                    std::string space = sub.empty() ? "" : " ";
                    results.push_back(word + space + sub);
                }
            }
        }
        memo[start] = results;
        return results;
    }
};


