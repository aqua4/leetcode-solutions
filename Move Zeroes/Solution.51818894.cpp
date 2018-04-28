class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len=nums.size();
        int zero=0,i=0;
        while(i<len) {
            if (nums[zero]) {
                zero++;
                if (i<zero) i++;
            }
            if (!nums[i]) i++; 
            else {
                if (!nums[zero]) swap(nums[i],nums[zero]);
            }
        }
    }
};