class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int val = abs(nums[i]) - 1;
            if (nums[val] < 0) {
                ans.push_back(val + 1);
                continue;
            }
            nums[val] = -nums[val];
        }
        return ans;
    }
};