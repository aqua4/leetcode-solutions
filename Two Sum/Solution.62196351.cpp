class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=1;i<nums.size();i++) {
            for (int j=0;j<i;j++)
                if (nums[i]+nums[j]==target) return {j,i};
        }
        return {0,0};
    }
};