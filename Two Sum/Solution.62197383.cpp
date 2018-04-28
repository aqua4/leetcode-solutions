class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        pair<int,int> p[n];
        for (int i=0;i<n;i++) p[i]=make_pair(nums[i],i);
        sort(p,p+n);
        for (int i=0;i<n;i++) nums[i]=p[i].first;
        for (int i=0;i<n-1;i++) {
            if (nums[n-1]+nums[i]<target) continue;
            int l = lower_bound(nums.begin()+i+1,nums.end(),target-nums[i])-nums.begin();
            if (nums[l]+nums[i]==target) return {p[i].second,p[l].second};
        }
        return {0,0};
    }
};