const int MAX = 2e5+5;

typedef long long int ll;

class Solution {
public:
    int col[MAX];
    int k;
    vector<vector<int>> ed;
    void dfs(int p, int a){
        if(col[a] != -1) return;
        col[a] = k;
        for(auto x:ed[a]){
            if(p == x) continue;
            dfs(a,x);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        k = 0;
        vector<int> v0;
        ll cont[MAX];
        for(int i=0;i<n;i++){
            ed.push_back(v0);
            col[i] = -1;
            cont[i] = 0;
        }
        for(auto x:edges){
            ed[x[0]].push_back(x[1]);
            ed[x[1]].push_back(x[0]);
        }

        for(int i=0;i<n;i++){
            if(col[i]!=-1) continue;
            dfs(-1,i);
            k++;
        }

        for(int i = 0;i<n;i++){
            cont[col[i]]++;
        }
        ll m = n;
        ll res = m * m;
        for(int i = 0;i<k;i++){
            cout<<cont[i]<<endl;
            res-=cont[i]*cont[i];
        } 

        return res/2;
    }
};
