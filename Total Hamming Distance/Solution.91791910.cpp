class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int dist = 0;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                count += ((nums[j] & (1<<i)) != 0);
            }
            dist += count * (n - count);
        }
        return dist;
    }
};