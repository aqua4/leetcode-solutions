class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if (!n) {
            return 0;
        }
        int ans = duration;
        for (int i = 0; i < n - 1; ++i) {
            ans += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        return ans;
    }
};