#define pii pair<int,int>

class Solution {
public:
    int m,n;
    vector<int> adj(int i){
        vector<int> res;
        if(i >= n) res.push_back(i-n);
        if(i < m*n-n) res.push_back(i+n);
        if(i % n != 0) res.push_back(i-1);
        if(i % n != n-1) res.push_back(i+1);
        return res;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        deque<pii> q;
        vector<vector<int>> dp;
        vector<int> v(n,-1);
        for(int i = 0;i<m;i++){
            dp.push_back(v);
        }
        q.push_front({0,grid[0][0]});
        //i / n
        //i % n
        while(!q.empty()){
            pii p = q.front();
            q.pop_front();
            int x = p.first;
            if(dp[x / n][x % n] != -1) continue;
            dp[x / n][x % n] = p.second;
            for(auto y:adj(x)){
                if(dp[y / n][y % n] != -1) continue;
                if(grid[y/n][y%n]){
                    q.push_back({y,dp[x/n][x%n] + grid[y/n][y%n]});
                }
                else {
                    q.push_front({y,dp[x/n][x%n] + grid[y/n][y%n]});
                }
            }
        }
        return dp[m-1][n-1];
    }
};
