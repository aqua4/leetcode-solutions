class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return nums;
        }
        int x = 0;
        for (int i = 0; i < n; ++i) {
            x ^= nums[i];
        }
        int bit = 1;
        while ((x & bit) == 0) {
            bit <<= 1;
        }
        int ans1 = 0;
        int ans2 = 0;
        for (int i = 0; i < n; ++i) {
            if ((nums[i] & bit)) {
                ans1 ^= nums[i];
            }
            else {
                ans2 ^= nums[i];
            }
        }
        return {ans1, ans2};
    }
};