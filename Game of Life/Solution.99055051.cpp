class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if (!n) {
            return;
        }
        int m = board[0].size();
        if (!m) {
            return;
        }
        vector<vector<int> > temp = board;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int nei = 0;
                if (i && j && temp[i - 1][j - 1]) {
                    ++nei;
                }
                if (i && temp[i - 1][j]) {
                    ++nei;
                }
                if (i && j < m - 1 && temp[i - 1][j + 1]) {
                    ++nei;
                }
                if (j < m - 1 && temp[i][j + 1]) {
                    ++nei;
                }
                if (i < n - 1 && j < m - 1 && temp[i + 1][j + 1]) {
                    ++nei;
                }
                if (i < n - 1 && temp[i + 1][j]) {
                    ++nei;
                }
                if (i < n - 1 && j && temp[i + 1][j - 1]) {
                    ++nei;
                }
                if (j && temp[i][j - 1]) {
                    ++nei;
                }
                if (!temp[i][j]) {
                    if (nei == 3) {
                        board[i][j] = 1;
                    }
                    continue;
                }
                if (nei > 3 || nei < 2) {
                    board[i][j] = 0;
                }
            }
        }
    }
};