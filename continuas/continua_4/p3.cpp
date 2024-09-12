class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> v;
        for(int i = 0;i<gas.size();i++){
            v.push_back(gas[i] - cost[i]);
        }
        int r = 0;
        for(auto x:v){
            r+=x;
        }
        if(r<0) return -1;
        r = 0;
        int res = 0;
        bool x = true;
        for(int i = 0;i<v.size();i++){
            r+=v[i];
            if(r < 0){
                res = -1;
                r = 0;
                x = true;
            }
            else{
                if(x && v[i] > 0){
                    res = i;
                    x = false;
                }
            }
            cout<<r<<" "<<res<<endl;
        }
        return res;
    }
};


