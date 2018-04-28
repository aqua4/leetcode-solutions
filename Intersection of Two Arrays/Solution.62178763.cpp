class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int p2 = 0;
        vector<int> ans;
        for (int i=0;i<len1 && p2<len2;) {
            while (nums1[i]<nums2[p2] && i<len1) i++;
            while (nums2[p2]<nums1[i] && p2<len2) p2++;
            if (nums1[i]==nums2[p2]) {
                ans.push_back(nums1[i]);
                while (nums1[i]==ans.back() && i<len1) i++;
                while (nums2[p2]==ans.back() && p2<len2) p2++;
            }
        }
        return ans;
    }
};