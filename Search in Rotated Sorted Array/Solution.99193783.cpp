class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) {
            return -1;
        }
        if (nums[0] < nums.back()) {
            auto it = lower_bound(nums.begin(), nums.end(), target);
            if (it == nums.end() || *it != target) return -1;
            return it - nums.begin();
        }
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[r] == target) {
                return r;
            }
            if (nums[l] == target) {
                return l;
            }
            if (nums[m] > target) {
                if (nums[m] <= nums[r]) {
                    r = m - 1;
                    continue;
                }
                if (nums[m] >= nums[l]) {
                    if (nums[l] < target) {
                        r = m - 1;
                        continue;
                    }
                    l = m + 1;
                    continue;
                }
            }
            if (nums[l] <= nums[m]) {
                l = m + 1;
                continue;
            }
            if (target < nums[r]) {
                l = m + 1;
                continue;
            }
            r = m - 1;
        }
        return -1;
    }
};