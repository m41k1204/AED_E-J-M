class Solution {
public:
    vector<vector<int>> res;
    vector<int> c;
    int tar;
    void back(vector<int> v, int a){
        if(a > tar) return;
        if(a == tar) res.push_back(v);
        int l = 0;
        if(!v.empty()) l = v[v.size() - 1];
        for(auto x:c){
            if(x < l) continue;
            v.push_back(x);
            back(v,a+x);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        swap(c,candidates);
        swap(target,tar);
        vector<int> v;
        back(v,0);
        return res;
    }
};
