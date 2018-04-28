class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (!nums[i]) continue;
            nums[i] += nums[i - 1];
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};