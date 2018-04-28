class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        if (!n) return 0;
        int m=matrix[0].size();
        if (!m) return 0;
        int l=0,r=n-1,mid;
        while (l<=r) {
            mid=(l+r)/2;
            if (matrix[mid][0]==target) return 1;
            if (matrix[mid][0]<target) l=mid+1; else r=mid-1;
        }
        mid=min(mid,n-1);
        if (matrix[mid][0]>target) mid--;
        if (mid<0) return 0;
        int p1=mid;
        l=0;
        r=m-1;
        while (l<=r) {
            mid=(l+r)/2;
            if (matrix[0][mid]==target) return 1;
            if (matrix[0][mid]<target) l=mid+1; else r=mid-1;
        }
        mid=min(mid,m-1);
         if (matrix[0][mid]>target) mid--;
         if (p1<mid) {
             for(int i=0;i<=p1;i++) {
                 l=0;
                 r=m-1;
                 while (l<=r) {
                     mid=(l+r)/2;
                     if (matrix[i][mid]==target) return 1;
                     if (matrix[i][mid]<target) l=mid+1; else r=mid-1;
                 }
             }
         } else {
             p1=mid;
             for(int i=0;i<=p1;i++) {
                 l=1;
                 r=n-1;
                 while (l<=r) {
                     mid=(l+r)/2;
                     if (matrix[mid][i]==target) return 1;
                     if (matrix[mid][i]<target) l=mid+1; else r=mid-1;
                 }
             }
         }
         return 0;
    }
};