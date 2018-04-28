class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int m1[n] = {0};
        int m2[n];
        m1[1]=nums[0];
        m2[n-1]=0;
        m2[n-2]=nums[n-1];
        for (int i=2;i<n;i++) {
            m1[i] = nums[i-1]*m1[i-1];
        }
        for (int i=n-3;i>=0;i--) {
            m2[i] = nums[i+1]*m2[i+1];
        }
        vector<int> out(n);
        out[0] = m2[0];
        out[n-1] = m1[n-1];
        for (int i=1;i<n-1;i++) {
            out[i]=m1[i]*m2[i];
        }
        return out;
    }
};