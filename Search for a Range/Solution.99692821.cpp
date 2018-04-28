class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        if (l == nums.end() || *l != target) {
            return {-1, -1};
        }
        vector<int> ans(2);
        ans[0] = l - nums.begin();
        ans[1] = upper_bound(l, nums.end(), target) - nums.begin() - 1;
        return ans;
    }
};