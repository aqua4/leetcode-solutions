class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len=heights.size();
        if (!len) return 0;
        int ma=0;
        vector<int> prev(len,-1),next(len,len);
        for (int i=0;i<len;i++) {
            int p=i-1;
            while (p!=-1 && heights[p]>=heights[i]) p=prev[p];
            prev[i]=p;
        }
        for (int i=len-1;i>=0;i--) {
            int p=i+1;
            while (p!=len && heights[p]>=heights[i]) p=next[p];
            next[i]=p;
            ma=max(ma,(next[i]-prev[i]-1)*heights[i]);
            //cout<<ma<<" ";
        }
        //for (int i=0;i<len;i++) cout<<prev[i]<<" "<<next[i]<<endl;
        return ma;
    }
};