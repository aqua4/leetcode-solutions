class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0,mi=2100000009,ma=-1;
        for (int i=0;i<prices.size();i++) {
            mi=min(mi,prices[i]);
            if (prices[i]>mi) profit=max(profit,prices[i]-mi);
        }
        return profit;
    }
};