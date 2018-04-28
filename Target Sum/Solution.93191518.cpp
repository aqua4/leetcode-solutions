class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if (!n || abs(S) > 1000) {
            return 0;
        }
        if (n == 1) {
            int c = 0;
            if (nums[0] == S) ++c;
            if (-nums[0] == S) ++c;
            return c;
        }
        int ways[2001] = {0};
        ways[1000 + nums[0]] = 1;
        ++ways[1000 - nums[0]];
        for (int i = 1; i < n; ++i) {
            int temp[2001];
            for (int j = 0; j < 2001; ++j) {
                temp[j] = ways[j];
            }
            for (int j = 0; j < 2001; ++j) {
                ways[j] = 0;
                if (j - nums[i] >= 0) {
                    ways[j] = temp[j - nums[i]];
                }
                if (j + nums[i] <= 2000) {
                    ways[j] += temp[j + nums[i]];
                }
            }
        }
        return ways[S + 1000];
    }
};