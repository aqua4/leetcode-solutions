class Solution {
    int n,m;
    vector<vector<int>> d;
    vector<vector<int>> a;
public:
    void dfs(int i,int j) {
        int top=0,left=0,right=0,bot=0;
        if (i>0 && a[i-1][j]>a[i][j]) {
            if (!d[i-1][j]) dfs(i-1,j);
            top=d[i-1][j];
        }
        if (i<n-1 && a[i+1][j]>a[i][j]) {
            if (!d[i+1][j]) dfs(i+1,j);
            bot=d[i+1][j];
        }
        if (j>0 && a[i][j-1]>a[i][j]) {
            if (!d[i][j-1]) dfs(i,j-1);
            left=d[i][j-1];
        }
        if (j<m-1 && a[i][j+1]>a[i][j]) {
            if (!d[i][j+1]) dfs(i,j+1);
            right=d[i][j+1];
        }
        d[i][j]=max(top,max(bot,max(right,left)))+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        if (!n) return 0;
        m=matrix[0].size();
        if (!m) return 0;
        a=matrix;
        d.resize(n);
        for (int i=0;i<n;i++) d[i].resize(m);
        int ans=0;
        for (int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (!d[i][j]) dfs(i,j);
                ans=max(ans,d[i][j]);
            }    
        }
        return ans;
    }
};