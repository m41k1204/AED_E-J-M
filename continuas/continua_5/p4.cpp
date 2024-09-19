class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table;
        
        for(int i = 0; i < strs.size(); i++) {
            string palabra = strs[i];
            sort(palabra.begin(), palabra.end());
            if (table.contains(palabra)) {
                table.find(palabra) -> second.push_back(strs[i]);
            } else {
                vector<string> temp = {strs[i]};
                table[palabra] = temp;
            }
        }

        vector<vector<string>> vec;
        for (auto it = table.begin(); it != table.end(); it++) {
            vec.push_back(it->second );
        }
        return vec;
    }
};
