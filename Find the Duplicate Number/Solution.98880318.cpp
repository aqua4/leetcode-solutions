class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            int c = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= m) {
                    ++c;
                }
            }
            if (c > m) {
                r = m - 1;
                continue;
            }
            if (c <= m) {
                l = m + 1;
            }
        }
        return l;
    }
};