class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        bool hash[200001] = {0};
        int n = candies.size();
        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (!hash[candies[i] + 100000]) {
                ++diff;
            }
            hash[candies[i] + 100000] = 1;
        }
        return min(diff, n / 2);
    }
};