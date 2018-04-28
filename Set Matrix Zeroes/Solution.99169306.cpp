class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (!n) {
            return;
        }
        int m = matrix[0].size();
        if (!m) {
            return;
        }
        bool zi[n] = {0};
        bool zj[m] = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!matrix[i][j]) {
                    zi[i] = 1;
                    zj[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (zi[i] || zj[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};