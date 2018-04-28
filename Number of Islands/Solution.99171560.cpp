class Solution {
public:
    void dfs(int i, int j, int& n, int& m, vector<vector<char>>& grid, vector<vector<bool> >& used) {
        used[i][j] = 1;
        if (i + 1 < n && grid[i + 1][j] == '1' && !used[i + 1][j]) {
            dfs(i + 1, j, n, m, grid, used);
        }
        if (i > 0 && grid[i - 1][j] == '1' && !used[i - 1][j]) {
            dfs(i - 1, j, n, m, grid, used);
        }
        if (j + 1 < m && grid[i][j + 1] == '1' && !used[i][j + 1]) {
            dfs(i, j + 1, n, m, grid, used);
        }
        if (j > 0 && grid[i][j - 1] == '1' && !used[i][j - 1]) {
            dfs(i, j - 1, n, m, grid, used);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (!n) {
            return 0;
        }
        int m = grid[0].size();
        if (!m) {
            return 0;
        }
        int ans = 0;
        vector<vector<bool> > used(n, vector<bool>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !used[i][j]) {
                    ++ans;
                    dfs(i, j, n, m, grid, used);
                }
            }
        }
        return ans;
    }
};