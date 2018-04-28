class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        auto it = nums.begin() + n / 2;
        int ans = 0;
        nth_element(nums.begin(), it, nums.end());
        for (int i = 0; i < n; ++i) {
            ans += abs(nums[i] - *it);
        }
        return ans;
    }
};