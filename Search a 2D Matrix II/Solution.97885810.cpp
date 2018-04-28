class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (!n) {
            return 0;
        }
        int m = matrix[0].size();
        if (!m) {
            return 0;
        }
        int i = 0;
        int j = m - 1;
        while (i < n && j >= 0) {
            if (matrix[i][j] > target) {
                --j;
                continue;
            }
            if (matrix[i][j] < target) {
                ++i;
                continue;
            }
            return 1;
        }
        return 0;
    }
};