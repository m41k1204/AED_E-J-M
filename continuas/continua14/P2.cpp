class Solution {
public:
    vector<vector<int>> v;
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<int> u(n,0);
        for(int i = 0;i<m;i++){
            v.push_back(u);
        }
        for(auto x:walls) v[x[0]][x[1]] = 2;
        for(auto x:guards) v[x[0]][x[1]] = 1;
        for(auto x:guards){
            for(int i = x[0] - 1; i >= 0;i--){
                if(v[i][x[1]] == 2 || v[i][x[1]] == 1) break;
                v[i][x[1]] = 3;
            }
            for(int i = x[0] + 1; i < m;i++){
                if(v[i][x[1]] == 2 || v[i][x[1]] == 1) break;
                v[i][x[1]] = 3;
            }
            for(int i = x[1] - 1; i >= 0;i--){
                if(v[x[0]][i] == 2 || v[x[0]][i] == 1) break;
                v[x[0]][i] = 3;
            }
            for(int i = x[1] + 1; i < n;i++){
                if(v[x[0]][i] == 2 || v[x[0]][i] == 1) break;
                v[x[0]][i] = 3;
            }
        }        
        int res = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(v[i][j] == 0) res++;
            }
        }
        return res;
    }
};
