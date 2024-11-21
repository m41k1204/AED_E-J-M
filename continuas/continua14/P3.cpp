class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int total_water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (left_max > height[left]) {
                    total_water += left_max - height[left];
                } else {
                    left_max = height[left];
                }
                ++left;
            } else {
                if (right_max > height[right]) {
                    total_water += right_max - height[right];
                } else {
                    right_max = height[right];
                }
                --right;
            }
        }
        return total_water;
    }
};
