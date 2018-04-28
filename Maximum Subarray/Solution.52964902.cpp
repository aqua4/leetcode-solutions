class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) return 0;
        int s=0,mi=0,ans=nums[0];
        for(int i=0;i<nums.size();i++) {
            s+=nums[i];
            ans=max(ans,s-mi);
            mi=min(mi,s);
        }
        return ans;
    }
};