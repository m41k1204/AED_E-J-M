class Solution {
public:
    vector<int> ch;
    vector<vector<int>> v;
    bool flag;
    void dfs(int a, int p){
        if(ch[a] == 2) return;
        if(ch[a] == 1){
            flag = false;
            return;
        }
        ch[a] = 1;
        for(auto x:v[a]){
            if(ch[x] == 2) continue;
            dfs(x,a);
        }
        ch[a] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> b;
        for(int i = 0;i<numCourses;i++){
            v.push_back(b);
            ch.push_back(0);
        }
        flag = true;
        for(auto x:prerequisites){
            v[x[1]].push_back(x[0]);
        }
        for(int i = 0;i<numCourses;i++){
            dfs(i,-1);
        }
        return flag;
    }
};
