class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary(){
        deleteTrie(root);
    }
    void addWord(const std::string& word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if (!node -> children [index]){
                node -> children [index] = new TrieNode();
            }
            node = node -> children [index];
        }
        node -> isEndOfWord = true;
    }
    
    bool search(const std::string& word) {
        return searchHelper(word, 0, root);
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

    TrieNode* root;

    bool searchHelper(const std::string& word, int index, TrieNode* node){
        if(!node) return false;
        if (index== word.length()){
            return node -> isEndOfWord;
        }
        char ch = word[index];
        if(ch != '.'){
            int idx = ch - 'a';
            return searchHelper(word, index + 1, node -> children[idx]);
        }
        else {
            for(int i = 0; i<26; ++i){
                if(node -> children[i]){
                    if (searchHelper(word, index + 1, node -> children[i])){
                        return true;
                    }
                }
            }
            return false;
        }
    }

    void deleteTrie(TrieNode* node){
        if (!node) return;
        for (auto child : node -> children){
            deleteTrie(child);
        }
        delete node;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
