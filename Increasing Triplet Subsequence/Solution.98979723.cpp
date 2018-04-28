class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        int i = 0;
        while (i < n - 2 && nums[i] >= nums[i + 1]) {
            ++i;
        }
        if (i >= n - 2) {
            return 0;
        }
        int min1 = nums[i];
        int min2 = nums[i + 1];
        int min3 = INT_MAX;
        for (; i < n; ++i) {
            if (nums[i] > min2) {
                return 1;
            }
            if (nums[i] > min1 && nums[i] < min2) {
                min2 = nums[i];
                continue;
            }
            if (nums[i] < min1 && nums[i] < min3) {
                min3 = nums[i];
                continue;
            }
            if (nums[i] < min1 && nums[i] > min3) {
                min1 = min3;
                min2 = nums[i];
            }
        }
        return 0;
    }
};