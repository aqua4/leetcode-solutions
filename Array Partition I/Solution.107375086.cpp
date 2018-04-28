class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        int map[20001] = {0};
        for (int i = 0; i < n; ++i) {
            ++map[nums[i] + 10000];
        }
        int ans = 0;
        bool cur = 0;
        int curi = 0;
        for (int i = 0; i < 20001; ++i) {
            if (cur) {
                ans += curi;
                --map[i];
            }
            ans = (map[i]>>1) * (i - 10000) + ans;
            cur = map[i] & 1;
            curi = i - 10000;
        }
        return ans;
    }
};