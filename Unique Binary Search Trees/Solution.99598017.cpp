class Solution {
public:
    int numTrees(int n) {
        int dp[max(n + 1, 3)] = {1, 1, 2};
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};