class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int,bool> a;
        for(int i=0;i<nums.size();i++) {
            if (a[nums[i]]) return 1;
            a[nums[i]]=1;
        }
        return 0;
    }
};