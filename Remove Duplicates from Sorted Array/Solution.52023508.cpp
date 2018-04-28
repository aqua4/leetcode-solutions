class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int>::iterator it=unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),it));
        return nums.size();
    }
};