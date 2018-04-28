class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if (!n) return 1;
        int m = board[0].size();
        vector<vector<bool>> sq(11,vector<bool> (11,0));
        for (int i=0;i<n;i++) {
            vector<bool> row(11,0),col(11,0);
            for (int j=0;j<m;j++) {
                if (board[i][j]!='.') {
                    int ch = board[i][j]-48;
                    if (row[ch] || sq[i/3+j/3*3][ch]) {cout<<sq[i/3+j/3*3][ch];return 0;}
                    row[ch]=1;
                    sq[i/3+j/3*3][ch]=1;
                }
                if (board[j][i]!='.') {
                    if (col[board[j][i]-48]) return 0;
                    col[board[j][i]-48]=1;
                }
            }
        }
        return 1;
    }
};