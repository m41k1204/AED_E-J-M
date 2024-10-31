
const int MAX = 1e5+5;

class Solution {
public:
    int parent[MAX];
    int pr[MAX];
    int pv[MAX];
        
    int findParent(int a){
        if(parent[a] == a) return a;
        if(parent[a] == -1) return -1;
        return findParent(parent[a]);
    }
    int findR(int a){
        if(pr[a] == a) return a;
        if(pr[a] == -1) return -1;
        return findR(pr[a]);
    }
    
    int findV(int a){
        if(pv[a] == a) return a;
        if(pv[a] == -1) return -1;
        return findV(pv[a]);
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int cont[5];
        vector<vector<int>> v[5];
        int res = 0;
        for(int i = 0;i<n;i++){
            parent[i] = -1;
            pr[i] = -1;
            pv[i] = -1;
            
        }
        for(auto x:edges){
            v[x[0]].push_back({x[1]-1,x[2]-1});
        }

        for(auto x:v[3]){
            int p1 = findParent(x[0]);
            int p2 = findParent(x[1]);
            parent[x[0]] = p1;
            parent[x[1]] = p2;
            if(p1 == -1 && p2 == -1){
                parent[x[0]] = x[0];
                parent[x[1]] = x[0];
                res++;
            }
            if(p1 == p2) continue;
            if(p1 == -1){
                parent[x[0]] = p2;
                res++;
            }
            else if(p2 == -1){
                parent[x[1]] = p1;
                res++;
            }
            else {
                parent[parent[x[0]]] = p2;
                res++;
            }
        }
        for(int i = 0;i<n;i++){
            pr[i] = parent[i];
            pv[i] = parent[i];
        }
        
        for(auto x:v[1]){
            int p1 = findR(x[0]);
            int p2 = findR(x[1]);
            pr[x[0]] = p1;
            pr[x[1]] = p2;
            if(p1 == -1 && p2 == -1){
                pr[x[0]] = x[0];
                pr[x[1]] = x[0];
                res++;
            }
            if(p1 == p2) continue;
            if(p1 == -1){
                pr[x[0]] = p2;
                res++;
            }
            else if(p2 == -1){
                pr[x[1]] = p1;
                res++;
            }
            else {
                pr[pr[x[0]]] = p2;
                res++;
            }
        }
        
        for(auto x:v[2]){
            int p1 = findV(x[0]);
            int p2 = findV(x[1]);
            pv[x[0]] = p1;
            pv[x[1]] = p2;
            if(p1 == -1 && p2 == -1){
                pv[x[0]] = x[0];
                pv[x[1]] = x[0];
                res++;
            }
            if(p1 == p2) continue;
            
            if(p1 == -1){
                pv[x[0]] = p2;
                res++;
            }
            else if(p2 == -1){
                pv[x[1]] = p1;
                res++;
            }
            else {
                pv[pv[x[0]]] = p2;
                res++;
            }
        }
        int kr = findR(0);
        int kv = findR(0);
        for(int i = 0;i<n;i++){
            if(kr != findR(i)) return -1;
            if(kv != findV(i)) return -1;
            
        }
        return edges.size() - res;
    }
};
