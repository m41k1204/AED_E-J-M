class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int sz = nums.size();
        vector<int> result;
        for (int i = 0; i < sz ; i += 2) {
            for (int j = 0; j < nums[i]; j++) {
                result.push_back(nums[i+1]);
            }
        }
        return result;
    }
};
