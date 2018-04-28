class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ma = -1;
        int ind = 0;
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        for (int i = 0; i < n * 2 - 1; ++i) {
            cur += (gas[i] - cost[i]);
            if (ma <= cur) {
                ma = cur;
                ans = ind;
            } 
            if (cur < 0) {
                cur = 0;
                ind = i + 1;
            }
        }
        cur = 0;
        for (int i = ans; i < n; ++i) {
            cur += (gas[i] - cost[i]);
        }
        for (int i = 0; i < ans; ++i) {
            cur += (gas[i] - cost[i]);
        }
        return cur < 0 ? -1 : ans;
    }
};