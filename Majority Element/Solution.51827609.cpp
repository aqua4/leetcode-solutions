class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> a;
        int len=nums.size();
        for(int i=0;i<len;i++) {
            a[nums[i]]++;
            if (a[nums[i]]>len/2) return nums[i];
        }
    }
};