class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(),nums1.end());
        vector<int> ans;
        for (int n : nums2) {
            if (s.count(n)) {
                ans.push_back(n);
                s.erase(n);
            }
        }
        return ans;
    }
};