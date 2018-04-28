class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (!nums[i]) {
                ++zeros;
                continue;
            }
            if (nums[i] == 1) {
                ++ones;
            }
        }
        for (int i = 0; i < zeros; ++i) {
            nums[i] = 0;
        }
        for (int i = zeros; i < ones + zeros; ++i) {
            nums[i] = 1;
        }
        for (int i = ones + zeros; i < nums.size(); ++i) {
            nums[i] = 2;
        }
    }
};