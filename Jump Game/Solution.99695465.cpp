class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (i > maxi) {
                return 0;
            }
            maxi = max(i + nums[i], maxi);
        }
        return 1;
    }
};