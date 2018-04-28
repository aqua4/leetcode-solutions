class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j]) continue;
                ans += 4;
                if (i > 0 && grid[i - 1][j]) ans--;
                if (i < n - 1 && grid[i + 1][j]) ans--;
                if (j > 0 && grid[i][j - 1]) ans--;
                if (j < m - 1 && grid[i][j + 1]) ans--;
            }
        }
        return ans;
    }
};