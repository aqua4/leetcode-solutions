class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k%=n;
        vector<int> v1(nums.end()-k,nums.end());
        v1.insert(v1.end(),nums.begin(),nums.end()-k);
        nums = v1;
    }
};