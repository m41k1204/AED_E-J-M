class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> freq(254,0);
        int l = 0;
        int r = 0;

        for (auto c:s){
            freq[(int) c] ++;
            while (freq[(int)c]>1){
                freq[(int) s[l]] --;
                l++;
            }
            ans = max (ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
