class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0,cur=0;
        int len=nums.size();
        for(int i=0;i<len;i++) {
            if (!cur) {
                cur++;
                ans=nums[i];
            } else {
                ans==nums[i] ? cur++ : cur--;
            }
            if (cur>len/2) return ans;
        }
        return ans;
    }
};