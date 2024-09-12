#include <stack>
#include <vector>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        std::stack<int> st;
        int third = 0;  
        bool k = false;  

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (k && nums[i] < third) {
                return true;
            }

            while (!st.empty() && nums[i] > st.top()) {
                third = st.top(); 
                st.pop();
                k = true;  
            }

            st.push(nums[i]);
        }

        return false;  
    }
};
