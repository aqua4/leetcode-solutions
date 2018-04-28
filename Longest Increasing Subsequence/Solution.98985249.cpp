class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> l;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(l.begin(), l.end(), nums[i]);
            if (it == l.end()) {
                l.push_back(nums[i]);
                continue;
            }
            *it = nums[i];
        }
        return l.size();
    }
};