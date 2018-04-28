class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        if (!len) return 0;
        int last=len-1;
        while (nums[last]==val) last--;
        for (int i=0;i<last;i++) {
            if (nums[i]==val) {
                swap(nums[i],nums[last]);
            }    
            while (nums[last]==val) last--;
        }
        return last+1;
    }
};