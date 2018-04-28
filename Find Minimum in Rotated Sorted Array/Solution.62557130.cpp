class Solution {
public:
    int findMin(vector<int>& nums) {
        int mi = INT_MAX;
        for (int i=0;i<nums.size();i++) mi = min(mi,nums[i]);
        return mi;
    }
};