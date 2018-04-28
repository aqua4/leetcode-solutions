class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n<2) return 0;
        int ans = 0;
        int mi = prices[0];
        for (int i=1;i<n;i++) {
            mi = min(mi,prices[i]);
            if (prices[i]>mi && ((i<n-1 && prices[i+1]<prices[i]) || i==n-1)) {
                ans+=prices[i]-mi;
                mi = prices[i];
            }
        }
        return ans;
    }
};