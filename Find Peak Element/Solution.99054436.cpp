class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || nums[0] > nums[1]) {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        int l = 1;
        int r = n - 2;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[m - 1]) {
                if (nums[m] > nums[m + 1]) {
                    return m;
                }
                l = m + 1;
                continue;
            }
            r = m - 1;
        }
    }
};