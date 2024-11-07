class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        std::set<int> s;
        for (int i = 0; i < trust.size(); i++) {
            s.insert(trust[i][0]);
        }
        if (s.size() != n-1) return -1;
        int judge = 0;
        for (int i = 1; i <= n; ++i) {
            if (s.find(i) == s.end()) judge = i;
        }
        int count = 0;
        for (int i = 0; i < trust.size(); ++i) {
            if (trust[i][1] == judge) ++count;
        }
        cout << judge << endl;
        if (count == n-1) return judge;
        return -1;
    }
};
