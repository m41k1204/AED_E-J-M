struct Node{
    bool ends;
    vector<Node*> v;
    Node(){
        ends = false;
        for(int i = 0;i<26;i++){
            v.push_back(nullptr);
        }
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node* ptr = root;
        for(auto x:s){
            if(ptr->v[x-'a'] == nullptr) ptr->v[x-'a'] = new Node();
            ptr = ptr->v[x-'a'];
        }
        ptr->ends = true;
    }
    bool search(string s){
        Node* ptr = root;
        for(auto x:s){
            if(ptr->v[x-'a'] == nullptr) return false;
            ptr = ptr->v[x-'a'];
        }
        return ptr->ends;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie tr;
        for(auto x:wordDict){
            reverse(x.begin(),x.end());
            tr.insert(x);
        }
        vector<string> dp[305];
        dp[0].push_back("");
        int n = s.size();
        for(int i=0;i<n;i++){
            string s0 = "";
            for(int j=i;j>=0;j--){
                s0+=s[j];
                if(!tr.search(s0)) continue;
                string s1 = s0;
                reverse(s1.begin(),s1.end());
                for(auto x:dp[i+1 - s0.size()]){
                    dp[i+1].push_back((x == "") ? s1 : x+" "+s1);
                }
            }
        }
        
        return dp[n];
    }
};

