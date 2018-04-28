class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> a;
        int p1=0,p2=0;
        for(int i=0;i<n+m;i++) {
            if ((p2<n && nums1[p1]>nums2[p2]) || p1>=m) {
                a.push_back(nums2[p2]);
                p2++;
            } else {
                a.push_back(nums1[p1]);
                p1++;
            }
        }
        nums1=a;
        //for(int i=0;i<n+m;i++) nums1[i]=a[i];
    }
};