class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;
        for (int n : nums1) m[n]++;
        for (int n : nums2) {
            if (m[n]) {
                ans.push_back(n);
                m[n]--;
            }    
        }
        return ans;
    }
};